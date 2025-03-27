#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{

    delete ui;
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



void MainWindow::on_addProfileButton_clicked()
{
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
/*unlock buttonns*/
void MainWindow::on_unlock3_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}








