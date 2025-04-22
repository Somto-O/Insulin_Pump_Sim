#include "mainwindow.h"
#include "profile.h"
#include "user.h"
#include "insulinpump.h"
#include "systemalerts.h"
#include "QDateTime"
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QLineSeries>




// ==============================
// Constructor / Destructor
// ==============================

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), simulatedMinutesElapsed(0),
      cgm(new CGM), insulinPump(new InsulinPump()), simulatedClock(QTime(0, 0)),
      simulationStartTime(QDateTime::currentDateTime()), currentSimulatedTime(simulationStartTime)
{
    ui->setupUi(this);

    // Initial UI Setup
    ui->stackedWidget->setCurrentIndex(0);
    setLockScreenState(true);
    ui->deadBattery->setTextVisible(false);
    ui->powerbutton_24->setEnabled(false);

    // Disable scrollbars for graphs
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Signal connections
    setupConnections();

    // Simulated Clock
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);
//    clockTimer->start(1000);
//    updateClock();

    // Inactivity Timer
    inactivityTimer = new QTimer(this);
    connect(inactivityTimer, &QTimer::timeout, this, &MainWindow::returnToLockPage);

    qApp->installEventFilter(this);
    batteryLevel = insulinPump->getBatteryLevel();
}

MainWindow::~MainWindow()
{

    delete ui;
}





// ==============================
// Setup Connections
// ==============================

void MainWindow::setupConnections()
{
    // Battery
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay2);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryLevelValue);
    connect(insulinPump, &InsulinPump::batteryDepleted, this, &MainWindow::beginShutdownSequence);
    connect(insulinPump, &InsulinPump::batteryCritical, this, &MainWindow::startBatteryBlink);
    connect(insulinPump, &InsulinPump::reservoirLevelChanged, this, &MainWindow::updateReservoirDisplay);


    // CGM
    connect(cgm, &CGM::glucoseLevelUpdated, this, &MainWindow::updateSensorDisplay);
    connect(cgm, &CGM::glucoseLevelUpdated, this, &MainWindow::handleNewGlucoseReading);

    //Simulation
    connect(ui->idleButton, &QPushButton::clicked, this, &MainWindow::setCGMStateToIdle);
    connect(ui->eatingButton, &QPushButton::clicked, this, &MainWindow::setCGMStateToEating);
    connect(ui->fastingButton, &QPushButton::clicked, this, &MainWindow::setCGMStateToFasting);
    connect(ui->startSimulationButton, &QPushButton::clicked, this, &MainWindow::startSimulation);
    connect(ui->stopSimulationButton, &QPushButton::clicked, this, &MainWindow::stopSimulation);



    // Charging & Power
    connect(ui->chargeButton_10, &QPushButton::clicked, this, &MainWindow::startCharging);
    connect(ui->powerbutton_24, &QPushButton::clicked, this, &MainWindow::startPowerOn);

    // Graph view button
    connect(ui->graphViewsButton, &QPushButton::clicked, this, &MainWindow::on_graphViewsButton_clicked);

    // Profiles
    connect(ui->spDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::onProfileSelected);
    connect(ui->spButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_spButtonBox_clicked);
    connect(ui->dppDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::on_dppProfileSelected);
    connect(ui->dppButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_dppButtonBox_clicked);
    connect(ui->vppButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_vppButtonBox_clicked);
    connect(ui->apButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_apButtonBox_clicked);
}



void MainWindow::updateReservoirDisplay(float level) {
    ui->insulinReservoir_2->setValue(static_cast<int>(level));
    ui->insulinReservoir->setValue(static_cast<int>(level));

    QString style = QString(
        "QProgressBar#insulinReservoir_2 {"
        "    border: 2px solid grey;"
        "    border-radius: 5px;"
        "    background: lightgray;"
        "    text-align: center;"
        "    color: white;"
        "}"
        "QProgressBar#insulinReservoir_2::chunk {"
        "    background-color: #2980b9;"
        "    border-radius: 5px;"
        "}"
    );

    QString style1 = QString(
        "QProgressBar#insulinReservoir {"
        "    border: 2px solid grey;"
        "    border-radius: 5px;"
        "    background: lightgray;"
        "    text-align: center;"
        "    color: white;"
        "}"
        "QProgressBar#insulinReservoir::chunk {"
        "    background-color: #2980b9;"
        "    border-radius: 5px;"
        "}");
    ui->insulinReservoir_2->setStyleSheet(style);
    ui->insulinReservoir->setStyleSheet(style1);
}





