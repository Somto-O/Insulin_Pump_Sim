#ifndef USER_H
#define USER_H

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

    // functions
    void navigateProfiles();
    void startInsulinDelivery();
    void stopInsulinDelivery();
    void deliverManualBolus();
    void viewDeliveryData();
    void viewPumpStatus();
    void setAlerts();
};

#endif // USER_H
