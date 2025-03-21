#include "mainwindow.h"
#include "user.h"

#include <iostream>
#include <string>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    User user;
    user.createProfile("test", 0.5f, 4.3f, 2.3f);

    Profile* p = user.GetProfiles()[0];

    cout << "name: " << p->GetName() << endl;


    return a.exec();
}
