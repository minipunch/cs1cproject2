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
    bool addPerson(const QString &fullName, const QString &userName, const QString &pWord, const QString &company, const QString &street, const QString &city, const QString &state, const QString &zip);
    int checkLogin(QString username, QString pword);
    QString retrieveCustomerName(QString username);
    QString retrieveCustomerUsername(QString username);
    QString retrieveCustomerCompany(QString username);
    QString retrieveCustomerStreet(QString username);
    QString retrieveCustomerCity(QString username);
    QString retrieveCustomerState(QString username);
    QString retrieveCustomerZip(QString username);
    QSqlDatabase getDB();
private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
