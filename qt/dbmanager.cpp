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


void dbManager::checkLogin(QString username, QString pword)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = (:username) AND password = (:pword)");
    query.bindValue(":username", username);
    query.bindValue(":pword", pword);

    if(query.exec())
    {
        if(query.next())
        {
            qDebug() << "USERNAME FOUND!!";
        }
        else
            qDebug() << "USERNAME NOT FOUND!!";
    }

}

