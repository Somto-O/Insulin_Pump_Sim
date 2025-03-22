#include "user.h"

// constructor
User::User() {}

// destructor
User::~User()
{
    for(Profile* profile : profiles)
    {
        delete profile;
    }

    profiles.clear();
}

// getters
vector<Profile*>& User::GetProfiles()
{
    return profiles;
}

// functions
void User::createProfile()
{
    bool ok;
    QString name = QInputDialog::getText(nullptr, "Create Profile", "Enter your name:", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    float basalRate = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your basal rate:", 0.0, 0.0, 10.0, 2, &ok);
    if (!ok) return;

    float carbRatio = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your carb ratio:", 0.0, 0.0, 20.0, 2, &ok);
    if (!ok) return;

    float correctionFactor = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your correction factor:", 0.0, 0.0, 10.0, 2, &ok);
    if (!ok) return;

    Profile* profile = new Profile(name.toStdString(), basalRate, carbRatio, correctionFactor);
    profiles.push_back(profile);

    QMessageBox::information(nullptr, "Success", "Profile created successfully!");
}

void User::navigateProfiles()
{
    QStringList options = {"Create Profile", "Read Profile", "Update Profile", "Delete Profile"};
    bool ok;
    QString choice = QInputDialog::getItem(nullptr, "Profile Options", "Select an option:", options, 0, false, &ok);

    if (!ok || choice.isEmpty()) return;

    if (choice == "Create Profile")
    {
        createProfile();
    }
    else if (choice == "Read Profile")
    {
        QMessageBox::information(nullptr, "Read Profile", "Feature not implemented yet.");
    }
    else if (choice == "Update Profile")
    {
        QMessageBox::information(nullptr, "Update Profile", "Feature not implemented yet.");
    }
    else if (choice == "Delete Profile")
    {
        QMessageBox::information(nullptr, "Delete Profile", "Feature not implemented yet.");
    }
}
