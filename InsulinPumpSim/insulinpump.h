#ifndef INSULINPUMP_H
#define INSULINPUMP_H

#include <iostream>
#include <string>

using namespace std;

class InsulinPump
{
public:
    // constructor
    InsulinPump();

    // functions
    void startDelivery();
    void stopDelivery();
    void viewStatus();

private:
    string status;
    float batteryLevel;
};

#endif // INSULINPUMP_H
