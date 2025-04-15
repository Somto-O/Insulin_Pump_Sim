#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <vector>

class History
{
public:
    History();
    static void logEvent(const QString& eventType, const QString& userName, const QString& details);  // Log event with message
    static QString viewData(const QString& logType);
    static QString mergeAndSortLogs();
    void generateGraph();
};

#endif // HISTORY_H
