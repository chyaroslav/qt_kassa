#include "utils.h"
#include <QDebug>

void utils::readParams(const QString& filePath) {
    QFile file(filePath);
    try {
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty() && !line.startsWith("#")) // Пропускаем пустые строки и комментарии
            {
                QStringList parts = line.split("="); // Разделяем строку на ключ и значение

                // Проверяем формат строки "ключ=значение"
                if (parts.length() == 2)
                {
                    QString key = parts[0].trimmed();
                    QString value = parts[1].trimmed();
                    parameters[key] = value;
                }
                else
                {
                    // Обработка некорректного формата строки
                    qDebug() << "Неверный формат файла параметров";
                    exit(1);
                }
            }
        }
        file.close();
    }
    }
    catch (const std::exception& e)
    {
    qDebug() << "Произошла ошибка:" << e.what();
    throw; // Перебросить исключение для немедленного завершения
    }
}
void utils::dbChangeUser(const QString& un, const QString& pw){

    username=un;
    password=pw;
    //Удалить текущее подключение
    db = QSqlDatabase();
}
QSqlDatabase& utils::dbInstance()
{
    if (!db.isValid())
    {
    // Здесь выполняется создание и конфигурация объекта QSqlDatabase
    // на основе параметров подключения, хранящихся в переменных класса
    try {
        db.setHostName(parameters["dbHost"]);
        db.setDatabaseName(parameters["dbName"]);
        db.setUserName(username);
        db.setPassword(password);
        }
    catch (const std::exception& e)
        {
    qDebug() << "Произошла ошибка при соединении с БД:" << e.what();
    throw; // Перебросить исключение для немедленного завершения
        }
    }
    return db;
}
