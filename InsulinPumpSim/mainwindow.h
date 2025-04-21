#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include "ui_mainwindow.h"
#include "cgm.h"
#include "QDebug"
#include <QTime>


#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QtCharts/QValueAxis>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class User;
class InsulinPump;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //getter for the Ui
    Ui::MainWindow* getUI() const{return ui;}

    QString getSelectedProfileName() const;
    void setSelectedProfileName(const QString& profileName);
    QString onProfileSelected();
    QString on_dppProfileSelected();
    void openUpdateProfilePage();
    void updateProfileList();

    void handleProfileUpdateState();

    void moveToUpdatePage(const QString& profileName);
    void moveToViewPage(const QString& profileName);

    void populateProfileList();
    void populateDeleteList();
    void populateViewList();
    void on_spButtonBox_clicked(QAbstractButton *button);
    void on_dppButtonBox_clicked(QAbstractButton *button);

    void setLockScreenState(bool locked);



    void updateClock();

    void displayGlucoseGraph(int maxPoints);

    void startInsulinPump();

    //void startBatteryBlink();

    // Declare buttons
    QPushButton* createProfileButton;
    QPushButton* viewProfileButton;
    QPushButton* updateProfileButton;
    QPushButton* deleteProfileButton;
    QPushButton* graphViewsButton;

private slots:
    void updateSensorDisplay(float mmol);

    void on_graphViewsButton_clicked();  // handles range switching

    void handleNewGlucoseReading(float level);


   // void on_bolusButton_clicked();
    void on_options_Button_clicked();

    void on_pushButton_clicked();

    void on_personalProfile_button_clicked();
    void on_historyButton_clicked();

    void on_backButton_clicked();

    void on_backButton_2_clicked();

    void on_backButton_3_clicked();

    void on_unlock1_clicked();
    void on_unlock2_clicked();
    void on_unlock3_clicked();

    void on_backButton_4_clicked();


    void on_hpBackButton_clicked();
    void on_dlBackButton_clicked();

    void on_addProfileButton_clicked();
    void on_updateProfileButton_clicked();
    void on_viewProfilesButton_clicked();

    void on_vppBackButton_clicked();
    void on_vppButtonBox_clicked(QAbstractButton *button);

    void on_confirmProfileButtonBox_clicked(QAbstractButton *button);

    void on_uppBackButton_clicked();

    void on_sppBackButton_clicked();

    void on_dppBackButton_clicked();

    void on_spBackButton_clicked();

    void on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button);

    void updateBatteryDisplay(float newLevel);
    void updateBatteryDisplay2(float newLevel);

    void on_deleteProfileButton_clicked();

    //void changePageToBatteryLow();

    void on_profilesCreatedLogButton_clicked();

    void on_profilesUpdatedLogButton_clicked();

    void on_profilesDeletedLogButton_clicked();

    void on_allHistoryButton_clicked();

    void on_alertLogButton_clicked();


    void returnToLockPage();

    bool eventFilter(QObject *obj, QEvent *event) override;

    void goToOffScreen();

    void beginShutdownSequence();

private:
    Ui::MainWindow *ui;
    float insulinReservoir = 200.0f; // Initial insulin units available
    QVector<QPair<QDateTime, float>> glucoseDataPoints;  // timestamp, glucose level
    int simulatedMinutesElapsed = 0;
    CGM* cgm;
    User* user;
    InsulinPump* insulinPump;
    QString selectedProfileName;
    bool b1 = false;
    bool b2 = false;
    QTimer* clockTimer;  // Timer to update the clock
    QTimer* inactivityTimer;
    QLabel* clockLabel;  // QLabel to display the time
    QTime simulatedClock;
    QDateTime simulationStartTime;
    QDateTime currentSimulatedTime;
    int currentGraphRange = 1;  // 1 = 1h, 3 = 3h, 6 = 6h

    float batteryLevel;


    QTimer* batteryBlinkTimer = nullptr;
    bool batteryVisible = true;

    void startBatteryBlink();








protected:
    void resizeEvent(QResizeEvent* event) override;

};

#endif // MAINWINDOW_H
