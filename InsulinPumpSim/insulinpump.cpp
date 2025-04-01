#include "insulinpump.h"

InsulinPump::InsulinPump():
    status("Idle"), batteryLevel(100.0f)
{

}

// functions
void InsulinPump::startDelivery()
{
    if (batteryLevel > 0) {
        status = "Delivering insulin";
        std::cout << "Insulin pump is " << status << "..." << std::endl;
    } else {
        std::cout << "Battery is too low to start delivery." << std::endl;
    }
}

void InsulinPump::stopDelivery()
{
    status = "Idle";
    std::cout << "Insulin pump has stopped delivering insulin." << std::endl;
}

void InsulinPump::viewStatus()
{
    std::cout << "Pump Status: " << status << std::endl;
    std::cout << "Battery Level: " << batteryLevel << "%" << std::endl;
}
