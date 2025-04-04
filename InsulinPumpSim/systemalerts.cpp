#include "systemalerts.h"

#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QDateTime>

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
    ofstream file("alerts.log");

    if (!file) {
        QMessageBox::warning(nullptr, "Error", "Could not open alert log file.");
        return;
    }

    // Get current date and time in "d MMMM yyyy hh:mm:ss" format (e.g., "4 April 2025 14:30:15")
        QString currentTime = QDateTime::currentDateTime().toString("d MMMM yyyy hh:mm:ss AP");

        // Write the timestamp and alert message
        file << "[" << currentTime.toStdString() << "] Alert " << alertMessage << std::endl;


    file.close();
}


// Function to escalate an alert
void SystemAlerts::escalateAlert(const string& alertMessage) {
    // More aggressive escalation (e.g., critical error popup)
    QMessageBox::critical(nullptr, "Critical Alert", QString::fromStdString(alertMessage + "\nImmediate action required!"));

    // Log the escalation
    logAlert("ESCALATED: " + alertMessage);
}
