#include "mainwindow.h"
#include "profile.h"
#include "user.h"
#include "insulinpump.h"
#include "systemalerts.h"
#include "QDateTime"
#include <QtCharts/QDateTimeAxis>






MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , simulatedMinutesElapsed(0)
    , cgm(new CGM)
    ,insulinPump(new InsulinPump())
    , simulatedClock(QTime(0, 0))  // Start simulation at 00:00
    ,simulationStartTime(QDateTime::currentDateTime())
    ,currentSimulatedTime(simulationStartTime)
{
    ui->setupUi(this);

    // Disable scroll bars for graphicsView
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->stackedWidget->setCurrentIndex(0);
    setLockScreenState(true);  // Lock everything except 1,2,3 buttons

    // UI -> Logic connections
    connect(ui->spDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::onProfileSelected);
    connect(ui->spButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_spButtonBox_clicked);
    connect(ui->dppDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::on_dppProfileSelected);
    connect(ui->dppButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_dppButtonBox_clicked);
    connect(ui->vppButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_vppButtonBox_clicked);

    // Battery updates
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay2);
    connect(insulinPump, &InsulinPump::batteryDepleted, this, &MainWindow::beginShutdownSequence);
    connect(ui->powerbutton_24, &QPushButton::clicked, this, &MainWindow::startPowerOn);


    connect(insulinPump, &InsulinPump::batteryCritical, this, &MainWindow::startBatteryBlink);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryLevelValue);

    connect(ui->chargeButton_10, &QPushButton::clicked, this, &MainWindow::startCharging);
    ui->powerbutton_24->setEnabled(false);



    connect(cgm, &CGM::glucoseLevelUpdated, this, &MainWindow::updateSensorDisplay);


    connect(ui->graphViewsButton, &QPushButton::clicked, this, &MainWindow::on_graphViewsButton_clicked);


    // CGM monitoring
    connect(cgm, &CGM::glucoseLevelUpdated, this, &MainWindow::handleNewGlucoseReading);
    cgm->startMonitoring();

    // Simulated clock timer
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);
    clockTimer->start(1000);  // 1 real second = 5 simulated minutes

    // First clock update
    updateClock();


    batteryLevel = insulinPump->getBatteryLevel();





    // Lock screen inactivity timer
    inactivityTimer = new QTimer(this);
    connect(inactivityTimer, &QTimer::timeout, this, &MainWindow::returnToLockPage);





    ui->deadBattery->setTextVisible(false);


    qApp->installEventFilter(this);

    // Initial empty graph setup
   // displayGlucoseGraph(72);  // simulate 6 hours
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::updateBatteryLevelValue(float level) {
    currentBatteryLevel = level;
}


void MainWindow::returnToLockPage() {
    if (currentBatteryLevel <= 0.0f) {
        qDebug() << "Battery is depleted. Lock screen not shown.";
        return;
    }

    qDebug() << "Battery Level is:" << currentBatteryLevel;
    qDebug() << "I AM CAUSING THIS";

    ui->stackedWidget->setCurrentIndex(0);
    b1 = false;
    b2 = false;
}


void MainWindow::startPowerOn() {
    ui->h1_7->setText("Powering on...");

    QTimer::singleShot(2000, this, [=]() {
        ui->h1_7->clear();  // Clear the message before switching
        // Set internal level and pump level back to full
        currentBatteryLevel = 100.0f;
        insulinPump->resetBattery();
        ui->stackedWidget->setCurrentIndex(0);  // Lock screen
    });
}






void MainWindow::beginShutdownSequence() {
    if (inactivityTimer->isActive())
        inactivityTimer->stop();

    ui->stackedWidget->setCurrentIndex(15);  // Shutting down screen
    // Enable the power button now
    ui->powerbutton_24->setEnabled(false);

    QTimer::singleShot(3000, this, &MainWindow::goToOffScreen);  // Simulate time passing
}



void MainWindow::goToOffScreen() {
    ui->stackedWidget->setCurrentIndex(9); // Assuming 11 is the "Off" screen
}

