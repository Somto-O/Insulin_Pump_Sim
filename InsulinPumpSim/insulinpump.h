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


signals:
    void batteryLevelChanged(float newLevel);  // Signal to update UI
    void batteryDepleted(); // Signal for battery = 0

private slots:
    void drainBattery();  // Function to decrease battery over time


private:
    History history;
    MainWindow* mainWindow;
    QString status;
    float batteryLevel;
    QTimer *batteryTimer;  // Timer for automatic battery drain
};

#endif // INSULINPUMP_H
