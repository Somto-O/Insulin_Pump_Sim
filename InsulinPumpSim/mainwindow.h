#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class User;

enum ProfileUpdateState {
    WAITING_FOR_SELECTION,
    PROFILE_SELECTED
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //getter for the Ui
    Ui::MainWindow* getUI() const{return ui;}

    QString getSelectedProfileName() const;
    void setSelectedProfileName( QString& profileName);
    QString onProfileSelected();
    void openUpdateProfilePage();
    void updateProfileList();

    void handleProfileUpdateState();

    void on_spButtonBox_clicked(QAbstractButton *button);


    // Declare buttons
    QPushButton* createProfileButton;
    QPushButton* viewProfileButton;
    QPushButton* updateProfileButton;
    QPushButton* deleteProfileButton;

private slots:


    void on_options_Button_clicked();

    void on_pushButton_clicked();

    void on_personalProfile_button_clicked();

    void on_backButton_clicked();

    void on_backButton_2_clicked();

    void on_backButton_3_clicked();

    void on_unlock3_clicked();

    void on_backButton_4_clicked();

    void on_addProfileButton_clicked();
    void on_updateProfileButton_clicked();
    void on_viewProfilesButton_clicked();

    void on_backButton_5_clicked();

    void on_confirmProfileButtonBox_clicked(QAbstractButton *button);

    void on_uppBackButton_clicked();

    void on_sppBackButton_clicked();

    void on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button);

private:
    Ui::MainWindow *ui;
    User* user;
    QString selectedProfileName;

    ProfileUpdateState updateState = WAITING_FOR_SELECTION; // Initial state
};

#endif // MAINWINDOW_H
