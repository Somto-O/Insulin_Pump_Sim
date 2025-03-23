#ifndef PROFILE_H
#define PROFILE_H

#include<iostream>
#include <vector>

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
    string GetName();
    static vector<Profile*>& GetProfiles();

    // functions
    static void createProfile();
    void updateProfile();
    void deleteProfile();
    void viewProfile();

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
