#include "dbmanager.h"

dbManager::dbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../cybersecurity.db");

    if(!db.open())
        qDebug() << "Not connected to DB.";
    else if(db.open())
        qDebug() << "Connected to DB.";
}

/* RETURN VALUES:
 * 0 = GUEST
 * 1 = CUSTOMER
 * 2 = ADMIN
*/
int dbManager::checkLogin(QString username, QString pword)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = (:username) AND password = (:pword) AND access = 1");
    query.bindValue(":username", username);
    query.bindValue(":pword", pword);

    //makes sure the the query is executed
    if(query.exec())
    {
        //returns data that matches the query with access level 1
        if(query.next())
        {
            return 1;
            qDebug() << "USERNAME FOUND LEVEL 1!!";
        }
        else
        {
            qDebug() << "USERNAME NOT FOUND LEVEL 1!!";
        }
    }

    QSqlQuery query2;
    query2.prepare("SELECT username FROM users WHERE username = (:username) AND password = (:pword) AND access = 2");
    query2.bindValue(":username", username);
    query2.bindValue(":pword", pword);

    //makes sure the the query is executed
    if(query2.exec())
    {
        //grabs something that matches the query with access level 2
        if(query2.next())
        {
            return 2;
            qDebug() << "USERNAME FOUND LEVEL 2!!";
        }
        else
        {
            return 0;
            qDebug() << "USERNAME NOT FOUND LEVEL 2!!";
        }
    }

}

QString dbManager::retrieveCustomerName(QString username)
{
    QSqlQuery query("SELECT name FROM users WHERE username = '" + username + "'");

    while(query.next())
    {
        QString customerName = query.value(0).toString();
        return customerName;
    }

    return "NO.CUSTOMER.INFO.FOUND";
}

QString dbManager::retrieveCustomerUsername(QString username)
{
    QSqlQuery query("SELECT username FROM users WHERE username = '" + username + "'");

    while(query.next())
    {
        QString customerUsername = query.value(0).toString();
        return customerUsername;
    }

    return "NO.CUSTOMER.INFO.FOUND";
}

