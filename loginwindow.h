#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include "utils.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QMainWindow* mainWindow);
    ~LoginWindow();

private slots:
    void on_loginButtonBox_accepted();

private:
    Ui::LoginWindow *ui;
    QMainWindow* mainWindow;
};

#endif // LOGINWINDOW_H
