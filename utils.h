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
    static void dbConnect(const QString& username, const QString& password);
    static QMap<QString,QString> parameters;

private:
    static QSqlDatabase db;
};

#endif // UTILS_H
