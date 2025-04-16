#include "cgm.h"
#include <QDebug>
#include <QRandomGenerator>

CGM::CGM(QObject* parent)
    : QObject(parent), sensorData(0.0f), disconnectCounter(0)
{
    connect(&monitorTimer, &QTimer::timeout, this, &CGM::monitorGlucose);
}

void CGM::startMonitoring()
{
    monitorTimer.start(1000); // simulate glucose readings every 3 seconds
    qDebug() << "CGM monitoring started.";
}

float CGM::getGlucoseLevel() const
{
    return sensorData;
}


void CGM::monitorGlucose()
{
    // Generate a glucose level between 4.0 and 10.0 mmol/L
    sensorData = 4.0 + QRandomGenerator::global()->generateDouble() * (10.0 - 4.0);
    qDebug() << "New glucose level:" << sensorData << "mmol/L";
    emit glucoseLevelUpdated(sensorData);

    // Simulate a possible disconnection every 5 readings
    disconnectCounter++;
    if (disconnectCounter >= 5) {
        qDebug() << "Sensor disconnected!";
        emit sensorDisconnected();
        disconnectCounter = 0;
    }
}
