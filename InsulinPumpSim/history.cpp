#include "history.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

History::History() {}

void History::logEvent(const QString& event)
{
    QFile file("history.txt");

    // Open the file in append mode to keep previous history
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << event << "\n";
        file.close();
        //qDebug() << "Event logged:" << event;
    } else {
        qDebug() << "ERROR: Could not open history.txt to log event!";
    }
}

QString History::viewData()
{
    QFile file("history.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       // qDebug() << "ERROR: Could not open history.txt to read!";
        return "Unable to read history file.";
    }

    QTextStream in(&file);
    QString contents = in.readAll();
    file.close();
    return contents;
}
