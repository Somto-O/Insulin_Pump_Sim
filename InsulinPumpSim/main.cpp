#include "mainwindow.h"
#include "user.h"
#include "profile.h"

#include <iostream>

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

using namespace std;

void loadStyleSheet(QApplication &app){
    QFile file("styles.qss");
    if (file.open(QFile::ReadOnly)){
        QString styleSheet = QTextStream(&file).readAll();
        app.setStyleSheet(styleSheet);
        qDebug() << "Stylesheet loaded!";
        file.close();
    } else {
        qDebug() << "Could not open styles.qss at:" << QDir::currentPath();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");
    loadStyleSheet(a);
    MainWindow w;
    w.show();

    // Load saved profiles after the UI is ready
    Profile::loadProfiles(&w);

    // Create User object
    User user(&w);


    return a.exec();
}
