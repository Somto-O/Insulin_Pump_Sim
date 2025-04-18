#include "cgm.h"
#include <QDebug>
#include <QRandomGenerator>

CGM::CGM(QObject* parent)
    : QObject(parent)
    , sensorData(85.0f)               // start in mid-normal range
    , disconnectCounter(0)
    , currentState(State::Idle)
{
    connect(&monitorTimer, &QTimer::timeout, this, &CGM::monitorGlucose);
}

void CGM::startMonitoring()
{
    monitorTimer.start(1000); // readings every 1 second
    qDebug() << "CGM monitoring started in state:" << static_cast<int>(currentState);
}

float CGM::getGlucoseLevel() const
{
    return sensorData;
}

CGM::State CGM::getState() const
{
    return currentState;
}

void CGM::setState(State newState)
{
    if (newState != currentState) {
        currentState = newState;
        qDebug() << "CGM state changed to:" << static_cast<int>(currentState);
        emit stateChanged(currentState);
    }
}

void CGM::monitorGlucose()
{
    constexpr float idleMin = 70.0f;
    constexpr float idleMax = 100.0f;
    constexpr float eatMax = 125.0f;
    constexpr float corrMin = 70.0f;
    const float step = 1.0f;

    switch (currentState) {
    case State::Idle:
        sensorData = idleMin + QRandomGenerator::global()->generateDouble() * (idleMax - idleMin);
        break;
    case State::Eating:
        sensorData = qMin(sensorData + step, eatMax);
        if (sensorData > 110.0f) {
            setState(State::Correction);
        }
        break;
    case State::Correction:
        sensorData = qMax(sensorData - step, corrMin);
        if (sensorData < idleMax) {
            setState(State::Idle);
        }
        break;
    }

    float mmol = sensorData / 18.0f;  // Convert from mg/dL to mmol/L
    qDebug() << "[CGM] State:" << static_cast<int>(currentState)
             << " Glucose:" << mmol << "mmol/L";

    emit glucoseLevelUpdated(mmol);

    if (++disconnectCounter >= 5) {
        qDebug() << "Sensor disconnected!";
        emit sensorDisconnected();
        disconnectCounter = 0;
    }
}
