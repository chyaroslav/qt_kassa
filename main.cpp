#include "loginwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include "utils.h"

const QString parfile="params.ini";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //utils utl(parfile);
    utils::readParams(parfile);
    MainWindow w;
    w.setWindowTitle("Кассовое место");
    LoginWindow lw(&w);
    lw.setWindowTitle("Соединение с БД");
    w.show();
    lw.exec();

    return a.exec();
}
