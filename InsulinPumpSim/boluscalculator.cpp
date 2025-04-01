#include "boluscalculator.h"

BolusCalculator::BolusCalculator():
    glucoseLevel(0.0f),
    carbohydrateIntake(0.0f),
    bolus(0.0f)
{

}

// functions
void BolusCalculator::calculateBolus()
{
    // Example bolus calculation (simplified):
    // Let's assume 1 unit of insulin for every 10g of carbs
    // and 1 unit of insulin to bring down 50 mg/dL of glucose above the target.

    const float carbsPerUnit = 10.0; // 10 grams of carbs per unit of insulin
    const float glucoseCorrectionFactor = 50.0; // 1 unit of insulin per 50 mg/dL over the target glucose

    // Calculate the bolus for carbohydrate intake
    float carbBolus = carbohydrateIntake / carbsPerUnit;

    // Calculate the bolus for high glucose (assuming target glucose level is 100 mg/dL)
    float targetGlucose = 100.0; // placeholder. this variable should be taken from user input.
    float glucoseBolus = (glucoseLevel > targetGlucose) ? (glucoseLevel - targetGlucose) / glucoseCorrectionFactor : 0.0;

    // Total bolus is the sum of both
    bolus = carbBolus + glucoseBolus;

    std::cout << "Calculated bolus: " << bolus << " units" << std::endl;
}

void BolusCalculator::confirmBolus()
{
    cout << "Bolus of " << bolus << " units confirmed for delivery." << endl;

    insulinPump.startDelivery();
}
