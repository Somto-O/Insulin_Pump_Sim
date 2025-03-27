/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *lockScreen;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *unlock1;
    QPushButton *unlock2;
    QPushButton *unlock3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *sensorValue_2;
    QPushButton *graphViewsButton_2;
    QLabel *label_2;
    QGraphicsView *graphicsView_2;
    QProgressBar *battery_2;
    QWidget *homePage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *bolusButton;
    QPushButton *options_Button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *sensorValue;
    QPushButton *graphViewsButton;
    QProgressBar *battery;
    QWidget *optionsPage;
    QLabel *optionsLabel;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *backButton;
    QWidget *myPumpPage;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *personalProfile_button;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *backButton_2;
    QWidget *personalProfiles;
    QPushButton *backButton_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_17;
    QPushButton *addProfileButton;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *viewProfilesButton;
    QWidget *viewProfilePage;
    QPushButton *backButton_5;
    QWidget *addProfilePage;
    QPushButton *backButton_4;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameInput;
    QLabel *basalLabel;
    QSpinBox *basalInput;
    QLabel *carbRatioLabel;
    QSpinBox *carbRatioInput;
    QLabel *carbRatioLabel_2;
    QSpinBox *carbRatioInput_2;
    QDialogButtonBox *confirmProfileButtonBox;
    QLabel *optionsLabel_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 464);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1031, 461));
        lockScreen = new QWidget();
        lockScreen->setObjectName(QString::fromUtf8("lockScreen"));
        horizontalLayoutWidget_2 = new QWidget(lockScreen);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(70, 330, 711, 81));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        unlock1 = new QPushButton(horizontalLayoutWidget_2);
        unlock1->setObjectName(QString::fromUtf8("unlock1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(unlock1->sizePolicy().hasHeightForWidth());
        unlock1->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(unlock1);

        unlock2 = new QPushButton(horizontalLayoutWidget_2);
        unlock2->setObjectName(QString::fromUtf8("unlock2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(unlock2->sizePolicy().hasHeightForWidth());
        unlock2->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(unlock2);

        unlock3 = new QPushButton(horizontalLayoutWidget_2);
        unlock3->setObjectName(QString::fromUtf8("unlock3"));
        sizePolicy.setHeightForWidth(unlock3->sizePolicy().hasHeightForWidth());
        unlock3->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(unlock3);

        verticalLayoutWidget_2 = new QWidget(lockScreen);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(660, 60, 121, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        sensorValue_2 = new QLabel(verticalLayoutWidget_2);
        sensorValue_2->setObjectName(QString::fromUtf8("sensorValue_2"));
        sizePolicy1.setHeightForWidth(sensorValue_2->sizePolicy().hasHeightForWidth());
        sensorValue_2->setSizePolicy(sizePolicy1);
        sensorValue_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(sensorValue_2);

        graphViewsButton_2 = new QPushButton(verticalLayoutWidget_2);
        graphViewsButton_2->setObjectName(QString::fromUtf8("graphViewsButton_2"));
        sizePolicy.setHeightForWidth(graphViewsButton_2->sizePolicy().hasHeightForWidth());
        graphViewsButton_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(graphViewsButton_2);

        label_2 = new QLabel(lockScreen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 310, 111, 20));
        graphicsView_2 = new QGraphicsView(lockScreen);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(70, 60, 581, 231));
        battery_2 = new QProgressBar(lockScreen);
        battery_2->setObjectName(QString::fromUtf8("battery_2"));
        battery_2->setGeometry(QRect(70, 20, 71, 23));
        battery_2->setValue(24);
        stackedWidget->addWidget(lockScreen);
        homePage = new QWidget();
        homePage->setObjectName(QString::fromUtf8("homePage"));
        horizontalLayoutWidget = new QWidget(homePage);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 330, 711, 81));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(homePage);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(70, 60, 581, 231));
        label = new QLabel(homePage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 310, 111, 20));
        bolusButton = new QPushButton(homePage);
        bolusButton->setObjectName(QString::fromUtf8("bolusButton"));
        bolusButton->setGeometry(QRect(71, 331, 352, 79));
        sizePolicy1.setHeightForWidth(bolusButton->sizePolicy().hasHeightForWidth());
        bolusButton->setSizePolicy(sizePolicy1);
        options_Button = new QPushButton(homePage);
        options_Button->setObjectName(QString::fromUtf8("options_Button"));
        options_Button->setGeometry(QRect(429, 331, 351, 79));
        sizePolicy.setHeightForWidth(options_Button->sizePolicy().hasHeightForWidth());
        options_Button->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(homePage);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(660, 60, 121, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sensorValue = new QLabel(verticalLayoutWidget);
        sensorValue->setObjectName(QString::fromUtf8("sensorValue"));
        sizePolicy1.setHeightForWidth(sensorValue->sizePolicy().hasHeightForWidth());
        sensorValue->setSizePolicy(sizePolicy1);
        sensorValue->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(sensorValue);

        graphViewsButton = new QPushButton(verticalLayoutWidget);
        graphViewsButton->setObjectName(QString::fromUtf8("graphViewsButton"));
        sizePolicy.setHeightForWidth(graphViewsButton->sizePolicy().hasHeightForWidth());
        graphViewsButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(graphViewsButton);

        battery = new QProgressBar(homePage);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(70, 20, 71, 23));
        battery->setValue(24);
        stackedWidget->addWidget(homePage);
        optionsPage = new QWidget();
        optionsPage->setObjectName(QString::fromUtf8("optionsPage"));
        optionsLabel = new QLabel(optionsPage);
        optionsLabel->setObjectName(QString::fromUtf8("optionsLabel"));
        optionsLabel->setGeometry(QRect(370, 20, 62, 17));
        optionsLabel->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_3 = new QWidget(optionsPage);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(70, 60, 691, 321));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_3);

        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton);

        pushButton_4 = new QPushButton(verticalLayoutWidget_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(verticalLayoutWidget_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_6);

        backButton = new QPushButton(optionsPage);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(30, 10, 81, 31));
        stackedWidget->addWidget(optionsPage);
        myPumpPage = new QWidget();
        myPumpPage->setObjectName(QString::fromUtf8("myPumpPage"));
        verticalLayoutWidget_4 = new QWidget(myPumpPage);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(70, 60, 691, 321));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        personalProfile_button = new QPushButton(verticalLayoutWidget_4);
        personalProfile_button->setObjectName(QString::fromUtf8("personalProfile_button"));
        sizePolicy.setHeightForWidth(personalProfile_button->sizePolicy().hasHeightForWidth());
        personalProfile_button->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(personalProfile_button);

        pushButton_14 = new QPushButton(verticalLayoutWidget_4);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(verticalLayoutWidget_4);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(pushButton_15);

        pushButton_16 = new QPushButton(verticalLayoutWidget_4);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(pushButton_16);

        backButton_2 = new QPushButton(myPumpPage);
        backButton_2->setObjectName(QString::fromUtf8("backButton_2"));
        backButton_2->setGeometry(QRect(30, 20, 81, 31));
        stackedWidget->addWidget(myPumpPage);
        personalProfiles = new QWidget();
        personalProfiles->setObjectName(QString::fromUtf8("personalProfiles"));
        backButton_3 = new QPushButton(personalProfiles);
        backButton_3->setObjectName(QString::fromUtf8("backButton_3"));
        backButton_3->setGeometry(QRect(30, 20, 81, 31));
        verticalLayoutWidget_5 = new QWidget(personalProfiles);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(70, 60, 691, 321));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_17 = new QPushButton(verticalLayoutWidget_5);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(pushButton_17);

        addProfileButton = new QPushButton(verticalLayoutWidget_5);
        addProfileButton->setObjectName(QString::fromUtf8("addProfileButton"));
        sizePolicy.setHeightForWidth(addProfileButton->sizePolicy().hasHeightForWidth());
        addProfileButton->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(addProfileButton);

        pushButton_19 = new QPushButton(verticalLayoutWidget_5);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(pushButton_19);

        pushButton_20 = new QPushButton(verticalLayoutWidget_5);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(pushButton_20);

        viewProfilesButton = new QPushButton(personalProfiles);
        viewProfilesButton->setObjectName(QString::fromUtf8("viewProfilesButton"));
        viewProfilesButton->setGeometry(QRect(810, 20, 121, 31));
        sizePolicy.setHeightForWidth(viewProfilesButton->sizePolicy().hasHeightForWidth());
        viewProfilesButton->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(personalProfiles);
        viewProfilePage = new QWidget();
        viewProfilePage->setObjectName(QString::fromUtf8("viewProfilePage"));
        backButton_5 = new QPushButton(viewProfilePage);
        backButton_5->setObjectName(QString::fromUtf8("backButton_5"));
        backButton_5->setGeometry(QRect(30, 20, 81, 31));
        stackedWidget->addWidget(viewProfilePage);
        addProfilePage = new QWidget();
        addProfilePage->setObjectName(QString::fromUtf8("addProfilePage"));
        backButton_4 = new QPushButton(addProfilePage);
        backButton_4->setObjectName(QString::fromUtf8("backButton_4"));
        backButton_4->setGeometry(QRect(30, 20, 81, 31));
        formLayoutWidget = new QWidget(addProfilePage);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(150, 140, 721, 131));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameInput = new QLineEdit(formLayoutWidget);
        nameInput->setObjectName(QString::fromUtf8("nameInput"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nameInput->sizePolicy().hasHeightForWidth());
        nameInput->setSizePolicy(sizePolicy2);

        formLayout->setWidget(0, QFormLayout::FieldRole, nameInput);

        basalLabel = new QLabel(formLayoutWidget);
        basalLabel->setObjectName(QString::fromUtf8("basalLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, basalLabel);

        basalInput = new QSpinBox(formLayoutWidget);
        basalInput->setObjectName(QString::fromUtf8("basalInput"));
        sizePolicy.setHeightForWidth(basalInput->sizePolicy().hasHeightForWidth());
        basalInput->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, basalInput);

        carbRatioLabel = new QLabel(formLayoutWidget);
        carbRatioLabel->setObjectName(QString::fromUtf8("carbRatioLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, carbRatioLabel);

        carbRatioInput = new QSpinBox(formLayoutWidget);
        carbRatioInput->setObjectName(QString::fromUtf8("carbRatioInput"));
        sizePolicy.setHeightForWidth(carbRatioInput->sizePolicy().hasHeightForWidth());
        carbRatioInput->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, carbRatioInput);

        carbRatioLabel_2 = new QLabel(formLayoutWidget);
        carbRatioLabel_2->setObjectName(QString::fromUtf8("carbRatioLabel_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, carbRatioLabel_2);

        carbRatioInput_2 = new QSpinBox(formLayoutWidget);
        carbRatioInput_2->setObjectName(QString::fromUtf8("carbRatioInput_2"));
        sizePolicy.setHeightForWidth(carbRatioInput_2->sizePolicy().hasHeightForWidth());
        carbRatioInput_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, carbRatioInput_2);

        confirmProfileButtonBox = new QDialogButtonBox(addProfilePage);
        confirmProfileButtonBox->setObjectName(QString::fromUtf8("confirmProfileButtonBox"));
        confirmProfileButtonBox->setGeometry(QRect(410, 270, 171, 51));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(confirmProfileButtonBox->sizePolicy().hasHeightForWidth());
        confirmProfileButtonBox->setSizePolicy(sizePolicy3);
        confirmProfileButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        optionsLabel_2 = new QLabel(addProfilePage);
        optionsLabel_2->setObjectName(QString::fromUtf8("optionsLabel_2"));
        optionsLabel_2->setGeometry(QRect(450, 100, 131, 20));
        optionsLabel_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(addProfilePage);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        unlock1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        unlock2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        unlock3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        sensorValue_2->setText(QCoreApplication::translate("MainWindow", "7.9 mmol/l", nullptr));
        graphViewsButton_2->setText(QCoreApplication::translate("MainWindow", "3 Hrs", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Insulin On Board", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Insulin On Board", nullptr));
        bolusButton->setText(QCoreApplication::translate("MainWindow", "Bolus", nullptr));
        options_Button->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        sensorValue->setText(QCoreApplication::translate("MainWindow", "7.9 mmol/l", nullptr));
        graphViewsButton->setText(QCoreApplication::translate("MainWindow", "3 Hrs", nullptr));
        optionsLabel->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Activity", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "My Pump", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "My CGM", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Device Settings", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        personalProfile_button->setText(QCoreApplication::translate("MainWindow", "Personal Profiles", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Control-IQ", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Alerts & Reminders", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Pump Info", nullptr));
        backButton_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        backButton_3->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Pump Settings", nullptr));
        addProfileButton->setText(QCoreApplication::translate("MainWindow", "Create Profile", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Update Profile", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "Delete Profile", nullptr));
        viewProfilesButton->setText(QCoreApplication::translate("MainWindow", "View Profiles", nullptr));
        backButton_5->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        backButton_4->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        basalLabel->setText(QCoreApplication::translate("MainWindow", "Basal", nullptr));
        carbRatioLabel->setText(QCoreApplication::translate("MainWindow", "Carb Ratio", nullptr));
        carbRatioLabel_2->setText(QCoreApplication::translate("MainWindow", "Target BG", nullptr));
        optionsLabel_2->setText(QCoreApplication::translate("MainWindow", "Create Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
