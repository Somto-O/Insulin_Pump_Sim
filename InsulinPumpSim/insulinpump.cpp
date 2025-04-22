#include "insulinpump.h"
#include "systemalerts.h"
#include "mainwindow.h"
#include "QDebug"



// =========================
// Constructor
// =========================

InsulinPump::InsulinPump()
    : status("Idle"), batteryLevel(100.0f), hourlyBolusAmount(0.0f), remainingHours(0)
{
    // Battery drain setup
    batteryTimer = new QTimer(this);
    connect(batteryTimer, &QTimer::timeout, this, &InsulinPump::drainBattery);
    batteryTimer->start(4000); // Drain every 4 seconds

    // Extended bolus delivery setup
    extendedBolusTimer = new QTimer(this);
    connect(extendedBolusTimer, &QTimer::timeout, this, &InsulinPump::deliverHourlyBolus);
}




// =========================
// Insulin Delivery Methods
// =========================

void InsulinPump::startDelivery() {
    if (batteryLevel <= 10) {
        SystemAlerts::escalateAlert("Battery too low! Unable to deliver insulin.");
        return;
    }

    if (insulinReservoir < 0.5f) {
        SystemAlerts::escalateAlert("Insulin reservoir empty!");
        return;
    }

    status = "Delivering insulin";
    drainReservoir();  // Depletes insulin once per call
    std::cout << "Insulin delivery triggered." << std::endl;
}

void InsulinPump::drainReservoir() {
    if (insulinReservoir > 0.0f) {
        insulinReservoir -= 2.0f;
        if (insulinReservoir < 0.0f)
            insulinReservoir = 0.0f;

        emit reservoirLevelChanged(insulinReservoir);  // Triggers update in MainWindow

        if (insulinReservoir <= 5.0f && insulinReservoir > 0.0f) {
            SystemAlerts::triggerAlert("Insulin reservoir low!");
        }

        if (insulinReservoir == 0.0f) {
            SystemAlerts::escalateAlert("Insulin reservoir depleted!");
        }
    }
}


void InsulinPump::stopDelivery() {
    status = "Idle";
    std::cout << "Insulin pump has stopped delivering insulin." << std::endl;
}

void InsulinPump::viewStatus() {
    std::cout << "Pump Status: " << status.toStdString() << std::endl;
    std::cout << "Battery Level: " << batteryLevel << "%" << std::endl;
}

float InsulinPump::getReservoirLevel() const {
    return insulinReservoir;
}



// =========================
// Battery Handling
// =========================

void InsulinPump::drainBattery() {
    if (batteryLevel > 0) {
        batteryLevel -= 1;
        emit batteryLevelChanged(batteryLevel);

        if (batteryLevel == 20) {
            SystemAlerts::triggerAlert("Battery low! Please charge soon.");
        } else if (batteryLevel == 5) {
            SystemAlerts::escalateAlert("Battery critically low! Charge immediately.");
        } else if (batteryLevel == 0) {
            //qDebug() << "this is the batterylevel:" << batteryLevel;

            emit batteryDepleted();
            batteryTimer->stop();
            emit batteryCritical();
            extendedBolusTimer->stop();
            SystemAlerts::escalateAlert("Battery depleted. System shutting down.");
        }
    }
}

void InsulinPump::resetBattery() {
    batteryLevel = 100.0f;
    emit batteryLevelChanged(batteryLevel);
    batteryTimer->start(1000); // Resume battery drain
}

void InsulinPump::resetInsulinResrvoir() {
    insulinReservoir = 100.0f;
    emit reservoirLevelChanged(insulinReservoir);

}

float InsulinPump::getBatteryLevel() const {
    return batteryLevel;
}




// =========================
// Extended Bolus Delivery
// =========================

void InsulinPump::deliverExtendedBolus(float unitsPerHour, int durationHours) {
    if (batteryLevel <= 10) {
        SystemAlerts::escalateAlert("Battery too low for extended delivery!");
        return;
    }

    hourlyBolusAmount = unitsPerHour;
    remainingHours = durationHours;

    std::cout << "Starting extended bolus: " << unitsPerHour
              << " units/hour for " << durationHours << " hours." << std::endl;

    // Simulate compressed delivery (5s = 1 hour)
    extendedBolusTimer->start(5000);
}

void InsulinPump::deliverHourlyBolus() {
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




