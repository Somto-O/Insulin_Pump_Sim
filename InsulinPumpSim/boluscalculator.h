#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H


class BolusCalculator
{
public:
    BolusCalculator();
    void calculateBolus();
    void confirmBolus();

private:
    float glucoseLevel;
    float carbohydrateIntake;
};

#endif // BOLUSCALCULATOR_H
