#include "mainwindow.h"
#include "profile.h"
#include "user.h"
#include "insulinpump.h"
#include "QDateTime"




MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , insulinPump(new InsulinPump())
{
    ui->setupUi(this);

    // Disable scroll bars for graphicsView
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->stackedWidget->setCurrentIndex(0);
    setLockScreenState(true);  // Lock everything except 1,2,3 buttons

    // In MainWindow constructor, connect the signal
    connect(ui->spDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::onProfileSelected);
    connect(ui->spButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_spButtonBox_clicked);
    connect(ui->dppDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::on_dppProfileSelected);
    connect(ui->dppButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_dppButtonBox_clicked);
    connect(ui->vppButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_vppButtonBox_clicked);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay2);
    // connect(ui->bolusButton, &QPushButton::clicked, this, &MainWindow::on_bolusButton_clicked);

     // Connect battery depletion signal to screen change function
    connect(insulinPump, &InsulinPump::batteryDepleted, this, &MainWindow::changePageToBatteryLow);

    // Set up the timer to update every second
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);
    clockTimer->start(1000);  // Update every (1 second)

    // Initial clock update
    updateClock();

    // Add this in MainWindow constructor
    inactivityTimer = new QTimer(this);
    connect(inactivityTimer, &QTimer::timeout, this, &MainWindow::returnToLockPage);

    qApp->installEventFilter(this);

    // graph
    displayXYPoints();
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::returnToLockPage() {
    ui->stackedWidget->setCurrentIndex(0);
    b1 = false;
    b2 = false;

}



void MainWindow::updateClock() {
    QString currentTime = QDateTime::currentDateTime().toString("d MMMM yyyy hh:mm AP");
    ui->clockLabel->setText(currentTime);  // Update the text of the QLabel
    ui->clockLabel2->setText(currentTime);
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

void MainWindow::changePageToBatteryLow() {
    ui->stackedWidget->setCurrentIndex(9);
}



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



void MainWindow::displayXYPoints() {
    // Create a scatter series
    QtCharts::QScatterSeries* series = new QtCharts::QScatterSeries();
    series->setName("Bolus Data");

    // Add (Time, Bolus) points to the series
    series->append(1, 1);
    series->append(2, 4);
    series->append(3, 9);
    series->append(4, 16);

    // Create the chart and add the series
    QtCharts::QChart* chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("XY Points: Time vs Bolus");
    chart->setMargins(QMargins(10, 10, 10, 10));

    // Create and configure the X-Axis (Time)
    QtCharts::QValueAxis* axisX = new QtCharts::QValueAxis();
    axisX->setTitleText("Time");
    QFont axisFontX = axisX->titleFont();
    axisFontX.setPointSize(10);
    axisX->setTitleFont(axisFontX);
    axisX->setLabelsAngle(0);
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create and configure the Y-Axis (Bolus)
    QtCharts::QValueAxis* axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("Bolus");
    QFont axisFontY = axisY->titleFont();
    axisFontY.setPointSize(10);
    axisY->setTitleFont(axisFontY);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view with antialiasing
    QtCharts::QChartView* chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a scene and embed the chart view in the graphicsView
    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->addWidget(chartView);

    // Optional: resize the chart view to match the graphics view size
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
