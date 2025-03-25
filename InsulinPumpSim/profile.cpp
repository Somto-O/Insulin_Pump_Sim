#include "profile.h"

// static variables
vector<Profile*> Profile::profiles;

// constructor
Profile::Profile(string n, float bRate, float carbRatio,float cFactor):
    name(n),
    basalRate(bRate),
    carbohydrateRatio(carbRatio),
    correctionFactor(cFactor)
{

}

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
void Profile::createProfile()
{
    bool ok;
    QString n = QInputDialog::getText(nullptr, "Create Profile", "Enter your name:", QLineEdit::Normal, "", &ok);
    if (!ok || n.isEmpty()) return;

    float bRate = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your basal rate:", 0.0, 0.0, 10.0, 2, &ok);
    if (!ok) return;

    float carbRatio = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your carb ratio:", 0.0, 0.0, 20.0, 2, &ok);
    if (!ok) return;

    float cFactor = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your correction factor:", 0.0, 0.0, 10.0, 2, &ok);
    if (!ok) return;

    Profile* profile = new Profile(n.toStdString(), bRate, carbRatio, cFactor);
    profiles.push_back(profile);

    // save profiles to file
    saveProfiles();

    QMessageBox::information(nullptr, "Success", "Profile created successfully!");
}

void Profile::updateProfile() {
    if (profiles.empty()) {
        QMessageBox::warning(nullptr, "Update Profile", "No profiles available to update.");
        return;
    }

    QStringList profileNames;
    for (Profile* profile : profiles) {
        profileNames.append(QString::fromStdString(profile->getName()));
    }

    bool ok;
    QString selectedProfile = QInputDialog::getItem(nullptr, "Update Profile", "Select a profile:", profileNames, 0, false, &ok);
    if (!ok || selectedProfile.isEmpty()) return;

    // Find the selected profile
    for (Profile* profile : profiles) {
        if (profile->getName() == selectedProfile.toStdString()) {
            profile->basalRate = QInputDialog::getDouble(nullptr, "Update Profile", "Enter new basal rate:", profile->basalRate, 0.0, 10.0, 2, &ok);
            if (!ok) return;

            profile->carbohydrateRatio = QInputDialog::getDouble(nullptr, "Update Profile", "Enter new carb ratio:", profile->carbohydrateRatio, 0.0, 20.0, 2, &ok);
            if (!ok) return;

            profile->correctionFactor = QInputDialog::getDouble(nullptr, "Update Profile", "Enter new correction factor:", profile->correctionFactor, 0.0, 10.0, 2, &ok);
            if (!ok) return;

            QMessageBox::information(nullptr, "Success", "Profile updated successfully!");
            return;
        }
    }
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
             << profile->carbohydrateRatio << " "
             << profile->correctionFactor << endl;
    }

    file.close();
}

void Profile::loadProfiles()
{
    ifstream file("profiles.txt");

    if(!file) {
        QMessageBox::warning(nullptr, "Error", "Could not open file to load profiles!");
        return;
    }

    profiles.clear();

    string name;
    float bRate, carbRatio, cFactor;

    while (file >> name >> bRate >> carbRatio >> cFactor) {
        profiles.push_back(new Profile(name, bRate, carbRatio, cFactor));
    }

    file.close();
}




