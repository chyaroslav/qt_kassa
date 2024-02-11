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
void utils::dbConnect(const QString& username, const QString& password){
    try {
    db = QSqlDatabase::addDatabase("QOCI");
    db.setHostName(parameters["dbHost"]);
    db.setDatabaseName(parameters["dbName"]);
    db.setUserName(username);
    db.setPassword(password);
    db.open();
    }
    catch (const std::exception& e)
    {
    qDebug() << "Произошла ошибка при соединении с БД:" << e.what();
    throw; // Перебросить исключение для немедленного завершения
    }
}
