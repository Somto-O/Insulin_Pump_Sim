#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H

#include <iostream>

#include "insulinpump.h"
#include "cgm.h"

class BolusCalculator
{
public:
    BolusCalculator(CGM* cgm, InsulinPump* pump);

    void calculateBolus(float carbIntake, float currentBG, float IOB);
    void confirmBolus();

private:
    CGM* cgm;
    InsulinPump* pump;

    float insulinToCarbRatio;  // ICR
    float correctionFactor;    // CF or ISF
    float targetBG;

    float totalBolusRequired;
    float immediateBolus;
    float extendedBolus;
    float bolusRatePerHour;
};

#endif // BOLUSCALCULATOR_H
