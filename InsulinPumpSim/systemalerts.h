#ifndef SYSTEMALERTS_H
#define SYSTEMALERTS_H

#include <string>

using namespace std;
class SystemAlerts
{

public:
    SystemAlerts();
    static void triggerAlert(const string& alertMessage);
    static void logAlert(const string& alertMessage);
    static void escalateAlert(const string& alertMessage);


};

#endif // SYSTEMALERTS_H
