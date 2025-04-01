#ifndef CGM_H
#define CGM_H

class CGM
{
public:
    CGM();
    float monitorGlucose();
    bool detectDisconnection();

private:
    float sensorData;
};

#endif // CGM_H
