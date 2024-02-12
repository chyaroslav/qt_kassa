#ifndef UTILS_H
#define UTILS_H

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMap>
#include <QtSql/QSqlDatabase>

class utils
{
public:
    static void readParams(const QString& filePath);
    static QSqlDatabase& dbInstance();
    static void dbChangeUser(const QString& username, const QString& password);

private:
    static QSqlDatabase db;
    static QString username;
    static QString password;
    static QMap<QString,QString> parameters;
};

#endif // UTILS_H
