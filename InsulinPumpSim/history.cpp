#include "history.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QRegularExpression>
#include <QCoreApplication>

History::History() {}

void History::logEvent(const QString& eventType, const QString& userName, const QString& details)
{
    QString fileName;
    QString logMessage;

    if (eventType == "ProfileCreated") {
        fileName = "profile_created.log";
        logMessage = QString("[%1] A new profile '%2' was created!")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(userName);
    }
    else if (eventType == "ProfileUpdated") {
        fileName = "profile_updated.log";
        logMessage = QString("[%1] '%2' was updated!")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(userName);
    }
    else if (eventType == "ProfileDeleted") {
        fileName = "profile_deleted.log";
        logMessage = QString("[%1] '%2' was deleted!")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(userName);
    }
    else {
        fileName = "general_history.log";
        logMessage = QString("[%1] Event Type: %2 | User: %3 | Details: %4")
                         .arg(QDateTime::currentDateTime().toString("d MMMM yyyy h:mm:ss AP"))
                         .arg(eventType)
                         .arg(userName)
                         .arg(details);
    }

    QString filePath = QCoreApplication::applicationDirPath() + "/../InsulinPumpSim/data/" + fileName;
    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << logMessage << "\n";
        file.close();
        qDebug() << "Event logged in" << filePath << ":" << logMessage;
    } else {
        qDebug() << "ERROR: Could not open" << filePath << "to log event!";
    }
}

QString History::viewData(const QString& logType)
{
    QString fileName;

    if (logType == "ProfileCreated") {
        fileName = "profile_created.log";
    }
    else if (logType == "ProfileUpdated") {
        fileName = "profile_updated.log";
    }
    else if (logType == "ProfileDeleted") {
        fileName = "profile_deleted.log";
    }
    else if (logType == "Alerts") {
        fileName = "alerts.log";
    }
    else if (logType == "AllHistory") {
        return mergeAndSortLogs();  // mergeAndSortLogs will be updated next
    }
    else {
        return "Invalid log type.";
    }

    QString filePath = QCoreApplication::applicationDirPath() + "/../InsulinPumpSim/data/" + fileName;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "Unable to read " + filePath;
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
        QString filePath = QCoreApplication::applicationDirPath() + "/../InsulinPumpSim/data/" + fileName;
        QFile file(filePath);
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

    std::sort(logEntries.begin(), logEntries.end(),
              [](const QPair<QDateTime, QString>& a, const QPair<QDateTime, QString>& b) {
                  return a.first < b.first;
              });

    QString sortedLog;
    for (const auto& entry : logEntries) {
        sortedLog += entry.second + "\n";
    }

    return sortedLog.isEmpty() ? "No history found." : sortedLog;
}


