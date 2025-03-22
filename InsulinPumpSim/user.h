#ifndef USER_H
#define USER_H

#include <vector>

#include <QString>
#include <QInputDialog>
#include <QMessageBox>

#include "profile.h"

using namespace std;

class User
{
public:
    // constructor
    User();

    // destructor
    ~User();

    // getters
    std::vector<Profile*>& GetProfiles();

    // functions
    void createProfile();
    void navigateProfiles();
    void startInsulinDelivery();
    void stopInsulinDelivery();
    void deliverManualBolus();
    void viewDeliveryData();
    void viewPumpStatus();
    void setAlerts();

private:
    std::vector<Profile*> profiles;
};

#endif // USER_H
