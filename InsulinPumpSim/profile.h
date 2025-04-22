#ifndef PROFILE_H
#define PROFILE_H

#include<iostream>
#include <vector>
#include <fstream>

#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "history.h"


using namespace std;

class Profile {

public:
    // constructor
    Profile(MainWindow* mw, string n, float bRate, float carbRatio,float cFactor, float targetbg);

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
    void setTargetBG(float newTargetBG){targetBG = newTargetBG;}

    static vector<Profile*>& getProfiles();



    // functions
    static void createProfile(MainWindow* mw);
    static void updateProfile(MainWindow* mw, const QString& profileName);
    static void deleteProfile(MainWindow* mw, const QString& profileName);
    static void viewProfile(MainWindow* mw, const QString& profileName);
    static void displayProfiles(MainWindow* mw);
    static void activateProfile(MainWindow* mw, const QString& profileName);
    static void saveProfiles();
    static void loadProfiles(MainWindow* mw);

    static void setActiveBasalRate(float rate);
    static void setActiveCarbRatio(float ratio);
    static void setActiveCorrectionFactor(float factor);
    static void setActiveTargetBG(float target);
    static void setActiveProfileName(const QString& name);

    static float getActiveBasalRate();
    static float getActiveCarbRatio();
    static float getActiveCorrectionFactor();
    static float getActiveTargetBG();
    static QString getActiveProfileName();



private:
    // per-profile data
    string name;
    float basalRate;
    float carbohydrateRatio;
    float correctionFactor;
    float targetBG;
    MainWindow* mainWindow;

    // shared active profile values
    static float activeBasalRate;
    static float activeCarbRatio;
    static float activeCorrectionFactor;
    static float activeTargetBG;
    static QString activeProfileName;

    static vector<Profile*> profiles;


};

#endif // PROFILE_H
