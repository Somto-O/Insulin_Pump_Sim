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

    // load saved profiles
    Profile::loadProfiles();

    User user;

    // when option button is pressed, it calls navigate profiles
    user.navigateProfiles();

    vector<Profile*>& profiles = Profile::getProfiles();

    if (!profiles.empty()) {
        Profile* profile = profiles[0];
        cout << "Name: " << profile->getName() << endl;
    } else {
        cout << "No profiles found!" << endl;
    }

    return a.exec();
}
