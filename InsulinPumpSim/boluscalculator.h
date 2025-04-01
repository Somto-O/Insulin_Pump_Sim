#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H

#include <iostream>


#include "insulinpump.h"

using namespace std;

class BolusCalculator
{
public:
    // constructor
    BolusCalculator();

    // setters
    void setGlucose(float glucose) { glucoseLevel = glucose; }
    void setCarb(float carbs) { carbohydrateIntake = carbs; }

    // functions
    void calculateBolus();
    void confirmBolus();

private:
    float glucoseLevel;
    float carbohydrateIntake;
    float bolus;
    InsulinPump insulinPump;
};

#endif // BOLUSCALCULATOR_H
