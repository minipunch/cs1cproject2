#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <qarraydata.h>
#include "user.h"
#include <QVector>

class dbManager
{
public:
    dbManager();
    bool addPerson(User toAdd);
    int checkLogin(QString username, QString pword);
    QString retrieveCustomerName(QString username);
    QString retrieveCustomerUsername(QString username);
    QString retrieveCustomerCompany(QString username);
    QString retrieveCustomerStreet(QString username);
    QString retrieveCustomerCity(QString username);
    QString retrieveCustomerState(QString username);
    QString retrieveCustomerZip(QString username);
    QString retrieveCustomerLevel(QString username);
    QString retrieveCustomerLiscenses(QString username);
    QString retrieveCustomerPlatform(QString username);
    QString retrieveCustomerKey(QString username);
    QString retrieveCustomerInterest(QString username);
    QVector<QString> getUserNames(int parameter);
    bool BuyProducts(QString username, QString platform, QString level, QString quantity);

private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
