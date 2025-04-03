#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "profile.h"
#include "user.h"
#include "insulinpump.h"


#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , insulinPump(new InsulinPump())
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    // In MainWindow constructor, connect the signal
    connect(ui->spDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::onProfileSelected);
    // Connect selection change signal to slot
    connect(ui->spDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::onProfileSelected);
    connect(ui->spButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_spButtonBox_clicked);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay);
    connect(insulinPump, &InsulinPump::batteryLevelChanged, this, &MainWindow::updateBatteryDisplay2);

    // Connect battery depletion signal to screen change function
    connect(insulinPump, &InsulinPump::batteryDepleted, this, &MainWindow::changePageToBatteryLow);

}

MainWindow::~MainWindow()
{

    delete ui;
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
    } else if (newLevel > 20) {
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
    } else {
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
    } else if (newLevel > 20) {
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
    } else {
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

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_personalProfile_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_viewProfilesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_confirmProfileButtonBox_clicked(QAbstractButton *button)
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

void MainWindow::on_updateProfileButton_clicked(){
    populateProfileList();
    ui->stackedWidget->setCurrentIndex(6);
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

void MainWindow::on_backButton_5_clicked()
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



/*unlock buttonns*/
void MainWindow::on_unlock1_clicked()
{
    b1 = true;
}

void MainWindow::on_unlock2_clicked()
{
    if(b1 == true)
        b2 = true;
}

void MainWindow::on_unlock3_clicked()
{
    if(b1 == true && b2 == true)
        ui->stackedWidget->setCurrentIndex(1);
}




void MainWindow::on_spButtonBox_clicked(QAbstractButton *button) {
    if (ui->spButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->spDisplayBox->currentItem();

        QString selectedProfileName = selectedItem->text();
        qDebug() << "DEBUG: Selected Profile Name: " << selectedProfileName;  // Debug output

        setSelectedProfileName(selectedProfileName);  // Store the selected profile name

        qDebug() << "DEBUG: Stored Profile Name: " << getSelectedProfileName();  // Debug output

//        if (!selectedItem) {
//            QMessageBox::warning(this, "Selection Error", "No profile selected. Please select a profile first.");
//            return;
//        }

        moveToUpdatePage(selectedProfileName);  // Move to update page
    }
}


void MainWindow::moveToUpdatePage(const QString& profileName) {
//    if (profileName.isEmpty()) {
//        QMessageBox::warning(this, "Selection Error", "No profile selected. Please select a profile first.");
//        return;
//    }

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

    // Debug: Check pre-filled values
//    qDebug() << "DEBUG: Pre-filled UI with Basal Rate: " << selectedProfilePtr->getBasalRate()
//             << ", Carb Ratio: " << selectedProfilePtr->getCarbRatio()
//             << ", Correction Factor: " << selectedProfilePtr->getCorrectionFactor();
}



void MainWindow::on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button) {
    if (ui->uppConfirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        qDebug() << "DEBUG: Updating profile for " << selectedProfileName;


        // Call updateProfile function with the selected profile
        Profile::updateProfile(this, selectedProfileName);

//        if (selectedProfileName.isEmpty()) {
//            QMessageBox::warning(this, "Error", "No profile selected.");
//            qDebug() << "ERROR: No profile selected!";
//            return;
//        }
    }
}


void MainWindow::on_deleteProfileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}







