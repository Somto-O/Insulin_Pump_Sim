#include "user.h"

// constructor
User::User() {}

// destructor
User::~User()
{
    for (Profile* profile : Profile::getProfiles())
    {
        delete profile;
    }

    Profile::getProfiles().clear();
}

// functions
void User::navigateProfiles()
{
    QStringList options = {"Create Profile", "View Profile", "Update Profile", "Delete Profile"};
    bool ok;
    QString choice = QInputDialog::getItem(nullptr, "Profile Options", "Select an option:", options, 0, false, &ok);

    if (!ok || choice.isEmpty()) return;

    if (choice == "Create Profile")
    {
        Profile::createProfile();
    }
    else if (choice == "View Profile")
    {
         Profile::viewProfile();
    }
    else if (choice == "Update Profile")
    {
         Profile::updateProfile();
    }
    else if (choice == "Delete Profile")
    {
         Profile::deleteProfile();
    }
}
