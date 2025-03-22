#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <limits>

#include "profile.h"

using namespace std;

class User
{
public:
    User();
    void createProfile();
    void navigateProfiles();
    void startInsulinDelivery();
    void stopInsulinDelivery();
    void deliverManualBolus();
    void viewDeliveryData();
    void viewPumpStatus();
    void setAlerts();

    // helper function (test)
    vector<Profile*>& GetProfiles();

private:
    vector<Profile*> profiles; // contains all the profiles
};

#endif // USER_H
