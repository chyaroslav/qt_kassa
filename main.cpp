#include "loginwindow.h"
#include "mainwindow.h"
#include "utils.h"
#include <QApplication>

const QString parfile="params.ini";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    utils utl(parfile);
    LoginWindow lw;
    lw.show();
    MainWindow w;
    w.show();
    return a.exec();
}
