#include "dbmanager.h"

dbManager::dbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../cybersecurity.db");

    // never fails to connect. idk why.
    if(!db.open())
        qDebug() << "Not connected to DB.";
    else if(db.open())
        qDebug() << "Connected to DB.";
}

bool dbManager::addPerson(const QString& name)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO users (name) VALUES (:name)");
   //bind what is passed in to the attribute of the object in database
   query.bindValue(":name", name);
   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  "
                 << query.lastError();
   }

   return success;
}


int dbManager::checkLogin(QString username, QString pword)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = (:username) AND password = (:pword) AND access = 1");
    query.bindValue(":username", username);
    query.bindValue(":pword", pword);

    //makes sure the the query is executed
    if(query.exec())
    {
        //grabs something that matches the query with access level 1
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

