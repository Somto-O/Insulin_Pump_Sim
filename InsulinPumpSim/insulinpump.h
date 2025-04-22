#ifndef INSULINPUMP_H
#define INSULINPUMP_H

#include <iostream>
#include <string>
#include <QObject>
#include <QTimer>
#include "mainwindow.h"
#include "history.h"


using namespace std;

class InsulinPump : public QObject
{
    Q_OBJECT

public:
    // constructor
    InsulinPump();
    virtual ~InsulinPump(){}

    // functions
    void startDelivery();
    void stopDelivery();
    void viewStatus();
    void deliverExtendedBolus(float unitsPerHour, int durationHours);
    float getBatteryLevel() const;
    float setBatteryLevel(){
        return batteryLevel =0;
    }
    void resetBattery();
    float getReservoirLevel() const;
    void resetInsulinResrvoir();




signals:
    void batteryLevelChanged(float newLevel);  // Signal to update UI
    void batteryDepleted(); // Signal for battery = 0
    void batteryCritical();
    void reservoirLevelChanged(float level);


public slots:

     void drainReservoir();

private slots:
    void drainBattery();  // Function to decrease battery over time
    void deliverHourlyBolus(); // Handles hourly extended delivery



private:
    History history;
    MainWindow* mainWindow;
    QString status;
    float batteryLevel;
    QTimer *batteryTimer;  // Timer for automatic battery drain
    float insulinReservoir = 100.0f; // Initial insulin units available
    QTimer* reservoirTimer;
    QTimer* extendedBolusTimer;   // Timer for hourly bolus delivery
    float hourlyBolusAmount;
    int remainingHours;
};

#endif // INSULINPUMP_H
