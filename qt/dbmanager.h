#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <qarraydata.h>

class dbManager
{
public:
    dbManager();
    bool addPerson(const QString& fullName, const QString& userName, const QString& pWord);
    int checkLogin(QString username, QString pword);
    QString retrieveCustomerName(QString username);
    QString retrieveCustomerUsername(QString username);

private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
