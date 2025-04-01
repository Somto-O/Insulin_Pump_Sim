#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "profile.h"
#include "user.h"

#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    // In MainWindow constructor, connect the signal
    connect(ui->spDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::onProfileSelected);
    // Connect selection change signal to slot
    connect(ui->spDisplayBox, &QListWidget::itemSelectionChanged, this, &MainWindow::onProfileSelected);
    connect(ui->spButtonBox, &QDialogButtonBox::clicked, this, &MainWindow::on_spButtonBox_clicked);

}

MainWindow::~MainWindow()
{

    delete ui;
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


// Function to update the display of profiles

//void MainWindow::updateProfileList() {

//    Profile::displayProfiles(this);  // 'this' refers to the MainWindow object
//}

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


//void MainWindow::on_spButtonBox_clicked(QAbstractButton *button) {
//    // Check if the clicked button is the "OK" or "Accept" button
//    if (ui->spButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
//        // Get the selected item from the list
//        QListWidgetItem* selectedItem = ui->spDisplayBox->currentItem();
//        if (!selectedItem) {
//            QMessageBox::warning(this, "Selection Error", "No profile selected. Please select a profile first.");
//            return;
//        }

//        QString selectedProfileName = selectedItem->text();

//        // Find the corresponding profile object
//        Profile* selectedProfile = nullptr;
//        for (Profile* profile : Profile::getProfiles()) {
//            if (profile->getName() == selectedProfileName.toStdString()) {
//                selectedProfile = profile;
//                break;
//            }
//        }

//        if (!selectedProfile) {
//            QMessageBox::warning(this, "Error", "Selected profile not found.");
//            return;
//        }

//        // Pre-fill update fields with selected profile details
//        ui->nameInput->setText(QString::fromStdString(selectedProfile->getName()));
//        ui->basalInput->setValue(selectedProfile->getBasalRate());
//        ui->carbRatioInput->setValue(selectedProfile->getCarbRatio());
//        ui->correctionFactorInput->setValue(selectedProfile->getCorrectionFactor());

//        // Switch to the Update Profile page
//        ui->stackedWidget->setCurrentIndex(7);
//    }
//}

//void MainWindow::on_spButtonBox_clicked(QAbstractButton *button) {
//    if (ui->spButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
//        QListWidgetItem* selectedItem = ui->spDisplayBox->currentItem();
//        if (!selectedItem) {
//            QMessageBox::warning(this, "Selection Error", "No profile selected. Please select a profile first.");
//            return;
//        }

//        QString selectedProfileName = selectedItem->text();
//        moveToUpdatePage(selectedProfileName);
//    }
//}



//void MainWindow::moveToUpdatePage(const QString& profileName) {
//    if (profileName.isEmpty()) {
//        QMessageBox::warning(this, "Selection Error", "No profile selected. Please select a profile first.");
//        return;
//    }

//    // Store the selected profile name for later use
//    selectedProfileName = profileName;

//    // Switch to the Update Profile page
//    ui->stackedWidget->setCurrentIndex(7);
//}







//void MainWindow::on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button)
//{
//    if(ui->uppConfirmProfileButtonBox->buttonRole(button) ==  QDialogButtonBox::AcceptRole){
//        Profile::updateProfile(this);
//    }
//    else if (ui->uppConfirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::RejectRole) {
//        // Handle the "Cancel" button click
//        QMessageBox::information(this, "Cancelled", "Profile update was cancelled.");
//}
//}

//void MainWindow::on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button) {
//    if (ui->uppConfirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
//        if (selectedProfileName.isEmpty()) {
//            QMessageBox::warning(this, "Error", "No profile selected.");
//            return;
//        }

//        // Find the profile using stored profile name
//        Profile* selectedProfile = nullptr;
//        for (Profile* profile : Profile::getProfiles()) {
//            if (QString::fromStdString(profile->getName()) == selectedProfileName) {
//                selectedProfile = profile;
//                break;
//            }
//        }

//        if (!selectedProfile) {
//            QMessageBox::warning(this, "Error", "Profile not found.");
//            return;
//        }

//        // Get user-entered values
//        float basalRate = ui->basalInput->value();
//        float carbRatio = ui->carbRatioInput->value();
//        float correctionFactor = ui->correctionFactorInput->value();

//        // Validate values
//        if (basalRate <= 0 || carbRatio <= 0 || correctionFactor <= 0) {
//            QMessageBox::warning(this, "Error", "Invalid input. Please enter positive values.");
//            return;
//        }

//        // Update the existing profile
//        selectedProfile->setBasalRate(basalRate);
//        selectedProfile->setCarbRatio(carbRatio);
//        selectedProfile->setCorrectionFactor(correctionFactor);

//        // Save changes
//        Profile::saveProfiles();

//        // Show success message
//        QMessageBox::information(this, "Success", "Profile updated successfully!");

//        // Refresh profile list after update
//        Profile::displayProfiles(this);
//    }
//}

//void MainWindow::on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button) {
//    if (ui->uppConfirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
//        if (selectedProfileName.isEmpty()) {
//            QMessageBox::warning(this, "Error", "No profile selected.");
//            return;
//        }

//        // Update the profile with the stored name
//        Profile::updateProfile(this, selectedProfileName);
//    }
//}



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
void MainWindow::on_unlock3_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}







void MainWindow::on_spButtonBox_clicked(QAbstractButton *button) {
    if (ui->spButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QListWidgetItem* selectedItem = ui->spDisplayBox->currentItem();

        if (!selectedItem) {
            QMessageBox::warning(this, "Selection Error", "No profile selected. Please select a profile first.");
            return;
        }

        QString selectedProfileName = selectedItem->text();
        qDebug() << "DEBUG: Selected Profile Name: " << selectedProfileName;  // Debug output

        setSelectedProfileName(selectedProfileName);  // Store the selected profile name

        qDebug() << "DEBUG: Stored Profile Name: " << getSelectedProfileName();  // Debug output

        moveToUpdatePage(selectedProfileName);  // Move to update page
    }
}


void MainWindow::moveToUpdatePage(const QString& profileName) {
    if (profileName.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "No profile selected. Please select a profile first.");
        return;
    }

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

    // Pre-fill the UI fields with the current profile values
//    ui->basalInput->setValue(selectedProfilePtr->getBasalRate());
//    ui->carbRatioInput->setValue(selectedProfilePtr->getCarbRatio());
//    ui->correctionFactorInput->setValue(selectedProfilePtr->getCorrectionFactor());

    // Switch to the Update Profile page
    ui->stackedWidget->setCurrentIndex(7);

    // Debug: Check pre-filled values
    qDebug() << "DEBUG: Pre-filled UI with Basal Rate: " << selectedProfilePtr->getBasalRate()
             << ", Carb Ratio: " << selectedProfilePtr->getCarbRatio()
             << ", Correction Factor: " << selectedProfilePtr->getCorrectionFactor();
}



void MainWindow::on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button) {
    if (ui->uppConfirmProfileButtonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        qDebug() << "DEBUG: Updating profile for " << selectedProfileName;

        if (selectedProfileName.isEmpty()) {
            QMessageBox::warning(this, "Error", "No profile selected.");
            qDebug() << "ERROR: No profile selected!";
            return;
        }

        // Call updateProfile function with the selected profile
        Profile::updateProfile(this, selectedProfileName);
    }
}










