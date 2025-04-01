#include "cgm.h"
#include <iostream>
#include <cstdlib>

CGM::CGM()
    : sensorData(100.0) // Initialize with default glucose level
{
}

float CGM::monitorGlucose()
{
    // Simulate glucose reading between 80 and 180 mg/dL
    sensorData = 80.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (180.0 - 80.0)));
    std::cout << "Current glucose level: " << sensorData << " mg/dL" << std::endl;
    return sensorData;
}

bool CGM::detectDisconnection()
{
    if (sensorData == -1) {
        std::cout << "CGM Disconnection detected!" << std::endl;
        return true;
    }
    std::cout << "CGM is connected and working correctly." << std::endl;
    return false;
}
