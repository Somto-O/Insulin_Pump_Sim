#include "profile.h"

Profile::Profile(string n, float bRate, float carbRatio,float cFactor):
    name(n),
    basalRate(bRate),
    carbohydrateRatio(carbRatio),
    correctionFactor(cFactor)
{

}

string Profile::GetName() {
    return name;
}
