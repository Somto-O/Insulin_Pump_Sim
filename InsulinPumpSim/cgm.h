#ifndef CGM_H
#define CGM_H

class CGM
{
public:
    CGM();  // Constructor to initialize the sensor
    void monitorGlucose();  // Monitor glucose levels
    void detectDisconnection();  // Detect if the CGM is disconnected

private:
    float sensorData;  // Simulated glucose level from the CGM sensor
};

#endif // CGM_H