// ==============================
// Event Filter & Clock
// ==============================

bool MainWindow::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::KeyPress)
        inactivityTimer->start(30000);
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::updateClock() {
    if (!simulationRunning) return;

    simulatedMinutesElapsed += 5;
    currentSimulatedTime = simulationStartTime.addSecs(simulatedMinutesElapsed * 60);

    QString displayTime = currentSimulatedTime.toString("d MMM yyyy hh:mm AP");
    ui->clockLabel->setText(displayTime);
    ui->clockLabel2->setText(displayTime);
}



void MainWindow::returnToLockPage() {
    if (currentBatteryLevel <= 0.0f) return;
    ui->stackedWidget->setCurrentIndex(0);
    b1 = false;
    b2 = false;
}




// ==============================
// Battery Handling
// ==============================

void MainWindow::updateBatteryLevelValue(float level) {
    currentBatteryLevel = level;
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

void MainWindow::startBatteryBlink() {
    if (!batteryBlinkTimer) batteryBlinkTimer = new QTimer(this);
    connect(batteryBlinkTimer, &QTimer::timeout, this, [=]() {
        batteryVisible = !batteryVisible;
        ui->deadBattery->setVisible(batteryVisible);
    });
    batteryBlinkTimer->start(300);
}

void MainWindow::beginShutdownSequence() {
    if (inactivityTimer->isActive()) inactivityTimer->stop();
    ui->stackedWidget->setCurrentIndex(15);
    ui->powerbutton_24->setEnabled(false);
    QTimer::singleShot(3000, this, &MainWindow::goToOffScreen);
}

void MainWindow::goToOffScreen() {
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::startPowerOn() {
    ui->h1_7->setText("Powering on...");
    QTimer::singleShot(2000, this, [=]() {
        ui->h1_7->clear();
        currentBatteryLevel = 100.0f;
        insulinPump->resetBattery();
        insulinPump->resetInsulinResrvoir();
        ui->stackedWidget->setCurrentIndex(0);
    });
}




// ==============================
// Charging Handling
// ==============================

void MainWindow::startCharging() {
    chargingLevel = 0;
    ui->battery_3->setValue(0);
    ui->batLabel->setText("Battery charging...");
    ui->stackedWidget->setCurrentIndex(14);

    if (!chargingTimer) chargingTimer = new QTimer(this);
    connect(chargingTimer, &QTimer::timeout, this, &MainWindow::simulateCharging, Qt::UniqueConnection);
    chargingTimer->start(50);
}

void MainWindow::simulateCharging() {
    chargingLevel += 5;
    ui->battery_3->setValue(chargingLevel);
    if (chargingLevel >= 100) {
        chargingTimer->stop();
        ui->batLabel->setText("Battery charged.");
        ui->powerbutton_24->setEnabled(true);
        QTimer::singleShot(1500, this, [=]() {
            ui->stackedWidget->setCurrentIndex(9);
        });
    }
}




// ==============================
// Glucose Monitoring & Graph
// ==============================

void MainWindow::handleNewGlucoseReading(float level) {
    if (!simulationRunning) return;

    updateClock();  // Sync simulated time + UI clock

    glucoseDataPoints.append(qMakePair(currentSimulatedTime, level));

    if (glucoseDataPoints.size() > 72)
        glucoseDataPoints.removeFirst();

    if (level >= 10.0f) {
        startInsulinPump();
    }

    int maxPoints = (currentGraphRange * 60) / 5;
    displayGlucoseGraph(maxPoints);
}



void MainWindow::startInsulinPump() {
    if (insulinPump->getReservoirLevel() >= 0.5f) {
        insulinPump->startDelivery();  // This should handle the internal decrement + emit
        if (cgm->getState() != CGM::State::Correction) {
            cgm->setState(CGM::State::Correction);
        }
    } else {
        SystemAlerts::triggerAlert("Insulin reservoir empty!");
    }
}


void MainWindow::displayGlucoseGraph(int maxPoints) {
    if (glucoseDataPoints.isEmpty()) return;

    QtCharts::QScatterSeries* series = new QtCharts::QScatterSeries();
    series->setName("CGM Readings");
    series->setBrush(QBrush("#00bcd4"));
    series->setBorderColor(Qt::transparent);
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
    chart->setTitleBrush(QBrush(Qt::white));
    chart->setMargins(QMargins(0, 0, 0, 0));  // Remove margins for more space
    chart->legend()->setLabelColor(Qt::white);

    QDateTime endTime = glucoseDataPoints.last().first;
    QDateTime startTime = endTime.addSecs(-currentGraphRange * 3600);

    QtCharts::QDateTimeAxis* axisX = new QtCharts::QDateTimeAxis();
    axisX->setTitleText("Time");
    axisX->setFormat("hh mm AP");
    axisX->setRange(startTime, endTime);
    axisX->setTickCount(2);

    QtCharts::QValueAxis* axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("BG Level (mmol/L)");
    axisY->setRange(2, 14);
    axisY->setTickCount(4);
    axisY->setLabelFormat("%.0f");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Add red threshold line at 10 mmol/L
    QtCharts::QLineSeries* redLine = new QtCharts::QLineSeries();
    redLine->append(startTime.toMSecsSinceEpoch(), 10.0);
    redLine->append(endTime.toMSecsSinceEpoch(), 10.0);
    redLine->setColor(Qt::red);
    redLine->setName("High Threshold");
    chart->addSeries(redLine);
    redLine->attachAxis(axisX);
    redLine->attachAxis(axisY);

    // Add orange threshold line at 3.9 mmol/L
    QtCharts::QLineSeries* orangeLine = new QtCharts::QLineSeries();
    orangeLine->append(startTime.toMSecsSinceEpoch(), 3.9);
    orangeLine->append(endTime.toMSecsSinceEpoch(), 3.9);
    orangeLine->setColor(QColor("orange"));
    orangeLine->setName("Low Threshold");
    chart->addSeries(orangeLine);
    orangeLine->attachAxis(axisX);
    orangeLine->attachAxis(axisY);

    // Chart appearance
    chart->setBackgroundBrush(QBrush(QColor("#121212")));
    chart->setPlotAreaBackgroundBrush(QBrush(QColor("#1e1e1e")));
    chart->setPlotAreaBackgroundVisible(true);

    axisX->setLabelsColor(Qt::white);
    axisX->setTitleBrush(QBrush(Qt::white));
    axisX->setGridLineColor(QColor("#555555"));

    axisY->setLabelsColor(Qt::white);
    axisY->setTitleBrush(QBrush(Qt::white));
    axisY->setGridLineColor(Qt::transparent);  // Hide horizontal grid lines

    QtCharts::QChartView* chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setMinimumSize(ui->graphicsView->size());

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

    if (ui->graphicsView_2->scene() && !ui->graphicsView_2->scene()->items().isEmpty()) {
        QGraphicsProxyWidget* proxyWidget = dynamic_cast<QGraphicsProxyWidget*>(ui->graphicsView_2->scene()->items().first());
        if (proxyWidget) {
            proxyWidget->widget()->resize(ui->graphicsView_2->size());
        }
    }
}

void MainWindow::updateSensorDisplay(float mmol) {
    ui->sensorValue->setText(QString("%1 mmol/L").arg(mmol, 0, 'f', 1));
    QString color = (mmol >= 10.0f) ? "red" : (mmol <= 3.9f) ? "orange" : "green";
    ui->sensorValue->setStyleSheet(QString("color: %1;").arg(color));

    ui->sensorValue_2->setText(QString("%1 mmol/L").arg(mmol, 0, 'f', 1));
    ui->sensorValue_2->setStyleSheet(QString("color: %1;").arg(color));
}

void MainWindow::on_graphViewsButton_clicked() {
    currentGraphRange = (currentGraphRange == 1) ? 6 : (currentGraphRange == 6) ? 3 : 1;
    QString label = QString::number(currentGraphRange) + " Hrs";
    ui->graphViewsButton->setText(label);
    ui->graphViewsButton_2->setText(label);

    int maxPoints = (currentGraphRange * 60) / 5;
    displayGlucoseGraph(maxPoints);
}






// ==============================
// Profile Handling
// ==============================

QString MainWindow::getSelectedProfileName() const {
    return selectedProfileName;
}

void MainWindow::setSelectedProfileName(const QString& profileName) {
    selectedProfileName = profileName;
}

QString MainWindow::onProfileSelected() {
    QString selectedItem = ui->spDisplayBox->currentItem()->text();
    return selectedItem;
}

QString MainWindow::on_dppProfileSelected() {
    QString selectedItem = ui->dppDisplayBox->currentItem()->text();
    return selectedItem;
}

QString MainWindow::on_apProfileSelected() {
    QString selectedItem = ui->apDisplayBox->currentItem()->text();
    return selectedItem;
}

void MainWindow::openUpdateProfilePage() {
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::populateProfileList() {
    ui->spDisplayBox->clear();
    for (Profile* profile : Profile::getProfiles()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(profile->getName()));
        ui->spDisplayBox->addItem(item);
    }
    if (ui->spDisplayBox->count() == 0) {
        QMessageBox::information(this, "No Profiles", "No profiles available.");
    }
}

void MainWindow::populateDeleteList() {
    ui->dppDisplayBox->clear();
    for (Profile* profile : Profile::getProfiles()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(profile->getName()));
        ui->dppDisplayBox->addItem(item);
    }
    if (ui->dppDisplayBox->count() == 0) {
        QMessageBox::information(this, "No Profiles", "No profiles available.");
    }
}

void MainWindow::populateViewList() {
    ui->vppDisplayBox->clear();
    for (Profile* profile : Profile::getProfiles()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(profile->getName()));
        ui->vppDisplayBox->addItem(item);
    }
    if (ui->vppDisplayBox->count() == 0) {
        QMessageBox::information(this, "No Profiles", "No profiles available.");
    }
}

