#include "profile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

// static variables
vector<Profile*> Profile::profiles;

// constructor
Profile::Profile(MainWindow* mw,string n, float bRate, float carbRatio,float cFactor):
    name(n),
    basalRate(bRate),
    carbohydrateRatio(carbRatio),
    correctionFactor(cFactor),
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

    // Create new Profile object with the gathered data
    Profile* profile = new Profile(mw, name.toStdString(), basalRate, carbRatio, correctionFactor);

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
                     << ", Correction Factor:" << p->getCorrectionFactor();
}
}



//void Profile::updateProfile(MainWindow* mw) {
//    //QString selectedProfile = mw->onProfileSelected();
//    displayProfiles(mw);
//    QString selectedProfile = mw->getSelectedProfileName();



//    // Find the existing profile in the vector
//    Profile* selectedProfilePtr = nullptr;
//    for (Profile* profile : profiles) {
//        if (profile->getName() == selectedProfile.toStdString()) {
//            selectedProfilePtr = profile;
//            break;
//        }
//    }

//    // If no profile was found, show an error
//    if (!selectedProfilePtr) {
//        QMessageBox::warning(mw, "Update Profile", "Profile not found.");
//        return;
//    }

//    // Populate the fields in the Update Profile page with the current profile values
//    mw->getUI()->basalInput->setValue(selectedProfilePtr->getBasalRate());
//    mw->getUI()->carbRatioInput->setValue(selectedProfilePtr->getCarbRatio());
//    mw->getUI()->correctionFactorInput->setValue(selectedProfilePtr->getCorrectionFactor());

//    // User manually enters new values in the updateProfilePage
//    float basalRate = mw->getUI()->basalInput->value();
//    float carbRatio = mw->getUI()->carbRatioInput->value();
//    float correctionFactor = mw->getUI()->correctionFactorInput->value();

//    // Validate new values
//    if (basalRate < 0 || carbRatio < 0 || correctionFactor < 0) {
//        QMessageBox::warning(mw, "Error", "Invalid input. Please enter positive values.");
//        return;
//    }

//    // Update the profile with new values
//    selectedProfilePtr->setBasalRate(basalRate);
//    selectedProfilePtr->setCarbRatio(carbRatio);
//    selectedProfilePtr->setCorrectionFactor(correctionFactor);

//    // Save the updated profile
//    saveProfiles();

//    // Inform the user that the profile has been updated successfully
//    QMessageBox::information(mw, "Success", "Profile updated successfully!");

//    // After updating the profile, refresh the displayed profiles in the list
//    mw->getUI()->spDisplayBox->clear();  // Clear previous content

//}

void Profile::updateProfile(MainWindow* mw) {
    // Get the selected item from the list
    displayProfiles(mw);
    QListWidgetItem* selectedItem = mw->getUI()->spDisplayBox->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(mw, "Selection Error", "No profile selected. Please select a profile first.");
        return;
    }

    QString selectedProfileName = selectedItem->text();

    // Find the corresponding profile object
    Profile* selectedProfile = nullptr;
    for (Profile* profile : profiles) {
        if (profile->getName() == selectedProfileName.toStdString()) {
            selectedProfile = profile;
            break;
        }
    }

    if (!selectedProfile) {
        QMessageBox::warning(mw, "Error", "Selected profile not found.");
        return;
    }

    // Get updated values from UI fields
    float basalRate = mw->getUI()->basalInput->value();
    float carbRatio = mw->getUI()->carbRatioInput->value();
    float correctionFactor = mw->getUI()->correctionFactorInput->value();

    // Validate values
    if (basalRate < 0 || carbRatio < 0 || correctionFactor < 0) {
        QMessageBox::warning(mw, "Error", "Invalid input. Please enter positive values.");
        return;
    }

    // Apply updates to the selected profile
    selectedProfile->setBasalRate(basalRate);
    selectedProfile->setCarbRatio(carbRatio);
    selectedProfile->setCorrectionFactor(correctionFactor);

    // Save updated profile
    saveProfiles();

    // Inform the user
    QMessageBox::information(mw, "Success", "Profile updated successfully!");
}



void Profile::deleteProfile() {
    if (profiles.empty()) {
        QMessageBox::warning(nullptr, "Delete Profile", "No profiles available to delete.");
        return;
    }

    QStringList profileNames;
    for (Profile* profile : profiles) {
        profileNames.append(QString::fromStdString(profile->getName()));
    }

    bool ok;
    QString selectedProfile = QInputDialog::getItem(nullptr, "Delete Profile", "Select a profile to delete:", profileNames, 0, false, &ok);
    if (!ok || selectedProfile.isEmpty()) return;

    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        if ((*it)->getName() == selectedProfile.toStdString()) {
            delete *it; // Free memory
            profiles.erase(it);
            saveProfiles(); // update profiles after deletion
            QMessageBox::information(nullptr, "Success", "Profile deleted successfully!");
            return;
        }
    }
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
            QString profileInfo = QString("Name: %1\nBasal Rate: %2\nCarb Ratio: %3\nCorrection Factor: %4")
                                      .arg(QString::fromStdString(profile->getName()))
                                      .arg(profile->basalRate)
                                      .arg(profile->carbohydrateRatio)
                                      .arg(profile->correctionFactor);

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
             << profile->carbohydrateRatio << endl;
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
    float bRate, carbRatio, cFactor;

    while (file >> name >> bRate >> cFactor >> carbRatio) {
        if (!name.empty() && bRate > 0 && carbRatio > 0 && cFactor > 0) {
            profiles.push_back(new Profile(mw, name, bRate, carbRatio, cFactor));
        }
    }

    file.close();
}


void Profile::displayProfiles(MainWindow* mw) {
    QSet<QString> existingItems;

    // Store existing items to avoid duplicates
    for (int i = 0; i < mw->getUI()->spDisplayBox->count(); ++i) {
        existingItems.insert(mw->getUI()->spDisplayBox->item(i)->text());
    }

    // Add only new profiles (no clearing)
    for (Profile* profile : profiles) {
        QString profileName = QString::fromStdString(profile->getName());

        if (!existingItems.contains(profileName)) {
            QListWidgetItem* item = new QListWidgetItem(profileName);
            mw->getUI()->spDisplayBox->addItem(item);
        }
    }
}