void MainWindow::startCharging() {
    chargingLevel = 0;
    ui->battery_3->setValue(0);
    ui->batLabel->setText("Battery charging...");
    ui->stackedWidget->setCurrentIndex(14);  // Charging screen index

    if (!chargingTimer)
        chargingTimer = new QTimer(this);

    connect(chargingTimer, &QTimer::timeout, this, &MainWindow::simulateCharging, Qt::UniqueConnection);
    chargingTimer->start(50); // Fast charging simulation
}



void MainWindow::simulateCharging() {
    chargingLevel += 5;
    ui->battery_3->setValue(chargingLevel);

    if (chargingLevel >= 100) {
        chargingTimer->stop();
        ui->batLabel->setText("Battery charged.");


        // Enable the power button now
        ui->powerbutton_24->setEnabled(true);


        // Go to off screen and wait for user to press power
        QTimer::singleShot(1500, this, [=]() {
            ui->stackedWidget->setCurrentIndex(9); // Off screen
        });
    }
}




void MainWindow::updateClock() {
    simulatedMinutesElapsed += 5;
    currentSimulatedTime = simulationStartTime.addSecs(simulatedMinutesElapsed * 60);

    QString displayTime = currentSimulatedTime.toString("d MMM yyyy hh:mm AP");
    ui->clockLabel->setText(displayTime);
    ui->clockLabel2->setText(displayTime);
}

void MainWindow::startBatteryBlink() {
    if (!batteryBlinkTimer) {
        batteryBlinkTimer = new QTimer(this);
    }

    connect(batteryBlinkTimer, &QTimer::timeout, this, [=]() {
        batteryVisible = !batteryVisible;
        ui->deadBattery->setVisible(batteryVisible);
    });

    batteryBlinkTimer->start(300); // Blink every 500 ms
}



void MainWindow::updateBatteryDisplay(float newLevel) {
    ui->battery->setValue(static_cast<int>(newLevel)); // Update QProgressBar

    // Change the color of the chunk (the actual filled part of the progress bar)
    if (newLevel > 50) {
        ui->battery->setStyleSheet("QProgressBar {"
            "border: 2px solid grey;"
            "border-radius: 5px;"
            "background: lightgray;"
            "text-align: center;"
            "color: white;"
            "}"
            "QProgressBar::chunk {"
            "background: green;"
            "border-radius: 5px;"
            "}"
        );
    }
    else if (newLevel > 20) {
        ui->battery->setStyleSheet("QProgressBar {"
            "border: 2px solid grey;"
            "border-radius: 5px;"
            "background: lightgray;"
            "text-align: center;"
            "color: white;"
            "}"
            "QProgressBar::chunk {"
            "background: orange;"
            "border-radius: 5px;"
            "}"
        );
    }
    else {
        ui->battery->setStyleSheet("QProgressBar {"
            "border: 2px solid grey;"
            "border-radius: 5px;"
            "background: lightgray;"
            "text-align: center;"
            "color: white;"
            "}"
            "QProgressBar::chunk {"
            "background: red;"
            "border-radius: 5px;"
            "}"
        );
    }
}

void MainWindow::updateBatteryDisplay2(float newLevel) {
    ui->battery_2->setValue(static_cast<int>(newLevel)); // Update second QProgressBar

    // Change the color of the chunk (the actual filled part of the progress bar)
    if (newLevel > 50) {
        ui->battery_2->setStyleSheet("QProgressBar {"
            "border: 2px solid grey;"
            "border-radius: 5px;"
            "background: 2px lightgray;"
            "text-align: center;"
            "color: white;"
            "}"
            "QProgressBar::chunk {"
            "background: green;"
            "border-radius: 5px;"
            "}"
        );
    }
    else if (newLevel > 20) {
        ui->battery_2->setStyleSheet("QProgressBar {"
            "border: 2px solid grey;"
            "border-radius: 5px;"
            "background: lightgray;"
            "text-align: center;"
            "color: white;"
            "}"
            "QProgressBar::chunk {"
            "background: orange;"
            "border-radius: 5px;"
            "}"
        );
    }
    else {
        ui->battery_2->setStyleSheet("QProgressBar {"
            "border: 2px solid grey;"
            "border-radius: 5px;"
            "background: lightgray;"
            "text-align: center;"
            "color: white;"
            "}"
            "QProgressBar::chunk {"
            "background: red;"
            "border-radius: 5px;"
            "}"
        );
    }
}

//void MainWindow::changePageToBatteryLow() {
//    ui->stackedWidget->setCurrentIndex(9);
//}