void MainWindow::populateActivateProfileList() {
    ui->apDisplayBox->clear();
    for (Profile* profile : Profile::getProfiles()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(profile->getName()));
        ui->apDisplayBox->addItem(item);
    }
    if (ui->apDisplayBox->count() == 0) {
        QMessageBox::information(this, "No Profiles", "No profiles available.");
    }
}



// ==============================
// Profile Page Navigation
// ==============================

void MainWindow::on_options_Button_clicked() { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::on_historyButton_clicked() { ui->stackedWidget->setCurrentIndex(11); }
void MainWindow::on_pushButton_clicked() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::on_personalProfile_button_clicked() { ui->stackedWidget->setCurrentIndex(4); }
void MainWindow::on_addProfileButton_clicked() { ui->stackedWidget->setCurrentIndex(8); }
void MainWindow::on_updateProfileButton_clicked() { populateProfileList(); ui->stackedWidget->setCurrentIndex(6); }
void MainWindow::on_deleteProfileButton_clicked() { populateDeleteList(); ui->stackedWidget->setCurrentIndex(10); }
void MainWindow::on_viewProfilesButton_clicked() { populateViewList(); ui->stackedWidget->setCurrentIndex(5); }
void MainWindow::on_selectProfileButton_clicked() {populateActivateProfileList();  ui->stackedWidget->setCurrentIndex(16); }
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





// ==============================
// Back Button Navigation
// ==============,================

void MainWindow::on_backButton_clicked() { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::on_backButton_2_clicked() { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::on_backButton_3_clicked() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::on_backButton_4_clicked() { ui->stackedWidget->setCurrentIndex(4); }
void MainWindow::on_vppBackButton_clicked() { ui->stackedWidget->setCurrentIndex(4); }
void MainWindow::on_uppBackButton_clicked() { ui->stackedWidget->setCurrentIndex(4); }
void MainWindow::on_sppBackButton_clicked() { ui->stackedWidget->setCurrentIndex(4); }
void MainWindow::on_dppBackButton_clicked() { ui->stackedWidget->setCurrentIndex(4); }
void MainWindow::on_hpBackButton_clicked() { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::on_dlBackButton_clicked() { ui->stackedWidget->setCurrentIndex(11); }
void MainWindow::on_spBackButton_clicked() { ui->stackedWidget->setCurrentIndex(4); }
void MainWindow::on_apBackButton_clicked() { ui->stackedWidget->setCurrentIndex(4); }




// ==============================
// Profile CRUD Confirmation
// ==============================

void MainWindow::on_confirmProfileButtonBox_clicked(QAbstractButton* button) {
    if (ui->confirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QString name = ui->nameInput->text();
        if (name.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter a valid name.");
            return;
        }
        Profile::createProfile(this);
        Profile::saveProfiles();
        History::logEvent("ProfileCreated", name, "");
        QMessageBox::information(this, "Success", "Profile created and saved successfully!");
        ui->stackedWidget->setCurrentIndex(4);
        ui->nameInput->clear();
        ui->basalInput->clear();
        ui->carbRatioInput->clear();
        ui->correctionFactorInput->clear();
        ui->targetBGInput->clear();
    } else if (ui->confirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::RejectRole) {
        QMessageBox::information(this, "Cancelled", "Profile creation was cancelled.");
    }
}

void MainWindow::on_spButtonBox_clicked(QAbstractButton* button) {
    if (ui->spButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->spDisplayBox->currentItem();
        QString selectedProfileName = selectedItem->text();
        setSelectedProfileName(selectedProfileName);
        moveToUpdatePage(selectedProfileName);
    }
}

void MainWindow::on_dppButtonBox_clicked(QAbstractButton* button) {
    if (ui->dppButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->dppDisplayBox->currentItem();
        QString selectedProfileName = selectedItem->text();
        setSelectedProfileName(selectedProfileName);
        Profile::deleteProfile(this, selectedProfileName);
        History::logEvent("ProfileDeleted", selectedProfileName, "was deleted!");
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_vppButtonBox_clicked(QAbstractButton* button) {
    if (ui->vppButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->vppDisplayBox->currentItem();
        QString selectedProfileName = selectedItem->text();
        setSelectedProfileName(selectedProfileName);
        Profile::viewProfile(this, selectedProfileName);
        ui->stackedWidget->setCurrentIndex(13);
    }
}

void MainWindow::on_uppConfirmProfileButtonBox_clicked(QAbstractButton* button) {
    if (ui->uppConfirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        Profile::updateProfile(this, selectedProfileName);
        History::logEvent("ProfileUpdated", selectedProfileName, "");
    }
}

void MainWindow::on_apButtonBox_clicked(QAbstractButton* button){
    if (ui->apButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->apDisplayBox->currentItem();
        QString selectedProfileName = selectedItem->text();
        setSelectedProfileName(selectedProfileName);
        Profile::activateProfile(this, selectedProfileName);

        ui->stackedWidget->setCurrentIndex(4);

    }
}




// ==============================
// Profile Logs Display
// ==============================

void MainWindow::on_profilesCreatedLogButton_clicked() {
    QStringList logData = History::viewData("ProfileCreated").split("\n", Qt::SkipEmptyParts);
    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_profilesUpdatedLogButton_clicked() {
    QStringList logData = History::viewData("ProfileUpdated").split("\n", Qt::SkipEmptyParts);
    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_profilesDeletedLogButton_clicked() {
    QStringList logData = History::viewData("ProfileDeleted").split("\n", Qt::SkipEmptyParts);
    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_allHistoryButton_clicked() {
    QStringList logData = History::viewData("AllHistory").split("\n", Qt::SkipEmptyParts);
    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_alertLogButton_clicked() {
    QStringList logData = History::viewData("Alerts").split("\n", Qt::SkipEmptyParts);
    ui->dlDisplayBox->clear();
    ui->dlDisplayBox->addItems(logData);
    ui->stackedWidget->setCurrentIndex(12);
}




// ==============================
// Lock Screen Handling
// ==============================

void MainWindow::setLockScreenState(bool locked) {
    ui->graphicsView_2->setEnabled(!locked);
    ui->graphViewsButton_2->setEnabled(!locked);
    ui->unlock1->setEnabled(locked);
    ui->unlock2->setEnabled(locked);
    ui->unlock3->setEnabled(locked);
}

void MainWindow::on_unlock1_clicked() { b1 = true; }
void MainWindow::on_unlock2_clicked() { if (b1) b2 = true; }
void MainWindow::on_unlock3_clicked() {
    if (b1 && b2) ui->stackedWidget->setCurrentIndex(1);
    setLockScreenState(true);
}





// ==============================
// Simulation
// ==============================

void MainWindow::startSimulation() {
    simulationRunning = true;
    cgm->startMonitoring();                    // Start CGM readings
    qDebug() << "[Simulation] Started";
}

void MainWindow::stopSimulation() {
    simulationRunning = false;
    cgm->stopMonitoring();                     // Stop all BG generation
}


void MainWindow::setCGMStateToIdle() {
    cgm->setState(CGM::State::Idle);
}

void MainWindow::setCGMStateToEating() {
    cgm->setState(CGM::State::Eating);

}

void MainWindow::setCGMStateToFasting() {
    cgm->setState(CGM::State::Fasting);

}





