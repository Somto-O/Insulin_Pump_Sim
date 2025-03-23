#include "mainwindow.h"
#include "user.h"
#include "profile.h"

#include <iostream>
#include <string>

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    User user;

    // when option button is pressed, it calls navigate profiles
    user.navigateProfiles();

    vector<Profile*>& profiles = Profile::GetProfiles();

    if (!profiles.empty()) {
        Profile* profile = profiles[0];
        cout << "Name: " << profile->GetName() << endl;
    } else {
        cout << "No profiles found!" << endl;
    }

    return a.exec();
}
