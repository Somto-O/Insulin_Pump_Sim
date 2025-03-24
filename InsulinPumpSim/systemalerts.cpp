#include "systemalerts.h"

#include <iostream>
#include <fstream>
#include <QMessageBox>

using namespace std;

// Constructor
SystemAlerts::SystemAlerts() {}

//LEAVING THIS AS IT IS, NEED MORE INFO ON THE FUNCTIONS

// Function to trigger an alert
void SystemAlerts::triggerAlert(const string& alertMessage) {
    // Show an alert message to the user
    QMessageBox::warning(nullptr, "System Alert", QString::fromStdString(alertMessage));

    // Log the alert
    logAlert(alertMessage);
}

// Function to log alerts
void SystemAlerts::logAlert(const string& alertMessage) {
    // Open a log file in append mode
    ofstream logFile("alerts.log", ios::app);

    if (logFile.is_open()) {
        logFile << "Alert: " << alertMessage << endl;
        logFile.close();
    } else {
        cerr << "Error: Could not open alert log file!" << endl;
    }
}

// Function to escalate an alert
void SystemAlerts::escalateAlert(const string& alertMessage) {
    // More aggressive escalation (e.g., critical error popup)
    QMessageBox::critical(nullptr, "Critical Alert", QString::fromStdString(alertMessage + "\nImmediate action required!"));

    // Log the escalation
    logAlert("ESCALATED: " + alertMessage);
}
