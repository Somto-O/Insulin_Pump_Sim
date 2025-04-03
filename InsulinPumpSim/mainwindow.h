#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QPushButton>




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
    void on_spButtonBox_clicked(QAbstractButton *button);
    void on_dppButtonBox_clicked(QAbstractButton *button);


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

    void on_unlock1_clicked();
    void on_unlock2_clicked();
    void on_unlock3_clicked();

    void on_backButton_4_clicked();

    void on_addProfileButton_clicked();
    void on_updateProfileButton_clicked();
    void on_viewProfilesButton_clicked();

    void on_vppBackButton_clicked();

    void on_confirmProfileButtonBox_clicked(QAbstractButton *button);

    void on_uppBackButton_clicked();

    void on_sppBackButton_clicked();

    void on_dppBackButton_clicked();

    void on_uppConfirmProfileButtonBox_clicked(QAbstractButton *button);

    void updateBatteryDisplay(float newLevel);
    void updateBatteryDisplay2(float newLevel);
    
    void on_deleteProfileButton_clicked();

    void changePageToBatteryLow();


private:
    Ui::MainWindow *ui;
    User* user;
    InsulinPump* insulinPump;
    QString selectedProfileName;
    bool b1 = false;
    bool b2 = false;

};

#endif // MAINWINDOW_H