QString MainWindow::onProfileSelected() {
    //updateProfileList();

    QString selectedItem = ui->spDisplayBox->currentItem()->text();  // Get the selected item
    return selectedItem;

}

QString MainWindow::on_dppProfileSelected() {
    //updateProfileList();

    QString selectedItem = ui->dppDisplayBox->currentItem()->text();  // Get the selected item
    return selectedItem;

}


// Switch to the Update Profile pages
void MainWindow::openUpdateProfilePage() {


    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::populateProfileList() {
    ui->spDisplayBox->clear();  // Clear the list before populating

    for (Profile* profile : Profile::getProfiles()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(profile->getName()));
        ui->spDisplayBox->addItem(item);
    }

    if (ui->spDisplayBox->count() == 0) {
        QMessageBox::information(this, "No Profiles", "No profiles available.");
    }
}

void MainWindow::populateDeleteList() {
    ui->dppDisplayBox->clear();// Clear the list before populating

    for (Profile* profile : Profile::getProfiles()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(profile->getName()));
        ui->dppDisplayBox->addItem(item);
    }

    if (ui->dppDisplayBox->count() == 0) {
        QMessageBox::information(this, "No Profiles", "No profiles available.");
    }
}

void MainWindow::populateViewList() {
    ui->vppDisplayBox->clear();// Clear the list before populating

    for (Profile* profile : Profile::getProfiles()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(profile->getName()));
        ui->vppDisplayBox->addItem(item);
    }

    if (ui->vppDisplayBox->count() == 0) {
        QMessageBox::information(this, "No Profiles", "No profiles available.");
    }
}





QString MainWindow::getSelectedProfileName() const {
    return selectedProfileName;  // Return the stored selected profile name
}

void MainWindow::setSelectedProfileName(const QString& profileName) {
    selectedProfileName = profileName;
}


/*functionality buttons*/
void MainWindow::on_options_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_historyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_personalProfile_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_confirmProfileButtonBox_clicked(QAbstractButton* button)
{
    // Check which button was clicked
    if (ui->confirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        // Retrieve values from the UI fields
        QString name = ui->nameInput->text();

        // Validate fields before saving
        if (name.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter a valid name.");
            return;
        }

        // If all fields are valid, create the profile
        Profile::createProfile(this);

        // Save profiles after creation
        Profile::saveProfiles();

        History::logEvent("ProfileCreated", name, "");

        // Inform the user that the profile is saved
        QMessageBox::information(this, "Success", "Profile created and saved successfully!");
        ui->stackedWidget->setCurrentIndex(4);
        // Clear the input fields after profile is created
        ui->nameInput->clear();
        ui->basalInput->clear();
        ui->carbRatioInput->clear();
        ui->correctionFactorInput->clear();
        ui->targetBGInput->clear();


    }
    else if (ui->confirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::RejectRole) {
        // Handle the "Cancel" button click
        QMessageBox::information(this, "Cancelled", "Profile creation was cancelled.");
    }
}

