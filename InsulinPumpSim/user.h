#ifndef USER_H
#define USER_H


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
};

#endif // USER_H
