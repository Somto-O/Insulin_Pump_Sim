#ifndef CGM_H
#define CGM_H


class CGM
{
    public:
        CGM();
        void monitorGlucose();
        void detectDisconnection();

    private:
        float sensorData;
};

#endif // CGM_H