void MainWindow::on_addProfileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void MainWindow::on_updateProfileButton_clicked() {
    populateProfileList();
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_deleteProfileButton_clicked()
{
    populateDeleteList();
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_viewProfilesButton_clicked()
{
    populateViewList();
    ui->stackedWidget->setCurrentIndex(5);

}



/*back buttons*/
void MainWindow::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_backButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_backButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_vppBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_uppBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_sppBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_dppBackButton_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_hpBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_dlBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_spBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


/*unlock buttonns*/
void MainWindow::on_unlock1_clicked()
{
    b1 = true;
}

void MainWindow::on_unlock2_clicked()
{
    if (b1 == true)
        b2 = true;
}

void MainWindow::on_unlock3_clicked()
{
    if (b1 == true && b2 == true) {
        ui->stackedWidget->setCurrentIndex(1);
    }
    setLockScreenState(true);  // Re-enable all buttons
}




void MainWindow::on_spButtonBox_clicked(QAbstractButton* button) {
    if (ui->spButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->spDisplayBox->currentItem();

        QString selectedProfileName = selectedItem->text();

        setSelectedProfileName(selectedProfileName);  // Store the selected profile name

        moveToUpdatePage(selectedProfileName);  // Move to update page
    }
}

void MainWindow::on_dppButtonBox_clicked(QAbstractButton* button) {
    if (ui->dppButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->dppDisplayBox->currentItem();

        QString selectedProfileName = selectedItem->text();

        setSelectedProfileName(selectedProfileName);  // Store the selected profile name

        Profile::deleteProfile(this, selectedProfileName);
        History::logEvent("ProfileDeleted", selectedProfileName, "was deleted!");
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_vppButtonBox_clicked(QAbstractButton* button) {
    if (ui->vppButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->vppDisplayBox->currentItem();

        QString selectedProfileName = selectedItem->text();

        setSelectedProfileName(selectedProfileName);  // Store the selected profile name

        //Profile::viewProfile(this,selectedProfileName);
        Profile::viewProfile(this, selectedProfileName);

        ui->stackedWidget->setCurrentIndex(13);
    }
}



void MainWindow::on_uppConfirmProfileButtonBox_clicked(QAbstractButton* button) {
    if (ui->uppConfirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {

        // Call updateProfile function with the selected profile
        Profile::updateProfile(this, selectedProfileName);
        History::logEvent("ProfileUpdated", selectedProfileName, "");


    }
}



void MainWindow::on_profilesCreatedLogButton_clicked()
{
    QStringList logData = History::viewData("ProfileCreated").split("\n", Qt::SkipEmptyParts);


    ui->dlDisplayBox->clear(); // Clear existing items
    ui->dlDisplayBox->addItems(logData); // Add log lines as items to the QListWidget
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_profilesUpdatedLogButton_clicked()
{
    QStringList logData = History::viewData("ProfileUpdated").split("\n", Qt::SkipEmptyParts);

    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_profilesDeletedLogButton_clicked()
{
    QStringList logData = History::viewData("ProfileDeleted").split("\n", Qt::SkipEmptyParts);

    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_allHistoryButton_clicked()
{
    QStringList logData = History::viewData("AllHistory").split("\n", Qt::SkipEmptyParts);

    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_alertLogButton_clicked()
{
    QStringList logData = History::viewData("Alerts").split("\n", Qt::SkipEmptyParts);

    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}



bool MainWindow::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::KeyPress) {
        inactivityTimer->start(15000); // Reset the timer
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::setLockScreenState(bool locked) {
    // Disable everything except the unlock buttons when lockeds
    ui->graphicsView_2->setEnabled(!locked);
    ui->graphViewsButton_2->setEnabled(!locked);


    // Ensure only unlock buttons are enabled when locked
    ui->unlock1->setEnabled(locked);
    ui->unlock2->setEnabled(locked);
    ui->unlock3->setEnabled(locked);
}


void MainWindow::moveToUpdatePage(const QString& profileName) {

    // Store the selected profile name for later use
    selectedProfileName = profileName;

    // Find the profile in the list
    Profile* selectedProfilePtr = nullptr;
    for (Profile* profile : Profile::getProfiles()) {
        if (profile->getName() == profileName.toStdString()) {
            selectedProfilePtr = profile;
            break;
        }
    }

    if (!selectedProfilePtr) {
        QMessageBox::warning(this, "Error", "Profile not found.");
        return;
    }

    // Switch to the Update Profile page
    ui->stackedWidget->setCurrentIndex(7);
}



void MainWindow::displayGlucoseGraph(int maxPoints) {
    if (glucoseDataPoints.isEmpty()) return;

    QtCharts::QScatterSeries* series = new QtCharts::QScatterSeries();
    series->setName("CGM Readings");
    series->setMarkerSize(7.0);

    int startIndex = qMax(0, glucoseDataPoints.size() - maxPoints);
    for (int i = startIndex; i < glucoseDataPoints.size(); ++i) {
        QDateTime timestamp = glucoseDataPoints[i].first;
        float value = glucoseDataPoints[i].second;
        series->append(timestamp.toMSecsSinceEpoch(), value);
    }

    QtCharts::QChart* chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Blood Glucose Over Time (mmol/L)");
    chart->setMargins(QMargins(10, 10, 10, 10));

    QDateTime endTime = glucoseDataPoints.last().first;
    QDateTime startTime = endTime.addSecs(-currentGraphRange * 3600);

    QtCharts::QDateTimeAxis* axisX = new QtCharts::QDateTimeAxis();
    axisX->setTitleText("Time");
    axisX->setFormat("hh mm AP");
    axisX->setRange(startTime, endTime);

    // Manually adjust tick count to simulate interval logic
    if (currentGraphRange == 1) {
        axisX->setTickCount(2); // 1hr apart: 6 PM, 7 PM
    } else if (currentGraphRange == 3) {
        axisX->setTickCount(2); // 3hr apart: 6 PM, 9 PM
    } else if (currentGraphRange == 6) {
        axisX->setTickCount(2); // 6hr apart: 6 PM, 12 AM
    }

    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QtCharts::QValueAxis* axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("BG Level (mmol/L)");
    axisY->setRange(2, 14);
    axisY->setTickCount(4);
    axisY->setLabelFormat("%.0f");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QtCharts::QChartView* chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGraphicsScene* scene = ui->graphicsView->scene();
    if (!scene) {
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
    } else {
        scene->clear();
    }

    scene->addWidget(chartView);
    chartView->resize(ui->graphicsView->size());
}


void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);

    // Ensure the chart resizes to fit graphicsView_2
    if (ui->graphicsView_2->scene() && !ui->graphicsView_2->scene()->items().isEmpty()) {
        QGraphicsProxyWidget* proxyWidget = dynamic_cast<QGraphicsProxyWidget*>(ui->graphicsView_2->scene()->items().first());
        if (proxyWidget) {
            proxyWidget->widget()->resize(ui->graphicsView_2->size());
        }
    }
}


void MainWindow::handleNewGlucoseReading(float level) {
    simulatedMinutesElapsed += 5;
    QDateTime simulatedTimestamp = QDateTime::fromSecsSinceEpoch(simulatedMinutesElapsed * 60);
    glucoseDataPoints.append(qMakePair(currentSimulatedTime, level));

    if (glucoseDataPoints.size() > 72)
        glucoseDataPoints.removeFirst();

    // BG response logic
    if (level >= 10.0f) {
       // qDebug() << "[Auto-Bolus] High BG detected:" << level << "→ Triggering insulin pump.";
        startInsulinPump();
    } else if (level <= 3.9f) {
       // qDebug() << "[Alert] Low BG detected:" << level;
        // Optional: Stop insulin delivery here
    } else {
       // qDebug() << "[Normal] BG level is within normal range:" << level;
    }

    // ✅ Calculate it here
    int maxPoints = (currentGraphRange * 60) / 5;
    displayGlucoseGraph(maxPoints);
}


void MainWindow::startInsulinPump() {
    if (insulinReservoir >= 0.5f) {
        insulinPump->startDelivery();
        insulinReservoir -= 0.5f;

        qDebug() << "[Pump] Delivered 0.5 units. Remaining reservoir:" << insulinReservoir;

        // Trigger correction phase in CGM
        if (cgm->getState() != CGM::State::Correction) {
            cgm->setState(CGM::State::Correction);
        }

        // Optional: update UI progress bar or label
        // ui->insulinProgressBar->setValue(static_cast<int>(insulinReservoir));
    } else {
        qDebug() << "[Pump] Insulin reservoir empty!";
        SystemAlerts::triggerAlert("Insulin reservoir empty!");
    }
}



void MainWindow::on_graphViewsButton_clicked() {
    // Cycle through 1 → 3 → 6 → 1
    if (currentGraphRange == 1)
        currentGraphRange = 6;
    else if (currentGraphRange == 6)
        currentGraphRange = 3;
    else
        currentGraphRange = 1;

    QString label = QString::number(currentGraphRange) + " Hrs";
    ui->graphViewsButton->setText(label);
    ui->graphViewsButton_2->setText(label);

    int maxPoints = (currentGraphRange * 60) / 5;
    displayGlucoseGraph(maxPoints);
}



void MainWindow::updateSensorDisplay(float mmol) {
    ui->sensorValue->setText(QString("%1 mmol/L").arg(mmol, 0, 'f', 1));

    // Optional color coding
    QString color;
    if (mmol >= 10.0f)
        color = "red";
    else if (mmol <= 3.9f)
        color = "orange";
    else
        color = "green";

    ui->sensorValue->setStyleSheet(QString("color: %1;").arg(color));
}






void MainWindow::on_selectProfileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_apBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

