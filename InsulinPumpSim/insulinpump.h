#ifndef INSULINPUMP_H
#define INSULINPUMP_H

#include <string>
using namespace std;

class InsulinPump
{
public:
    InsulinPump();
    void startDelivery();
    void stopDelivery();
    void viewStatus();

private:
    string status;
    float batteryLevel;

};

#endif // INSULINPUMP_H
