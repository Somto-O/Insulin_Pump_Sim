#include "user.h"

User::User()
{

}

vector<Profile*>& User::GetProfiles()
{
    return profiles;
}

void User::createProfile(string n, float bRate, float carbRatio,float cFactor)
{
    Profile* profile = new Profile(n, bRate, carbRatio, cFactor);

    profiles.push_back(profile);
}
