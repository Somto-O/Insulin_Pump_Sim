#include "boluscalculator.h"

BolusCalculator::BolusCalculator(CGM* cgm, InsulinPump* pump)
    : cgm(cgm), pump(pump), insulinToCarbRatio(1.0), correctionFactor(1.0), targetBG(5.0),
      totalBolusRequired(0.0), immediateBolus(0.0), extendedBolus(0.0), bolusRatePerHour(0.0)
{
}

void BolusCalculator::calculateBolus(float carbIntake, float currentBG, float IOB)
{
    // Step 1: Calculate Food Bolus
    float carbBolus = carbIntake / insulinToCarbRatio;

    // Step 2: Calculate Correction Bolus
    float correctionBolus = (currentBG - targetBG) / correctionFactor;

    // Step 3: Total Bolus Before IOB Adjustment
    float totalBolus = carbBolus + correctionBolus;

    // Step 4: Adjust for Insulin On Board (IOB)
    totalBolusRequired = totalBolus - IOB;

    if (totalBolusRequired < 0) totalBolusRequired = 0; // Prevent negative values

    // Step 5: Bolus Distribution
    float immediateBolusFraction = 0.6;  // 60% immediate
    float extendedBolusFraction = 0.4;   // 40% extended
    int bolusDuration = 3; // 3 hours

    immediateBolus = immediateBolusFraction * totalBolusRequired;
    extendedBolus = extendedBolusFraction * totalBolusRequired;
    bolusRatePerHour = extendedBolus / bolusDuration;

    // Display the calculated values
    std::cout << "Total Bolus Required: " << totalBolusRequired << " units" << std::endl;
    std::cout << "Immediate Bolus: " << immediateBolus << " units" << std::endl;
    std::cout << "Extended Bolus: " << extendedBolus << " units" << std::endl;
    std::cout << "Bolus Rate Per Hour: " << bolusRatePerHour << " units/hour" << std::endl;
}

void BolusCalculator::confirmBolus()
{
    std::cout << "Confirming Bolus Delivery..." << std::endl;

    // Start immediate delivery
    pump->startDelivery();
    std::cout << "Delivering Immediate Bolus: " << immediateBolus << " units" << std::endl;

    // Simulate extended delivery over 3 hours
    for (int hour = 1; hour <= 3; ++hour) {
        std::cout << "Delivering Extended Bolus - Hour " << hour << ": " << bolusRatePerHour << " units" << std::endl;
    }

    // Stop delivery after completion
    pump->stopDelivery();
}
