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

bool dbManager::addPerson(User toAdd)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO users (name, username, password, access, company, street, city, state, zip, protectionlvl, licenses, platform, key, interestLvl)"
                  "VALUES (:fullName, :userName, :pWord, :access, :company, :street, :city, :state, :zip, :proLvl, :license, :platform, :key, :interest)");

    query.bindValue(":fullName", toAdd.getRName());
    query.bindValue(":userName", toAdd.getUName());
    query.bindValue(":pWord", toAdd.getpWord());
    query.bindValue(":access", toAdd.getAccess());
    query.bindValue(":company", toAdd.getCompany());
    query.bindValue(":street", toAdd.getStreet());
    query.bindValue(":city", toAdd.getCity());
    query.bindValue(":state", toAdd.getState());
    query.bindValue(":zip", toAdd.getZip());
    query.bindValue(":proLvl", toAdd.getProtection());
    query.bindValue(":license", toAdd.getLicenses());
    query.bindValue(":platform", toAdd.getPlatform());
    query.bindValue(":key", toAdd.getKey());
    query.bindValue(":interest", toAdd.getInterest());

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
            QString protection = query.value(0).toString();
            return protection;
        }
    }

    return "NO.CUSTOMER.PROTECTION.LEVEL.FOUND";
}

QString dbManager::retrieveCustomerLevel(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT protectionlvl FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString protection = query.value(0).toString();
            if(protection == NULL)
            {
                protection = "N/A";
            }

            return protection;
        }
    }

    return "NO.CUSTOMER.PROTECTION.LEVEL.FOUND";
}

QString dbManager::retrieveCustomerLiscenses(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT licenses FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString licenses = query.value(0).toString();

            if(licenses == NULL)
            {
                licenses = "0";
            }

            return licenses;
        }
    }

    return "NO.CUSTOMER.LISCENSES.FOUND";
}

QString dbManager::retrieveCustomerPlatform(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT platform FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString platform = query.value(0).toString();
            if(platform == NULL)
            {
                platform = "N/A";
            }
            return platform;
        }
    }

    return "NO.CUSTOMER.PLATFORM.FOUND";
}

QString dbManager::retrieveCustomerKey(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT key FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString platform = query.value(0).toString();
            if(platform == "0")
            {
                platform = "No";
            }
            else
            {
                platform = "Yes";
            }
            return platform;
        }
    }

    return "NO.CUSTOMER.PLATFORM.FOUND";
}

QString dbManager::retrieveCustomerInterest(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT interestLvl FROM users WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
    {
        if(query.next())
        {
            QString interest = query.value(0).toString();
            return interest;
        }
    }

    return "NO.CUSTOMER.INTEREST.FOUND";
}


QVector<QString> dbManager::getUserNames(int parameter)
{

    QSqlQuery query;
    QVector<QString> names;
    //show only customers
    //more parameters can be added as needed
    if(parameter == 1)
    {
        query.prepare("SELECT username FROM users WHERE access = 1");

        if(query.exec())
        {
            while(query.next())
            {
                names.push_back(query.value(0).toString());
            }
        }
       for(int i = 0; i < names.size(); i++)
       {
           qDebug() << names.at(i) << endl;
       }
    }
    else if(parameter == 2)
    {
        query.prepare("SELECT username FROM users WHERE access = 2");

        if(query.exec())
        {
            while(query.next())
            {
                names.push_back(query.value(0).toString());
            }
        }
    }
    else if(parameter == 3)
    {
        query.prepare("SELECT username FROM users WHERE key = 1");

        if(query.exec())
        {
            while(query.next())
            {
                names.push_back(query.value(0).toString());
            }
        }
    }

    return names;
}
