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
    char crud;

    cout << "C - Create Profile" << endl;
    cout << "R - Read Profile" << endl;
    cout << "U - Update Profile" << endl;
    cout << "D - Delete Profile" << endl;
    cout << "Enter your choice: ";

    cin >> crud; // Read input from user
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    crud = toupper(crud); // Convert to uppercase

    switch (crud)
    {
        case 'C':
            cout << "Creating profile..." << endl;
            createProfile();
            break;
        case 'R':
            cout << "Reading profile (not implemented yet)." << endl;
            break;
        case 'U':
            cout << "Updating profile (not implemented yet)." << endl;
            break;
        case 'D':
            cout << "Deleting profile (not implemented yet)." << endl;
            break;
        default:
            cout << "Invalid option! Please enter C, R, U, or D." << endl;
    }
}
