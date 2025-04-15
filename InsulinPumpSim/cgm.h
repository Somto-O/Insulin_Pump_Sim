#ifndef CGM_H
#define CGM_H

#include <QObject>
#include <QTimer>

class CGM : public QObject
{
    Q_OBJECT

public:
    explicit CGM(QObject* parent = nullptr);
    void startMonitoring();
    float getGlucoseLevel() const;

signals:
    void glucoseLevelUpdated(float level);
    void sensorDisconnected();

private slots:
    void monitorGlucose();

private:
    float sensorData;
    QTimer monitorTimer;
    int disconnectCounter; // simulate disconnection
};

#endif // CGM_H
