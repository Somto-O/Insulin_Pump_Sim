#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <vector>

class History
{
public:
    History();
    static void logEvent(const QString& event);  // Log event with message
    QString viewData();                   // Return the contents of the log file
    void generateGraph();
};

#endif // HISTORY_H
