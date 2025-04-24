#ifndef USER_H
#define USER_H

#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include "mainwindow.h"

#include "profile.h"

using namespace std;

class User : public QObject
{
    Q_OBJECT

public:
    // constructor
    User(MainWindow* mw);

    // destructor
    ~User();

    // functions
    void startInsulinDelivery();
    void stopInsulinDelivery();
    void deliverManualBolus();
    void viewDeliveryData();
    void viewPumpStatus();
    void setAlerts();

public slots:
     void navigateProfiles();
     void handleUpdateProfile();



private:
    void handleCreateProfile();
    void handleViewProfile();
    void handleDeleteProfile();

    MainWindow* mainWindow;


};

#endif // USER_H
