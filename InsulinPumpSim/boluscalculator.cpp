#include "boluscalculator.h"
#include "profile.h"
#include <QDebug>

BolusCalculator::BolusCalculator(CGM* cgm, InsulinPump* pump, QObject* parent)
    : QObject(parent), cgm(cgm), pump(pump), insulinToCarbRatio(1.0), correctionFactor(1.0), targetBG(5.0),
      totalBolusRequired(0.0), immediateBolus(0.0), extendedBolus(0.0), bolusRatePerHour(0.0)
{
}


void BolusCalculator::calculateBolus(float carbIntake, float currentBG, float IOB)
{
    // Use active profile values
    float insulinToCarbRatio = Profile::getActiveCarbRatio();
    float correctionFactor = Profile::getActiveCorrectionFactor();
    float targetBG = Profile::getActiveTargetBG();

    float carbBolus = carbIntake / insulinToCarbRatio;
    float correctionBolus = (currentBG - targetBG) / correctionFactor;
    float totalBolus = carbBolus + correctionBolus;

    totalBolusRequired = totalBolus - IOB;
    if (totalBolusRequired < 0) totalBolusRequired = 0;

    float immediateBolusFraction = 0.6;
    float extendedBolusFraction = 0.4;
    int bolusDuration = 3;

    immediateBolus = immediateBolusFraction * totalBolusRequired;
    extendedBolus = extendedBolusFraction * totalBolusRequired;
    bolusRatePerHour = extendedBolus / bolusDuration;

    qDebug() << "[BolusCalc] Active Profile:";
    qDebug() << "ICR:" << insulinToCarbRatio
             << " CF:" << correctionFactor
             << " Target BG:" << targetBG;

    qDebug() << "Total Bolus Required:" << totalBolusRequired << "units";
    qDebug() << "Immediate Bolus:" << immediateBolus << "units";
    qDebug() << "Extended Bolus:" << extendedBolus << "units";
    qDebug() << "Bolus Rate Per Hour:" << bolusRatePerHour << "units/hour";

    emit bolusCalculated(totalBolusRequired, immediateBolus, extendedBolus, bolusRatePerHour);
}

void BolusCalculator::confirmBolus()
{
    qDebug() << "Confirming Bolus Delivery...";

    pump->startDelivery();
    qDebug() << "Delivering Immediate Bolus:" << immediateBolus << "units";

    for (int hour = 1; hour <= 3; ++hour) {
        qDebug() << "Delivering Extended Bolus - Hour" << hour << ":" << bolusRatePerHour << "units";
    }

    pump->stopDelivery();
    emit bolusDelivered();
}
