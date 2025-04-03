#include "profile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

// static variables
vector<Profile*> Profile::profiles;

// constructor
Profile::Profile(MainWindow* mw,string n, float bRate, float carbRatio,float cFactor, float targetbg):
    name(n),
    basalRate(bRate),
    carbohydrateRatio(carbRatio),
    correctionFactor(cFactor),
    targetBG(targetbg),
    mainWindow(mw)
{}

// destructor
Profile::~Profile()
{}

// getters
string Profile::getName() const {
    return name;
}

vector<Profile*>& Profile::getProfiles() {
    return profiles;
}

// functions
void Profile::createProfile(MainWindow* mw)
{
    // Retrieve values from the UI fields (these values have already been validated)
    QString name = mw->getUI()->nameInput->text();
    float basalRate = mw->getUI()->basalInput->value();
    float carbRatio = mw->getUI()->carbRatioInput->value();
    float correctionFactor = mw->getUI()->correctionFactorInput->value();
    float targetbg = mw->getUI()->targetBGInput->value();

    // Create new Profile object with the gathered data
    Profile* profile = new Profile(mw, name.toStdString(), basalRate, carbRatio, correctionFactor,targetbg);

    // Add the profile to the profiles list
    if(profile->getName() != "" ){
    profiles.push_back(profile);
    }


    // Optionally, you can print the entire profiles vector
        qDebug() << "Profiles in Vector:";
        for (Profile* p : profiles) {
            qDebug() << "Name:" << QString::fromStdString(p->getName())
                     << ", Basal Rate:" << p->getBasalRate()
                     << ", Carb Ratio:" << p->getCarbRatio()
                     << ", Correction Factor:" << p->getCorrectionFactor()
                     << ", Target BG: " << p->getTargetBG();
}
}




void Profile::updateProfile(MainWindow* mw, const QString& profileName) {
    qDebug() << "DEBUG: Attempting to update profile: " << profileName;

    // Find the profile in the list
    Profile* selectedProfilePtr = nullptr;
    for (Profile* profile : profiles) {
        if (profile->getName() == profileName.toStdString()) {
            selectedProfilePtr = profile;
            break;
        }
    }

    if (!selectedProfilePtr) {
        QMessageBox::warning(mw, "Update Profile", "Profile not found.");
        qDebug() << "ERROR: Profile not found!";
        return;
    }

    // Retrieve user-entered values from the input fields
    float basalRate = mw->getUI()->uppBasalInput->value();
    float carbRatio = mw->getUI()->uppCarbRatioInput->value();
    float correctionFactor = mw->getUI()->uppCorrectionFactorInput->value();
    float targetbg = mw->getUI()->uppTargetBGInput->value();

    // Debug: Print user-entered values
//    qDebug() << "DEBUG: Retrieved values - Basal Rate: " << basalRate
//             << ", Carb Ratio: " << carbRatio
//             << ", Correction Factor: " << correctionFactor;

    // Validate input
    if (basalRate < 0 || carbRatio < 0 || correctionFactor < 0 || targetbg < 0) {
        QMessageBox::warning(mw, "Error", "Invalid input. Enter positive values.");
        return;
    }

    // Debug: Print current profile values before updating
//    qDebug() << "DEBUG: Current profile values - Basal Rate: "
//             << selectedProfilePtr->getBasalRate()
//             << ", Carb Ratio: " << selectedProfilePtr->getCarbRatio()
//             << ", Correction Factor: " << selectedProfilePtr->getCorrectionFactor();

    // Update profile attributes
    selectedProfilePtr->setBasalRate(basalRate);
    selectedProfilePtr->setCarbRatio(carbRatio);
    selectedProfilePtr->setCorrectionFactor(correctionFactor);
    selectedProfilePtr->setTargetBG(targetbg);

    // Debug: Print profile values after updating
//    qDebug() << "DEBUG: Updated profile values - Basal Rate: "
//             << selectedProfilePtr->getBasalRate()
//             << ", Carb Ratio: " << selectedProfilePtr->getCarbRatio()
//             << ", Correction Factor: " << selectedProfilePtr->getCorrectionFactor();

    // Save updated profile data
    saveProfiles();

    qDebug() << "DEBUG: Profile updated successfully!";

    // Show confirmation message
    QMessageBox::information(mw, "Success", "Profile updated successfully!");
}


void Profile::deleteProfile(MainWindow* mw, const QString& profileName) {
    qDebug() << "DEBUG: Attempting to delete profile: " << profileName;

    if (profiles.empty()) {
        QMessageBox::warning(mw, "Delete Profile", "No profiles available to delete.");
        return;
    }

    // Find the profile in the list
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        if ((*it)->getName() == profileName.toStdString()) {
            delete *it;  // Free memory
            profiles.erase(it);
            saveProfiles();  // Save updated profiles after deletion

            qDebug() << "DEBUG: Profile deleted successfully!";
            QMessageBox::information(mw, "Success", "Profile deleted successfully!");
            return;
        }
    }

    // If profile not found
    QMessageBox::warning(mw, "Delete Profile", "Profile not found.");
    qDebug() << "ERROR: Profile not found!";
}


void Profile::viewProfile() {
    if (profiles.empty()) {
        QMessageBox::warning(nullptr, "View Profile", "No profiles available to view.");
        return;
    }

    QStringList profileNames;
    for (Profile* profile : profiles) {
        profileNames.append(QString::fromStdString(profile->getName()));
    }

    bool ok;
    QString selectedProfile = QInputDialog::getItem(nullptr, "View Profile", "Select a profile to view:", profileNames, 0, false, &ok);
    if (!ok || selectedProfile.isEmpty()) return;

    for (Profile* profile : profiles) {
        if (profile->getName() == selectedProfile.toStdString()) {
            QString profileInfo = QString("Name: %1\nBasal Rate: %2\nCarb Ratio: %3\nCorrection Factor: %4\nTarget BG: %5")
                                      .arg(QString::fromStdString(profile->getName()))
                                      .arg(profile->basalRate)
                                      .arg(profile->carbohydrateRatio)
                                      .arg(profile->correctionFactor)
                                      .arg(profile->targetBG);

            QMessageBox::information(nullptr, "Profile Details", profileInfo);
            return;
        }
    }
}

void Profile::saveProfiles()
{
    ofstream file("profiles.txt");

    if(!file) {
        QMessageBox::warning(nullptr, "Error", "Could not open save file.");
        return;
    }

    for(Profile* profile : profiles)
    {
        file << profile->name << " "
             << profile->basalRate << " "
             << profile-> correctionFactor << " "
             << profile->carbohydrateRatio << " "
             << profile->targetBG << endl;
    }


    file.close();


}


void Profile::loadProfiles(MainWindow* mw)
{
    ifstream file("profiles.txt");

    if (!file) {
        QMessageBox::warning(mw, "Error", "Could not open file to load profiles!");
        return;
    }

    profiles.clear();

    string name;
    float bRate, carbRatio, cFactor, targetbg;

    while (file >> name >> bRate >> cFactor >> carbRatio >> targetbg) {
        if (!name.empty() && bRate >= 0 && carbRatio >= 0 && cFactor >= 0 && targetbg >=0) {
            profiles.push_back(new Profile(mw, name, bRate, carbRatio, cFactor, targetbg));
        }
    }

    file.close();
}






