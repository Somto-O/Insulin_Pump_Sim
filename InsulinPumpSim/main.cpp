#include "mainwindow.h"
#include "user.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    User user;

    // when option button is pressed, it calls navigate profiles
    user.navigateProfiles();

    /*Profile* p = user.GetProfiles()[0];

    cout << "name: " << p->GetName() << endl;*/


    return a.exec();
}
