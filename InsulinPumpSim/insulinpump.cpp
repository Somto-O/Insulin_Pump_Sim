#include "insulinpump.h"
#include "systemalerts.h"
#include "mainwindow.h"
#include "QDebug"

InsulinPump::InsulinPump() : status("Idle"), batteryLevel(100.0f),
    hourlyBolusAmount(0.0f), remainingHours(0)
{
    // Battery timer
    batteryTimer = new QTimer(this);
    connect(batteryTimer, &QTimer::timeout, this, &InsulinPump::drainBattery);
    batteryTimer->start(1000); // Drain every 3 seconds

    // Extended bolus timer
    extendedBolusTimer = new QTimer(this);
    connect(extendedBolusTimer, &QTimer::timeout, this, &InsulinPump::deliverHourlyBolus);
}

// Immediate delivery
void InsulinPump::startDelivery()
{
    if (batteryLevel > 10) {
        status = "Delivering insulin";
        std::cout << "Insulin pump is " << status.toStdString() << "..." << std::endl;
    } else {
        QString alert = "Battery too low! Unable to deliver insulin.";
        SystemAlerts::escalateAlert(alert.toStdString());
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

// Battery drain logic
void InsulinPump::drainBattery()
{

    if (batteryLevel > 0) {
        batteryLevel -= 10;
        emit batteryLevelChanged(batteryLevel);

        if (batteryLevel == 20) {
            SystemAlerts::triggerAlert("Battery low! Please charge soon.");
        } else if (batteryLevel == 5) {
            SystemAlerts::escalateAlert("Battery critically low! Charge immediately.");
        } else if (batteryLevel == 0) {
            qDebug() << "this is the batterylevel:" << batteryLevel;

            emit batteryDepleted();
            batteryTimer->stop();
            emit batteryCritical();
            extendedBolusTimer->stop();
            SystemAlerts::escalateAlert("Battery depleted. System shutting down.");
        }


    }

}

// Extended bolus delivery
void InsulinPump::deliverExtendedBolus(float unitsPerHour, int durationHours)
{
    if (batteryLevel <= 10) {
        SystemAlerts::escalateAlert("Battery too low for extended delivery!");
        return;
    }

    hourlyBolusAmount = unitsPerHour;
    remainingHours = durationHours;

    std::cout << "Starting extended bolus: " << unitsPerHour
              << " units/hour for " << durationHours << " hours." << std::endl;

    // Simulate hourly delivery with compressed time for testing (5 seconds = 1 hour)
    extendedBolusTimer->start(5000);
}

void InsulinPump::deliverHourlyBolus()
{
    if (remainingHours <= 0 || batteryLevel <= 10) {
        extendedBolusTimer->stop();
        stopDelivery();
        return;
    }

    std::cout << "Delivering " << hourlyBolusAmount << " units (extended bolus)." << std::endl;
    remainingHours--;

    if (remainingHours == 0) {
        std::cout << "Extended bolus completed." << std::endl;
        stopDelivery();
        extendedBolusTimer->stop();
    }
}

float InsulinPump::getBatteryLevel() const{
    return batteryLevel;
}
