#ifndef PROFILE_H
#define PROFILE_H

#include <string>
using namespace std;

class Profile {

public:
    Profile();
    void saveProfile();
    void updateProfile();
    void deleteProfile();
    void viewProfile();



private:
    string name;
    float basalRate;
    float carbohydrateRatio;
    float correctionFactor;


};

#endif // PROFILE_H
