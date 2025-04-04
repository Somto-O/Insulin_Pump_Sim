#include "history.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QRegularExpression>

History::History() {}

void History::logEvent(const QString& eventType, const QString& userName, const QString& details)
{
    // Map event types to corresponding log files
    QString fileName;
    QString logMessage;

    if (eventType == "ProfileCreated") {
        fileName = "profile_created.log";
        logMessage = QString("[%1] A new profile '%2' was created!")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(userName)
                         .arg(details);
    }
    else if (eventType == "ProfileUpdated") {
        fileName = "profile_updated.log";
        logMessage = QString("[%1] '%2' was updated!")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(userName);
                       //  .arg(details);
    }
    else if (eventType == "ProfileDeleted") {
        fileName = "profile_deleted.log";
        logMessage = QString("[%1] '%2' was deleted!")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(userName);
    }
    else {
        fileName = "general_history.log";  // Default log file for unspecified events
        logMessage = QString("[%1] Event Type: %2 | User: %3 | Details: %4")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(eventType)
                         .arg(userName)
                         .arg(details);
    }

    QFile file(fileName);

    // Open file in append mode
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << logMessage << "\n";
        file.close();
        qDebug() << "Event logged in" << fileName << ":" << logMessage;
    } else {
        qDebug() << "ERROR: Could not open" << fileName << "to log event!";
    }
}

QString History::viewData(const QString& logType)
{
    QString fileName;

    // Select the correct file based on log type
    if (logType == "ProfileCreated") {
        fileName = "profile_created.log";
    }
    else if (logType == "ProfileUpdated") {
        fileName = "profile_updated.log";
    }
    else if (logType == "ProfileDeleted") {
        fileName = "profile_deleted.log";
    }
    else if (logType == "Alerts"){
        fileName = "alerts.log";
    }
    else if (logType == "AllHistory") {
        return mergeAndSortLogs();  // Call helper function to merge and sort all logs
    }
    else {
        return "Invalid log type.";
    }

    // Open the selected log file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "Unable to read " + fileName;
    }

    QTextStream in(&file);
    QString contents = in.readAll();
    file.close();

    return contents.isEmpty() ? "No entries found in " + fileName : contents;
}

QString History::mergeAndSortLogs()
{
    QStringList logFiles = { "profile_created.log", "profile_updated.log", "profile_deleted.log", "alerts.log" };
    QVector<QPair<QDateTime, QString>> logEntries;

    for (const QString& fileName : logFiles) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);

            while (!in.atEnd()) {
                QString line = in.readLine();

                // Extract timestamp (Assumes the format "[4 April 2025 2:30:15 PM]")
                QRegularExpression re(R"(\[(\d{1,2} \w+ \d{4} \d{1,2}:\d{2}:\d{2} [AP]M)])");
                QRegularExpressionMatch match = re.match(line);
                if (match.hasMatch()) {
                    QString dateTimeStr = match.captured(1);
                    QDateTime dateTime = QDateTime::fromString(dateTimeStr, "d MMMM yyyy h:mm:ss AP");

                    if (dateTime.isValid()) {
                        logEntries.append({dateTime, line});
                    }
                }
            }
            file.close();
        }
    }

    // Sort logs by date (earliest first)
    std::sort(logEntries.begin(), logEntries.end(),
              [](const QPair<QDateTime, QString>& a, const QPair<QDateTime, QString>& b) {
                  return a.first < b.first;
              });

    // Combine sorted entries
    QString sortedLog;
    for (const auto& entry : logEntries) {
        sortedLog += entry.second + "\n";
    }

    return sortedLog.isEmpty() ? "No history found." : sortedLog;
}


