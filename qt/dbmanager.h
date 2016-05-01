#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

class dbManager
{
public:
    dbManager();
    bool addPerson(const QString& name);
    int checkLogin(QString username, QString pword);

private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
