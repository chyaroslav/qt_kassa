#include "loginwindow.h"
#include "ui_loginwindow.h"


LoginWindow::LoginWindow(QMainWindow* mainWindow) :
     QDialog(mainWindow), mainWindow(mainWindow), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButtonBox_accepted()
{
    const QString uSql="select наименование from организации t where t.username=upper(:username)";
    utils::dbChangeUser(ui->usernameLineEdit->text(),ui->passwordLineEdit->text());
    QSqlDatabase& db = utils::dbInstance();
    if (db.open()) {
        QSqlQuery query(db);

        // Выполнение запроса к БД Oracle
        query.prepare(uSql);
        query.bindValue(":usrname", ui->usernameLineEdit->text());
        if (query.exec()) {
            mainWindow->setWindowTitle("Кассир:"+query.value(0).toString());
            }
        }

        db.close();
    }

