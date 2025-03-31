#include "user.h"
#include "profile.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

// constructor
User::User(MainWindow* mw) :mainWindow(mw) {
    {
        // Connect buttons from the UI to User functions
        connect(mainWindow->getUI()->addProfileButton, &QPushButton::clicked, this, &User::handleCreateProfile);
        connect(mainWindow->getUI()->viewProfilesButton, &QPushButton::clicked, this, &User::handleViewProfile);
        connect(mainWindow->getUI()->updateProfileButton, &QPushButton::clicked, this, &User::handleUpdateProfile);
        connect(mainWindow->getUI()->deleteProfileButton, &QPushButton::clicked, this, &User::handleDeleteProfile);
    }
}

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
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender()); // Get the button that triggered this function

    if (!senderButton) return; // Safety check

    if (senderButton == mainWindow->getUI()->addProfileButton)
    {
        handleCreateProfile();
    }
    else if (senderButton == mainWindow->getUI()->viewProfilesButton)
    {
        handleViewProfile();
    }
    else if (senderButton == mainWindow->getUI()->updateProfileButton)
    {
        handleUpdateProfile();

    }
    else if (senderButton == mainWindow->getUI()->deleteProfileButton)
    {
        handleDeleteProfile();
    }
}


void User::handleCreateProfile()
{
    Profile::createProfile(mainWindow);
}

void User::handleViewProfile()
{
    Profile::viewProfile();
}

void User::handleUpdateProfile() {
    Profile::updateProfile(mainWindow);
}


void User::handleDeleteProfile()
{
    Profile::deleteProfile();
}
