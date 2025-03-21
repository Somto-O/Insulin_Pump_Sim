#ifndef PROFILE_H
#define PROFILE_H

#include <string>
using namespace std;

class Profile {

public:
    Profile(string n, float bRate, float carbRatio,float cFactor);
    void saveProfile();
    void updateProfile();
    void deleteProfile();
    void viewProfile();

    // helper function (test)
    string GetName();


private:
    string name;
    float basalRate;
    float carbohydrateRatio;
    float correctionFactor;


};

#endif // PROFILE_H
