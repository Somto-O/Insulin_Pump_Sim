#include "profile.h"

// static variables
vector<Profile*> Profile::profiles;

// constructor
Profile::Profile(string n, float bRate, float carbRatio,float cFactor):
    name(n),
    basalRate(bRate),
    carbohydrateRatio(carbRatio),
    correctionFactor(cFactor)
{

}

// destructor
Profile::~Profile()
{

}

// getters
string Profile::GetName() {
    return name;
}

vector<Profile*>& Profile::GetProfiles() {
    return profiles;
}

// functions
void Profile::createProfile()
{
    bool ok;
    QString n = QInputDialog::getText(nullptr, "Create Profile", "Enter your name:", QLineEdit::Normal, "", &ok);
    if (!ok || n.isEmpty()) return;

    float bRate = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your basal rate:", 0.0, 0.0, 10.0, 2, &ok);
    if (!ok) return;

    float carbRatio = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your carb ratio:", 0.0, 0.0, 20.0, 2, &ok);
    if (!ok) return;

    float cFactor = QInputDialog::getDouble(nullptr, "Create Profile", "Enter your correction factor:", 0.0, 0.0, 10.0, 2, &ok);
    if (!ok) return;

    Profile* profile = new Profile(n.toStdString(), bRate, carbRatio, cFactor);
    profiles.push_back(profile);

    QMessageBox::information(nullptr, "Success", "Profile created successfully!");
}



