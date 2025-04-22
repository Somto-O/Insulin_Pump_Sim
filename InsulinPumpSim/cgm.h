#ifndef CGM_H
#define CGM_H

#include <QObject>
#include <QTimer>


class CGM : public QObject
{
    Q_OBJECT

public:
    enum class State { Idle, Eating, Correction, Fasting };

    explicit CGM(QObject* parent = nullptr);
    void startMonitoring();
    void stopMonitoring();
    float getGlucoseLevel() const;
    State getState() const;
    void setState(State newState);

signals:
    void glucoseLevelUpdated(float level);
    void sensorDisconnected();
    void stateChanged(State newState);

private slots:
    void monitorGlucose();


private:

    float sensorData;
    QTimer monitorTimer;
    int disconnectCounter;
    State currentState;
};

#endif // CGM_H
