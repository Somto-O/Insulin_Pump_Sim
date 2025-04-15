#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H

#include <QObject>
#include "insulinpump.h"
#include "cgm.h"

class BolusCalculator : public QObject
{
    Q_OBJECT

public:
    explicit BolusCalculator(CGM* cgm, InsulinPump* pump, QObject* parent = nullptr);

    void calculateBolus(float carbIntake, float currentBG, float IOB);
    void confirmBolus();

signals:
    void bolusCalculated(float totalBolus, float immediate, float extended, float ratePerHour);
    void bolusDelivered();

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
