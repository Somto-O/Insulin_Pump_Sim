#include "mainwindow.h"
#include "user.h"
#include "profile.h"

#include <iostream>

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Load saved profiles after the UI is ready
    Profile::loadProfiles(&w);

    // Create User object
    User user(&w);

    // The profiles will be managed through button clicks and navigation
    // You don't need to call navigateProfiles here

//    vector<Profile*>& profiles = Profile::getProfiles();

//    if (!profiles.empty()) {
//        Profile* profile = profiles[0];
//        cout << "Name: " << profile->getName() << endl;
//    } else {
//        cout << "No profiles found!" << endl;
//    }

    return a.exec();
}
