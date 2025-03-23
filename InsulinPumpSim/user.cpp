#include "user.h"

// constructor
User::User() {}

// destructor
User::~User()
{
    for (Profile* profile : Profile::GetProfiles())
    {
        delete profile;
    }

    Profile::GetProfiles().clear();
}

// functions
void User::navigateProfiles()
{
    QStringList options = {"Create Profile", "Read Profile", "Update Profile", "Delete Profile"};
    bool ok;
    QString choice = QInputDialog::getItem(nullptr, "Profile Options", "Select an option:", options, 0, false, &ok);

    if (!ok || choice.isEmpty()) return;

    if (choice == "Create Profile")
    {
        Profile::createProfile();
    }
    else if (choice == "Read Profile")
    {
        QMessageBox::information(nullptr, "Read Profile", "not implemented yet.");
    }
    else if (choice == "Update Profile")
    {
        QMessageBox::information(nullptr, "Update Profile", "not implemented yet.");
    }
    else if (choice == "Delete Profile")
    {
        QMessageBox::information(nullptr, "Delete Profile", "not implemented yet.");
    }
}
