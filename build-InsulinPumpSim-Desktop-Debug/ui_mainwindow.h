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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView_2;
    QProgressBar *battery_2;
    QLabel *label_2;
    QLabel *clockLabel;
    QPushButton *unlock1;
    QPushButton *unlock3;
    QPushButton *unlock2;
    QPushButton *graphViewsButton_2;
    QLabel *sensorValue_2;
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
    QLabel *clockLabel2;
    QWidget *optionsPage;
    QLabel *h1;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *loadButton;
    QPushButton *activityButton;
    QPushButton *pushButton;
    QPushButton *myCGMButton;
    QPushButton *device_settingsButton;
    QPushButton *historyButton;
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
    QPushButton *pumpSettingsButton;
    QPushButton *addProfileButton;
    QPushButton *updateProfileButton;
    QPushButton *deleteProfileButton;
    QPushButton *viewProfilesButton;
    QWidget *viewProfilePage;
    QPushButton *vppBackButton;
    QListWidget *vppDisplayBox;
    QDialogButtonBox *vppButtonBox;
    QLabel *h1_3;
    QWidget *selectProfilePage;
    QPushButton *sppBackButton;
    QLabel *h1_2;
    QListWidget *spDisplayBox;
    QDialogButtonBox *spButtonBox;
    QWidget *updateProfilePage;
    QPushButton *uppBackButton;
    QDialogButtonBox *uppConfirmProfileButtonBox;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *uppBasalLabel;
    QSpinBox *uppBasalInput;
    QLabel *uppCorrectionFactorLabel;
    QSpinBox *uppCorrectionFactorInput;
    QLabel *uppCarbRatioLabel;
    QSpinBox *uppCarbRatioInput;
    QSpinBox *uppTargetBGInput;
    QLabel *uppTargetBGLabel;
    QLabel *updateProfileLabel;
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
    QLabel *targetBGLabel;
    QSpinBox *targetBGInput;
    QSpinBox *correctionFactorInput;
    QLabel *correctionFactorLabel;
    QDialogButtonBox *confirmProfileButtonBox;
    QLabel *optionsLabel_2;
    QWidget *batteryDeadPage;
    QWidget *deleteProfilePage;
    QLabel *h1_4;
    QPushButton *dppBackButton;
    QListWidget *dppDisplayBox;
    QDialogButtonBox *dppButtonBox;
    QWidget *historyPage;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_9;
    QPushButton *allHistoryButton;
    QPushButton *alertLogButton;
    QPushButton *profilesCreatedLogButton;
    QPushButton *profilesDeletedLogButton;
    QPushButton *profilesUpdatedLogButton;
    QPushButton *hpBackButton;
    QLabel *h1_5;
    QWidget *displayLogsPage;
    QListWidget *dlDisplayBox;
    QPushButton *dlBackButton;
    QLabel *h1_6;
    QWidget *specificProfilePage;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *basalLabel_2;
    QLabel *spBasal;
    QLabel *correctionFactorLabel_2;
    QLabel *spCFactor;
    QLabel *carbRatioLabel_2;
    QLabel *spCarbRatio;
    QLabel *targetBGLabel_2;
    QLabel *spTargetBG;
    QPushButton *spBackButton;
    QLabel *LABEL;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 553);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1051, 561));
        lockScreen = new QWidget();
        lockScreen->setObjectName(QString::fromUtf8("lockScreen"));
        horizontalLayoutWidget_2 = new QWidget(lockScreen);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(70, 330, 711, 81));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(lockScreen);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(660, 60, 121, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView_2 = new QGraphicsView(lockScreen);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(70, 60, 581, 231));
        battery_2 = new QProgressBar(lockScreen);
        battery_2->setObjectName(QString::fromUtf8("battery_2"));
        battery_2->setGeometry(QRect(70, 10, 81, 31));
        battery_2->setValue(100);
        label_2 = new QLabel(lockScreen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 300, 181, 21));
        clockLabel = new QLabel(lockScreen);
        clockLabel->setObjectName(QString::fromUtf8("clockLabel"));
        clockLabel->setGeometry(QRect(460, 10, 191, 31));
        clockLabel->setTextFormat(Qt::MarkdownText);
        unlock1 = new QPushButton(lockScreen);
        unlock1->setObjectName(QString::fromUtf8("unlock1"));
        unlock1->setGeometry(QRect(71, 331, 232, 79));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(unlock1->sizePolicy().hasHeightForWidth());
        unlock1->setSizePolicy(sizePolicy);
        unlock3 = new QPushButton(lockScreen);
        unlock3->setObjectName(QString::fromUtf8("unlock3"));
        unlock3->setGeometry(QRect(548, 331, 232, 79));
        sizePolicy.setHeightForWidth(unlock3->sizePolicy().hasHeightForWidth());
        unlock3->setSizePolicy(sizePolicy);
        unlock2 = new QPushButton(lockScreen);
        unlock2->setObjectName(QString::fromUtf8("unlock2"));
        unlock2->setGeometry(QRect(309, 331, 233, 79));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(unlock2->sizePolicy().hasHeightForWidth());
        unlock2->setSizePolicy(sizePolicy1);
        graphViewsButton_2 = new QPushButton(lockScreen);
        graphViewsButton_2->setObjectName(QString::fromUtf8("graphViewsButton_2"));
        graphViewsButton_2->setGeometry(QRect(662, 180, 119, 111));
        sizePolicy.setHeightForWidth(graphViewsButton_2->sizePolicy().hasHeightForWidth());
        graphViewsButton_2->setSizePolicy(sizePolicy);
        sensorValue_2 = new QLabel(lockScreen);
        sensorValue_2->setObjectName(QString::fromUtf8("sensorValue_2"));
        sensorValue_2->setGeometry(QRect(662, 62, 119, 112));
        sizePolicy1.setHeightForWidth(sensorValue_2->sizePolicy().hasHeightForWidth());
        sensorValue_2->setSizePolicy(sizePolicy1);
        sensorValue_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(lockScreen);
        horizontalLayoutWidget_2->raise();
        verticalLayoutWidget_2->raise();
        graphicsView_2->raise();
        label_2->raise();
        clockLabel->raise();
        battery_2->raise();
        unlock3->raise();
        unlock2->raise();
        unlock1->raise();
        graphViewsButton_2->raise();
        sensorValue_2->raise();
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
        label->setGeometry(QRect(70, 300, 181, 21));
        bolusButton = new QPushButton(homePage);
        bolusButton->setObjectName(QString::fromUtf8("bolusButton"));
        bolusButton->setGeometry(QRect(71, 331, 352, 79));
        sizePolicy1.setHeightForWidth(bolusButton->sizePolicy().hasHeightForWidth());
        bolusButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/ui-elements/icons8-water-drop-100.png"), QSize(), QIcon::Normal, QIcon::Off);
        bolusButton->setIcon(icon);
        bolusButton->setIconSize(QSize(50, 50));
        options_Button = new QPushButton(homePage);
        options_Button->setObjectName(QString::fromUtf8("options_Button"));
        options_Button->setGeometry(QRect(429, 331, 351, 79));
        sizePolicy.setHeightForWidth(options_Button->sizePolicy().hasHeightForWidth());
        options_Button->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/ui-elements/icons8-settings-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        options_Button->setIcon(icon1);
        options_Button->setIconSize(QSize(50, 50));
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
        battery->setGeometry(QRect(70, 10, 81, 31));
        battery->setValue(100);
        clockLabel2 = new QLabel(homePage);
        clockLabel2->setObjectName(QString::fromUtf8("clockLabel2"));
        clockLabel2->setGeometry(QRect(460, 10, 191, 31));
        clockLabel2->setTextFormat(Qt::MarkdownText);
        stackedWidget->addWidget(homePage);
        optionsPage = new QWidget();
        optionsPage->setObjectName(QString::fromUtf8("optionsPage"));
        h1 = new QLabel(optionsPage);
        h1->setObjectName(QString::fromUtf8("h1"));
        h1->setGeometry(QRect(350, 20, 131, 41));
        h1->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_3 = new QWidget(optionsPage);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(70, 90, 691, 321));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        loadButton = new QPushButton(verticalLayoutWidget_3);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        sizePolicy.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(loadButton);

        activityButton = new QPushButton(verticalLayoutWidget_3);
        activityButton->setObjectName(QString::fromUtf8("activityButton"));
        sizePolicy.setHeightForWidth(activityButton->sizePolicy().hasHeightForWidth());
        activityButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(activityButton);

        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton);

        myCGMButton = new QPushButton(verticalLayoutWidget_3);
        myCGMButton->setObjectName(QString::fromUtf8("myCGMButton"));
        sizePolicy.setHeightForWidth(myCGMButton->sizePolicy().hasHeightForWidth());
        myCGMButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(myCGMButton);

        device_settingsButton = new QPushButton(verticalLayoutWidget_3);
        device_settingsButton->setObjectName(QString::fromUtf8("device_settingsButton"));
        sizePolicy.setHeightForWidth(device_settingsButton->sizePolicy().hasHeightForWidth());
        device_settingsButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(device_settingsButton);

        historyButton = new QPushButton(verticalLayoutWidget_3);
        historyButton->setObjectName(QString::fromUtf8("historyButton"));
        sizePolicy.setHeightForWidth(historyButton->sizePolicy().hasHeightForWidth());
        historyButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(historyButton);

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
        pumpSettingsButton = new QPushButton(verticalLayoutWidget_5);
        pumpSettingsButton->setObjectName(QString::fromUtf8("pumpSettingsButton"));
        sizePolicy.setHeightForWidth(pumpSettingsButton->sizePolicy().hasHeightForWidth());
        pumpSettingsButton->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(pumpSettingsButton);

        addProfileButton = new QPushButton(verticalLayoutWidget_5);
        addProfileButton->setObjectName(QString::fromUtf8("addProfileButton"));
        sizePolicy.setHeightForWidth(addProfileButton->sizePolicy().hasHeightForWidth());
        addProfileButton->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(addProfileButton);

        updateProfileButton = new QPushButton(verticalLayoutWidget_5);
        updateProfileButton->setObjectName(QString::fromUtf8("updateProfileButton"));
        sizePolicy.setHeightForWidth(updateProfileButton->sizePolicy().hasHeightForWidth());
        updateProfileButton->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(updateProfileButton);

        deleteProfileButton = new QPushButton(verticalLayoutWidget_5);
        deleteProfileButton->setObjectName(QString::fromUtf8("deleteProfileButton"));
        sizePolicy.setHeightForWidth(deleteProfileButton->sizePolicy().hasHeightForWidth());
        deleteProfileButton->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(deleteProfileButton);

        viewProfilesButton = new QPushButton(personalProfiles);
        viewProfilesButton->setObjectName(QString::fromUtf8("viewProfilesButton"));
        viewProfilesButton->setGeometry(QRect(810, 10, 141, 41));
        sizePolicy.setHeightForWidth(viewProfilesButton->sizePolicy().hasHeightForWidth());
        viewProfilesButton->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(personalProfiles);
        viewProfilePage = new QWidget();
        viewProfilePage->setObjectName(QString::fromUtf8("viewProfilePage"));
        vppBackButton = new QPushButton(viewProfilePage);
        vppBackButton->setObjectName(QString::fromUtf8("vppBackButton"));
        vppBackButton->setGeometry(QRect(30, 20, 81, 31));
        vppDisplayBox = new QListWidget(viewProfilePage);
        vppDisplayBox->setObjectName(QString::fromUtf8("vppDisplayBox"));
        vppDisplayBox->setGeometry(QRect(260, 130, 511, 211));
        vppButtonBox = new QDialogButtonBox(viewProfilePage);
        vppButtonBox->setObjectName(QString::fromUtf8("vppButtonBox"));
        vppButtonBox->setGeometry(QRect(410, 350, 211, 51));
        vppButtonBox->setLayoutDirection(Qt::LeftToRight);
        vppButtonBox->setOrientation(Qt::Horizontal);
        vppButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        vppButtonBox->setCenterButtons(true);
        h1_3 = new QLabel(viewProfilePage);
        h1_3->setObjectName(QString::fromUtf8("h1_3"));
        h1_3->setGeometry(QRect(320, 40, 391, 91));
        h1_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(viewProfilePage);
        selectProfilePage = new QWidget();
        selectProfilePage->setObjectName(QString::fromUtf8("selectProfilePage"));
        sppBackButton = new QPushButton(selectProfilePage);
        sppBackButton->setObjectName(QString::fromUtf8("sppBackButton"));
        sppBackButton->setGeometry(QRect(30, 20, 81, 31));
        h1_2 = new QLabel(selectProfilePage);
        h1_2->setObjectName(QString::fromUtf8("h1_2"));
        h1_2->setGeometry(QRect(330, 40, 371, 81));
        h1_2->setAlignment(Qt::AlignCenter);
        spDisplayBox = new QListWidget(selectProfilePage);
        spDisplayBox->setObjectName(QString::fromUtf8("spDisplayBox"));
        spDisplayBox->setGeometry(QRect(260, 130, 511, 211));
        spButtonBox = new QDialogButtonBox(selectProfilePage);
        spButtonBox->setObjectName(QString::fromUtf8("spButtonBox"));
        spButtonBox->setGeometry(QRect(410, 350, 211, 51));
        spButtonBox->setLayoutDirection(Qt::LeftToRight);
        spButtonBox->setOrientation(Qt::Horizontal);
        spButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spButtonBox->setCenterButtons(true);
        stackedWidget->addWidget(selectProfilePage);
        updateProfilePage = new QWidget();
        updateProfilePage->setObjectName(QString::fromUtf8("updateProfilePage"));
        uppBackButton = new QPushButton(updateProfilePage);
        uppBackButton->setObjectName(QString::fromUtf8("uppBackButton"));
        uppBackButton->setGeometry(QRect(30, 20, 81, 31));
        uppConfirmProfileButtonBox = new QDialogButtonBox(updateProfilePage);
        uppConfirmProfileButtonBox->setObjectName(QString::fromUtf8("uppConfirmProfileButtonBox"));
        uppConfirmProfileButtonBox->setGeometry(QRect(400, 270, 201, 71));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(uppConfirmProfileButtonBox->sizePolicy().hasHeightForWidth());
        uppConfirmProfileButtonBox->setSizePolicy(sizePolicy2);
        uppConfirmProfileButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        uppConfirmProfileButtonBox->setCenterButtons(true);
        formLayoutWidget_3 = new QWidget(updateProfilePage);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(150, 140, 721, 131));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        uppBasalLabel = new QLabel(formLayoutWidget_3);
        uppBasalLabel->setObjectName(QString::fromUtf8("uppBasalLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, uppBasalLabel);

        uppBasalInput = new QSpinBox(formLayoutWidget_3);
        uppBasalInput->setObjectName(QString::fromUtf8("uppBasalInput"));
        sizePolicy.setHeightForWidth(uppBasalInput->sizePolicy().hasHeightForWidth());
        uppBasalInput->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, uppBasalInput);

        uppCorrectionFactorLabel = new QLabel(formLayoutWidget_3);
        uppCorrectionFactorLabel->setObjectName(QString::fromUtf8("uppCorrectionFactorLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, uppCorrectionFactorLabel);

        uppCorrectionFactorInput = new QSpinBox(formLayoutWidget_3);
        uppCorrectionFactorInput->setObjectName(QString::fromUtf8("uppCorrectionFactorInput"));
        sizePolicy.setHeightForWidth(uppCorrectionFactorInput->sizePolicy().hasHeightForWidth());
        uppCorrectionFactorInput->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, uppCorrectionFactorInput);

        uppCarbRatioLabel = new QLabel(formLayoutWidget_3);
        uppCarbRatioLabel->setObjectName(QString::fromUtf8("uppCarbRatioLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, uppCarbRatioLabel);

        uppCarbRatioInput = new QSpinBox(formLayoutWidget_3);
        uppCarbRatioInput->setObjectName(QString::fromUtf8("uppCarbRatioInput"));
        sizePolicy.setHeightForWidth(uppCarbRatioInput->sizePolicy().hasHeightForWidth());
        uppCarbRatioInput->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, uppCarbRatioInput);

        uppTargetBGInput = new QSpinBox(formLayoutWidget_3);
        uppTargetBGInput->setObjectName(QString::fromUtf8("uppTargetBGInput"));
        sizePolicy.setHeightForWidth(uppTargetBGInput->sizePolicy().hasHeightForWidth());
        uppTargetBGInput->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, uppTargetBGInput);

        uppTargetBGLabel = new QLabel(formLayoutWidget_3);
        uppTargetBGLabel->setObjectName(QString::fromUtf8("uppTargetBGLabel"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, uppTargetBGLabel);

        updateProfileLabel = new QLabel(updateProfilePage);
        updateProfileLabel->setObjectName(QString::fromUtf8("updateProfileLabel"));
        updateProfileLabel->setGeometry(QRect(400, 80, 221, 51));
        updateProfileLabel->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(updateProfilePage);
        addProfilePage = new QWidget();
        addProfilePage->setObjectName(QString::fromUtf8("addProfilePage"));
        backButton_4 = new QPushButton(addProfilePage);
        backButton_4->setObjectName(QString::fromUtf8("backButton_4"));
        backButton_4->setGeometry(QRect(30, 20, 81, 31));
        formLayoutWidget = new QWidget(addProfilePage);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(110, 140, 721, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameInput = new QLineEdit(formLayoutWidget);
        nameInput->setObjectName(QString::fromUtf8("nameInput"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(nameInput->sizePolicy().hasHeightForWidth());
        nameInput->setSizePolicy(sizePolicy3);

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

        formLayout->setWidget(3, QFormLayout::LabelRole, carbRatioLabel);

        carbRatioInput = new QSpinBox(formLayoutWidget);
        carbRatioInput->setObjectName(QString::fromUtf8("carbRatioInput"));
        sizePolicy.setHeightForWidth(carbRatioInput->sizePolicy().hasHeightForWidth());
        carbRatioInput->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, carbRatioInput);

        targetBGLabel = new QLabel(formLayoutWidget);
        targetBGLabel->setObjectName(QString::fromUtf8("targetBGLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, targetBGLabel);

        targetBGInput = new QSpinBox(formLayoutWidget);
        targetBGInput->setObjectName(QString::fromUtf8("targetBGInput"));
        sizePolicy.setHeightForWidth(targetBGInput->sizePolicy().hasHeightForWidth());
        targetBGInput->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::FieldRole, targetBGInput);

        correctionFactorInput = new QSpinBox(formLayoutWidget);
        correctionFactorInput->setObjectName(QString::fromUtf8("correctionFactorInput"));
        sizePolicy.setHeightForWidth(correctionFactorInput->sizePolicy().hasHeightForWidth());
        correctionFactorInput->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, correctionFactorInput);

        correctionFactorLabel = new QLabel(formLayoutWidget);
        correctionFactorLabel->setObjectName(QString::fromUtf8("correctionFactorLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, correctionFactorLabel);

        confirmProfileButtonBox = new QDialogButtonBox(addProfilePage);
        confirmProfileButtonBox->setObjectName(QString::fromUtf8("confirmProfileButtonBox"));
        confirmProfileButtonBox->setGeometry(QRect(430, 300, 171, 51));
        sizePolicy2.setHeightForWidth(confirmProfileButtonBox->sizePolicy().hasHeightForWidth());
        confirmProfileButtonBox->setSizePolicy(sizePolicy2);
        confirmProfileButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        optionsLabel_2 = new QLabel(addProfilePage);
        optionsLabel_2->setObjectName(QString::fromUtf8("optionsLabel_2"));
        optionsLabel_2->setGeometry(QRect(410, 80, 211, 51));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(optionsLabel_2->sizePolicy().hasHeightForWidth());
        optionsLabel_2->setSizePolicy(sizePolicy4);
        optionsLabel_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(addProfilePage);
        batteryDeadPage = new QWidget();
        batteryDeadPage->setObjectName(QString::fromUtf8("batteryDeadPage"));
        stackedWidget->addWidget(batteryDeadPage);
        deleteProfilePage = new QWidget();
        deleteProfilePage->setObjectName(QString::fromUtf8("deleteProfilePage"));
        h1_4 = new QLabel(deleteProfilePage);
        h1_4->setObjectName(QString::fromUtf8("h1_4"));
        h1_4->setGeometry(QRect(330, 40, 371, 81));
        h1_4->setAlignment(Qt::AlignCenter);
        dppBackButton = new QPushButton(deleteProfilePage);
        dppBackButton->setObjectName(QString::fromUtf8("dppBackButton"));
        dppBackButton->setGeometry(QRect(30, 20, 81, 31));
        dppDisplayBox = new QListWidget(deleteProfilePage);
        dppDisplayBox->setObjectName(QString::fromUtf8("dppDisplayBox"));
        dppDisplayBox->setGeometry(QRect(260, 130, 511, 211));
        dppButtonBox = new QDialogButtonBox(deleteProfilePage);
        dppButtonBox->setObjectName(QString::fromUtf8("dppButtonBox"));
        dppButtonBox->setGeometry(QRect(410, 350, 211, 51));
        dppButtonBox->setLayoutDirection(Qt::LeftToRight);
        dppButtonBox->setOrientation(Qt::Horizontal);
        dppButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        dppButtonBox->setCenterButtons(true);
        stackedWidget->addWidget(deleteProfilePage);
        historyPage = new QWidget();
        historyPage->setObjectName(QString::fromUtf8("historyPage"));
        verticalLayoutWidget_6 = new QWidget(historyPage);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(70, 90, 691, 321));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        allHistoryButton = new QPushButton(verticalLayoutWidget_6);
        allHistoryButton->setObjectName(QString::fromUtf8("allHistoryButton"));
        sizePolicy.setHeightForWidth(allHistoryButton->sizePolicy().hasHeightForWidth());
        allHistoryButton->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(allHistoryButton);

        alertLogButton = new QPushButton(verticalLayoutWidget_6);
        alertLogButton->setObjectName(QString::fromUtf8("alertLogButton"));
        sizePolicy.setHeightForWidth(alertLogButton->sizePolicy().hasHeightForWidth());
        alertLogButton->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(alertLogButton);

        profilesCreatedLogButton = new QPushButton(verticalLayoutWidget_6);
        profilesCreatedLogButton->setObjectName(QString::fromUtf8("profilesCreatedLogButton"));
        sizePolicy.setHeightForWidth(profilesCreatedLogButton->sizePolicy().hasHeightForWidth());
        profilesCreatedLogButton->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(profilesCreatedLogButton);

        profilesDeletedLogButton = new QPushButton(verticalLayoutWidget_6);
        profilesDeletedLogButton->setObjectName(QString::fromUtf8("profilesDeletedLogButton"));
        sizePolicy.setHeightForWidth(profilesDeletedLogButton->sizePolicy().hasHeightForWidth());
        profilesDeletedLogButton->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(profilesDeletedLogButton);

        profilesUpdatedLogButton = new QPushButton(verticalLayoutWidget_6);
        profilesUpdatedLogButton->setObjectName(QString::fromUtf8("profilesUpdatedLogButton"));
        sizePolicy.setHeightForWidth(profilesUpdatedLogButton->sizePolicy().hasHeightForWidth());
        profilesUpdatedLogButton->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(profilesUpdatedLogButton);

        hpBackButton = new QPushButton(historyPage);
        hpBackButton->setObjectName(QString::fromUtf8("hpBackButton"));
        hpBackButton->setGeometry(QRect(30, 10, 81, 31));
        h1_5 = new QLabel(historyPage);
        h1_5->setObjectName(QString::fromUtf8("h1_5"));
        h1_5->setGeometry(QRect(350, 20, 131, 41));
        h1_5->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(historyPage);
        displayLogsPage = new QWidget();
        displayLogsPage->setObjectName(QString::fromUtf8("displayLogsPage"));
        dlDisplayBox = new QListWidget(displayLogsPage);
        dlDisplayBox->setObjectName(QString::fromUtf8("dlDisplayBox"));
        dlDisplayBox->setGeometry(QRect(180, 100, 611, 281));
        dlBackButton = new QPushButton(displayLogsPage);
        dlBackButton->setObjectName(QString::fromUtf8("dlBackButton"));
        dlBackButton->setGeometry(QRect(30, 10, 81, 31));
        h1_6 = new QLabel(displayLogsPage);
        h1_6->setObjectName(QString::fromUtf8("h1_6"));
        h1_6->setGeometry(QRect(280, 10, 371, 81));
        h1_6->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(displayLogsPage);
        specificProfilePage = new QWidget();
        specificProfilePage->setObjectName(QString::fromUtf8("specificProfilePage"));
        formLayoutWidget_2 = new QWidget(specificProfilePage);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(380, 150, 301, 187));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(50);
        formLayout_2->setVerticalSpacing(15);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        basalLabel_2 = new QLabel(formLayoutWidget_2);
        basalLabel_2->setObjectName(QString::fromUtf8("basalLabel_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, basalLabel_2);

        spBasal = new QLabel(formLayoutWidget_2);
        spBasal->setObjectName(QString::fromUtf8("spBasal"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spBasal);

        correctionFactorLabel_2 = new QLabel(formLayoutWidget_2);
        correctionFactorLabel_2->setObjectName(QString::fromUtf8("correctionFactorLabel_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, correctionFactorLabel_2);

        spCFactor = new QLabel(formLayoutWidget_2);
        spCFactor->setObjectName(QString::fromUtf8("spCFactor"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spCFactor);

        carbRatioLabel_2 = new QLabel(formLayoutWidget_2);
        carbRatioLabel_2->setObjectName(QString::fromUtf8("carbRatioLabel_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, carbRatioLabel_2);

        spCarbRatio = new QLabel(formLayoutWidget_2);
        spCarbRatio->setObjectName(QString::fromUtf8("spCarbRatio"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spCarbRatio);

        targetBGLabel_2 = new QLabel(formLayoutWidget_2);
        targetBGLabel_2->setObjectName(QString::fromUtf8("targetBGLabel_2"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, targetBGLabel_2);

        spTargetBG = new QLabel(formLayoutWidget_2);
        spTargetBG->setObjectName(QString::fromUtf8("spTargetBG"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, spTargetBG);

        spBackButton = new QPushButton(specificProfilePage);
        spBackButton->setObjectName(QString::fromUtf8("spBackButton"));
        spBackButton->setGeometry(QRect(30, 20, 81, 31));
        LABEL = new QLabel(specificProfilePage);
        LABEL->setObjectName(QString::fromUtf8("LABEL"));
        LABEL->setGeometry(QRect(410, 80, 211, 51));
        sizePolicy4.setHeightForWidth(LABEL->sizePolicy().hasHeightForWidth());
        LABEL->setSizePolicy(sizePolicy4);
        LABEL->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(specificProfilePage);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(13);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "INSULIN ON BOARD", nullptr));
        clockLabel->setText(QCoreApplication::translate("MainWindow", "Clock", nullptr));
        unlock1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        unlock3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        unlock2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        graphViewsButton_2->setText(QCoreApplication::translate("MainWindow", "3 Hrs", nullptr));
        sensorValue_2->setText(QCoreApplication::translate("MainWindow", "7.9 mmol/l", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "INSULIN ON BOARD", nullptr));
        bolusButton->setText(QCoreApplication::translate("MainWindow", "Bolus", nullptr));
        options_Button->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        sensorValue->setText(QCoreApplication::translate("MainWindow", "7.9 mmol/l", nullptr));
        graphViewsButton->setText(QCoreApplication::translate("MainWindow", "3 Hrs", nullptr));
        clockLabel2->setText(QCoreApplication::translate("MainWindow", "Clock", nullptr));
        h1->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        h1->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        activityButton->setText(QCoreApplication::translate("MainWindow", "Activity", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "My Pump", nullptr));
        myCGMButton->setText(QCoreApplication::translate("MainWindow", "My CGM", nullptr));
        device_settingsButton->setText(QCoreApplication::translate("MainWindow", "Device Settings", nullptr));
        historyButton->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        personalProfile_button->setText(QCoreApplication::translate("MainWindow", "Personal Profiles", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Control-IQ", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Alerts & Reminders", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Pump Info", nullptr));
        backButton_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        backButton_3->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pumpSettingsButton->setText(QCoreApplication::translate("MainWindow", "Pump Settings", nullptr));
        addProfileButton->setText(QCoreApplication::translate("MainWindow", "Create Profile", nullptr));
        updateProfileButton->setText(QCoreApplication::translate("MainWindow", "Update Profile", nullptr));
        deleteProfileButton->setText(QCoreApplication::translate("MainWindow", "Delete Profile", nullptr));
        viewProfilesButton->setText(QCoreApplication::translate("MainWindow", "View Profiles", nullptr));
        vppBackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        h1_3->setText(QCoreApplication::translate("MainWindow", "Select Profile to View", nullptr));
        h1_3->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        sppBackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        h1_2->setText(QCoreApplication::translate("MainWindow", "Select Profile to Update", nullptr));
        h1_2->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        uppBackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        uppBasalLabel->setText(QCoreApplication::translate("MainWindow", "Basal", nullptr));
        uppCorrectionFactorLabel->setText(QCoreApplication::translate("MainWindow", "Correction Factor", nullptr));
        uppCarbRatioLabel->setText(QCoreApplication::translate("MainWindow", "Carb Ratio", nullptr));
        uppTargetBGLabel->setText(QCoreApplication::translate("MainWindow", "Target BG", nullptr));
        updateProfileLabel->setText(QCoreApplication::translate("MainWindow", "Update Profile", nullptr));
        updateProfileLabel->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        backButton_4->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        basalLabel->setText(QCoreApplication::translate("MainWindow", "Basal", nullptr));
        carbRatioLabel->setText(QCoreApplication::translate("MainWindow", "Carb Ratio", nullptr));
        targetBGLabel->setText(QCoreApplication::translate("MainWindow", "Target BG", nullptr));
        correctionFactorLabel->setText(QCoreApplication::translate("MainWindow", "Correction Factor", nullptr));
        optionsLabel_2->setText(QCoreApplication::translate("MainWindow", "Create Profile", nullptr));
        optionsLabel_2->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        h1_4->setText(QCoreApplication::translate("MainWindow", "Select Profile to Delete", nullptr));
        h1_4->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        dppBackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        allHistoryButton->setText(QCoreApplication::translate("MainWindow", "All History", nullptr));
        alertLogButton->setText(QCoreApplication::translate("MainWindow", "Alert Log", nullptr));
        profilesCreatedLogButton->setText(QCoreApplication::translate("MainWindow", "Profiles Created Log", nullptr));
        profilesDeletedLogButton->setText(QCoreApplication::translate("MainWindow", "Profiles Deleted Log", nullptr));
        profilesUpdatedLogButton->setText(QCoreApplication::translate("MainWindow", "Profiles Updated Log", nullptr));
        hpBackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        h1_5->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        h1_5->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        dlBackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        h1_6->setText(QCoreApplication::translate("MainWindow", "Logs", nullptr));
        h1_6->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
        basalLabel_2->setText(QCoreApplication::translate("MainWindow", "Basal", nullptr));
        spBasal->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        correctionFactorLabel_2->setText(QCoreApplication::translate("MainWindow", "Correction Factor", nullptr));
        spCFactor->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        carbRatioLabel_2->setText(QCoreApplication::translate("MainWindow", "Carb Ratio", nullptr));
        spCarbRatio->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        targetBGLabel_2->setText(QCoreApplication::translate("MainWindow", "Target BG", nullptr));
        spTargetBG->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        spBackButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        LABEL->setText(QCoreApplication::translate("MainWindow", "Profile Name", nullptr));
        LABEL->setProperty("heading", QVariant(QCoreApplication::translate("MainWindow", "h1", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
