#include "insulinpump.h"
#include "systemalerts.h"
#include "mainwindow.h"
#include <QTimer>


InsulinPump::InsulinPump() : status("Idle"), batteryLevel(100.0f){

    batteryTimer = new QTimer(this);
    connect(batteryTimer, &QTimer::timeout, this, &InsulinPump::drainBattery);
    batteryTimer->start(2000);  // Reduce battery every 2 seconds
}

// functions
void InsulinPump::startDelivery() {
    if (batteryLevel > 0) {
        status = "Delivering insulin";
        std::cout << "Insulin pump is " << status.toStdString() << "..." << std::endl;
    } else {
        SystemAlerts::escalateAlert("Battery too low! Unable to deliver insulin.");
    }
}

void InsulinPump::stopDelivery()
{
    status = "Idle";
    std::cout << "Insulin pump has stopped delivering insulin." << std::endl;
}

void InsulinPump::viewStatus()
{
    std::cout << "Pump Status: " << status.toStdString() << std::endl;
    std::cout << "Battery Level: " << batteryLevel << "%" << std::endl;
}


void InsulinPump::drainBattery() {
    if (batteryLevel > 0) {
        batteryLevel -= 1; // Reduce battery gradually

        // Emit signal to update GUI
        emit batteryLevelChanged(batteryLevel);

        // Notify at critical battery levels
        if (batteryLevel == 20) {
            SystemAlerts::triggerAlert("Battery low! Please charge soon.");
        } else if (batteryLevel == 5) {
            SystemAlerts::escalateAlert("Battery critically low! Charge immediately.");
        } else if(batteryLevel == 0){
            emit batteryDepleted();
            batteryTimer->stop();
        }
    }
}

