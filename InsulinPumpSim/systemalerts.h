#ifndef SYSTEMALERTS_H
#define SYSTEMALERTS_H

#include <string>

using namespace std;
class SystemAlerts
{

public:
    SystemAlerts();
    void triggerAlert(const string& alertMessage);
    void logAlert(const string& alertMessage);
    void escalateAlert(const string& alertMessage);


};

#endif // SYSTEMALERTS_H
