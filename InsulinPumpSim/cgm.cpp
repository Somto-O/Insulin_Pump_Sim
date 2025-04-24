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
   // qDebug() << "CGM monitoring started in state:" << static_cast<int>(currentState);
}

void CGM::stopMonitoring() {
    monitorTimer.stop();
   // qDebug() << "[CGM] Monitoring stopped.";
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
      //  qDebug() << "CGM state changed to:" << static_cast<int>(currentState);
        emit stateChanged(currentState);
    }
}

void CGM::monitorGlucose()
{
    constexpr float idleMin = 70.0f;
    constexpr float idleMax = 100.0f;
    constexpr float eatTarget = 180.0f;
    constexpr float lowThreshold = 50.0f;
    constexpr float highThreshold = 100.0f;
    const float step = 7.0f;

    switch (currentState) {
    case State::Idle:
        sensorData = idleMin + QRandomGenerator::global()->generateDouble() * (idleMax - idleMin);
        break;

    case State::Eating:
        sensorData += step;
        if (sensorData >= eatTarget) {
            setState(State::Correction);
        }
        break;

    case State::Fasting:
        sensorData -= step;
        if (sensorData <= lowThreshold) {
            setState(State::Correction);  // Start correction if BG is too low
        }
        break;

    case State::Correction:
        if (sensorData > highThreshold) {
            sensorData = qMax(sensorData - step, highThreshold);
            if (sensorData <= highThreshold) setState(State::Idle);
        } else if (sensorData < lowThreshold) {
            sensorData = qMin(sensorData + 1.0f, lowThreshold);
            if (sensorData >= lowThreshold) setState(State::Idle);
        } else {
            setState(State::Idle);
        }
        break;
    }

    float mmol = sensorData / 18.0f;
    emit glucoseLevelUpdated(mmol);

    if (++disconnectCounter >= 5) {
        emit sensorDisconnected();
        disconnectCounter = 0;
    }
}


