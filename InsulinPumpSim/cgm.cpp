#include "cgm.h"
#include <iostream>

CGM::CGM()
    : sensorData(0.0)  // Initialize sensor data
{
    // You can set an initial sensor value if needed
    // For example, we can start with a simulated glucose level of 100 mg/dL
    sensorData = 100.0;  // Simulating an initial glucose level
}

void CGM::monitorGlucose()
{
    // Simulate reading glucose levels from the sensor
    // In a real-world scenario, you'd get this data from the actual CGM sensor
    // Let's simulate it fluctuating within a range (e.g., 80 to 180 mg/dL)

    sensorData = 80.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (180.0 - 80.0)));  // Simulate glucose value between 80 and 180

    // Output the glucose level (just for simulation)
    std::cout << "Current glucose level: " << sensorData << " mg/dL" << std::endl;
}

void CGM::detectDisconnection()
{
    // Let's simulate a disconnection condition, which can be indicated by a specific sensor data value (e.g., -1)
    if (sensorData == -1) {
        std::cout << "CGM Disconnection detected!" << std::endl;
    } else {
        std::cout << "CGM is connected and working correctly." << std::endl;
    }
}
