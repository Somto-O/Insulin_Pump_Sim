#include "systemalerts.h"

#include <QMessageBox>
#include <QDateTime>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Constructor
SystemAlerts::SystemAlerts() {}

// Function to trigger an alert
void SystemAlerts::triggerAlert(const std::string& alertMessage) {
    QMessageBox::warning(nullptr, "System Alert", QString::fromStdString(alertMessage));
    logAlert(alertMessage);
}

// Function to escalate an alert
void SystemAlerts::escalateAlert(const std::string& alertMessage) {
    QMessageBox::critical(nullptr, "Critical Alert", QString::fromStdString(alertMessage));
    logAlert("ESCALATED: " + alertMessage);
}

// Function to log alerts using Qt file handling
void SystemAlerts::logAlert(const std::string& alertMessage)
{
    QString filePath = QCoreApplication::applicationDirPath() + "/../InsulinPumpSim/data/alerts.log";
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Could not open alert log file at:\n" + filePath);
        return;
    }

    QString currentTime = QDateTime::currentDateTime().toString("d MMMM yyyy hh:mm:ss AP");
    QString logEntry = "[" + currentTime + "]" + QString::fromStdString(alertMessage);

    QTextStream out(&file);
    out << logEntry << "\n";

    file.close();
  //  qDebug() << "Logged alert to:" << filePath << "\n" << logEntry;
}
