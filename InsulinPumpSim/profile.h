#ifndef PROFILE_H
#define PROFILE_H

#include<iostream>
#include <vector>
#include <fstream>

#include <QString>
#include <QInputDialog>
#include <QMessageBox>

#include "mainwindow.h"

using namespace std;

class Profile {

public:
    // constructor
    Profile(MainWindow* mw, string n, float bRate, float carbRatio,float cFactor);

    // destructor
    ~Profile();

    // getters
    string getName() const;
    float getBasalRate(){return basalRate;}
    float getCarbRatio(){return carbohydrateRatio;}
    float getCorrectionFactor(){return correctionFactor;}
    float getTargetBG(){return targetBG;}

    // setters
    string setName() const;
    void setName(const string& newName) { name = newName; }
    void setBasalRate(float newBasalRate) { basalRate = newBasalRate; }
    void setCarbRatio(float newCarbRatio) { carbohydrateRatio = newCarbRatio; }
    void setCorrectionFactor(float newCorrectionFactor) { correctionFactor = newCorrectionFactor;}
    float setTargetBG(){return targetBG;}

    static vector<Profile*>& getProfiles();



    // functions
    static void createProfile(MainWindow* mw);
    static void updateProfile(MainWindow* mw);
    static void deleteProfile();
    static void viewProfile();
    static void displayProfiles(MainWindow* mw);

    static void saveProfiles();
    static void loadProfiles(MainWindow* mw);

private:
    // variables
    string name;
    float basalRate;
    float carbohydrateRatio;
    float correctionFactor;
    float targetBG;
    MainWindow* mainWindow;

    // static variables
    static vector<Profile*> profiles;
};

#endif // PROFILE_H
