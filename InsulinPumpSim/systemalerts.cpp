#include "systemalerts.h"

#include <iostream>
#include <fstream>
#include <QMessageBox>

using namespace std;

// Constructor
SystemAlerts::SystemAlerts() {}

// Function to trigger an alert
void SystemAlerts::triggerAlert(const string& alertMessage) {
    // Show an alert message to the user
    QMessageBox::warning(nullptr, "System Alert", QString::fromStdString(alertMessage));

    // Log the alert
    logAlert(alertMessage);
}

// Function to log alerts
void SystemAlerts::logAlert(const string& alertMessage)
{
    ofstream file("alerts.txt");

    if (!file) {
        QMessageBox::warning(nullptr, "Error", "Could not open alert log file.");
        return;
    }

    file << "Alert: " << alertMessage << endl;

    file.close();
}


// Function to escalate an alert
void SystemAlerts::escalateAlert(const string& alertMessage) {
    // More aggressive escalation (e.g., critical error popup)
    QMessageBox::critical(nullptr, "Critical Alert", QString::fromStdString(alertMessage + "\nImmediate action required!"));

    // Log the escalation
    logAlert("ESCALATED: " + alertMessage);
}
