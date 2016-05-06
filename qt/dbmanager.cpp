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

bool dbManager::addPerson(const QString &fullName, const QString &userName, const QString &pWord, const QString &company, const QString &street, const QString &city, const QString &state, const QString &zip)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO users (name, username, password, access, company, street, city, state, zip)"
                  "VALUES (:fullName, :userName, :pWord, 1, :company, :street, :city, :state, :zip)");
    query.bindValue(":fullName", fullName);
    query.bindValue(":userName", userName);
    query.bindValue(":pWord", pWord);
    query.bindValue(":company", company);
    query.bindValue(":street", street);
    query.bindValue(":city", city);
    query.bindValue(":state", state);
    query.bindValue(":zip", zip);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "It no work!" << query.lastError();
    }
    return success;

}

QString dbManager::retrieveCustomerName(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString customerName = query.value(0).toString();
            return customerName;
        }
    }

    return "NO.CUSTOMER.NAME.FOUND";
}

QString dbManager::retrieveCustomerUsername(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString customerUsername = query.value(0).toString();
            return customerUsername;
        }
    }

    return "NO.CUSTOMER.USERNAME.FOUND";
}

QString dbManager::retrieveCustomerCompany(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT company FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString customerCompany = query.value(0).toString();
            return customerCompany;
        }
    }

    return "NO.CUSTOMER.COMPANY.FOUND";
}

QString dbManager::retrieveCustomerStreet(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT street FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString customerStreet = query.value(0).toString();
            return customerStreet;
        }
    }

    return "NO.CUSTOMER.STREET.FOUND";
}

QString dbManager::retrieveCustomerCity(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT city FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString customerCity = query.value(0).toString();
            return customerCity;
        }
    }

    return "NO.CUSTOMER.CITY.FOUND";
}

QString dbManager::retrieveCustomerState(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT state FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString customerState = query.value(0).toString();
            return customerState;
        }
    }

    return "NO.CUSTOMER.STATE.FOUND";
}

QString dbManager::retrieveCustomerZip(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT zip FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString customerZip = query.value(0).toString();
            return customerZip;
        }
    }

    return "NO.CUSTOMER.ZIP.FOUND";
}
