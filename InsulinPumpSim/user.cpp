#include "user.h"

User::User()
{

}

vector<Profile*>& User::GetProfiles()
{
    return profiles;
}

void User::createProfile()
{
    string n;
    float bRate;
    float carbRatio;
    float cFactor;

    // user enters their info
    cout << "Enter your name: ";
    cin >> n;
    cout << "Enter your basal rate: ";
    cin >> bRate;
    cout << "Enter your carb ratio: ";
    cin >> carbRatio;
    cout << "Enter correction factor: ";
    cin >> cFactor;

    Profile* profile = new Profile(n, bRate, carbRatio, cFactor);

    profiles.push_back(profile);
}

void User::navigateProfiles()
{
    char crud = '0';

    cout << "C - Create Profile" << endl;
    cout << "R - Read Profile" << endl;
    cout << "U - Update Profile" << endl;
    cout << "D - Delete Profile" << endl;
    cout << "Enter your choice: ";

    // clear the buffer and convert to uppercase
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    crud = toupper(crud);

    switch (crud)
    {
        case 'C':
            cout << "Creating profile..." << endl;
            createProfile();
            break;

        default:
            cout << "Invalid option! Please enter C, R, U, or D." << endl;
    }
}
