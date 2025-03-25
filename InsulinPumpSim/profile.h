#ifndef PROFILE_H
#define PROFILE_H

#include<iostream>
#include <vector>
#include <fstream>

#include <QString>
#include <QInputDialog>
#include <QMessageBox>

using namespace std;

class Profile {

public:
    // constructor
    Profile(string n, float bRate, float carbRatio,float cFactor);

    // destructor
    ~Profile();

    // getters
    string getName() const;
    static vector<Profile*>& getProfiles();

    // functions
    static void createProfile();
    static void updateProfile();
    static void deleteProfile();
    static void viewProfile();

    static void saveProfiles();
    static void loadProfiles();

private:
    // variables
    string name;
    float basalRate;
    float carbohydrateRatio;
    float correctionFactor;

    // static variables
    static vector<Profile*> profiles;
};

#endif // PROFILE_H
