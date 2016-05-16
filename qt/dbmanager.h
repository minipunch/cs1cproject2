#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <qarraydata.h>
#include "user.h"
#include <QVector>
/*!
   * \file dbmanager.h
   * \brief  Header for database wrapper class
   *
   * This file contains all of the declarations of the dbmanager class
   */
/*!
 * \brief The dbManager database wrapper class
 *
 * This class interfaces the sql database with the rest of the program
 */
class dbManager
{
public:
    /*!
     * \brief Constructor
     */
    dbManager();
    /*!
     * \brief MUTATOR: addPerson
     * \param toAdd User object transfering the data needed
     *
     * THis method brings in a user class to be added to the database
     * \return the result of the adding
     */
    bool addPerson(User toAdd);
    /*!
     * \brief verifies user's input and tries to log them in
     * \param username Username input
     * \param pword Password input
     * \return User's new access level(for use in mainwindow)
     */
    int checkLogin(QString username, QString pword);
    /*!
     * \brief ACCESSOR: retrieves real name
     * \param username(used to find the right user in the database)
     * \return User's real name
     */
    QString retrieveCustomerName(QString username);
    /*!
     * \brief ACCESSOR: retrieves username
     * \param username(used to find the right user in the database)
     * \return User's username
     */
    QString retrieveCustomerUsername(QString username);
    /*!
     * \brief ACCESSOR: retrieves company
     * \param username(used to find the right user in the database)
     * \return User's company
     */
    QString retrieveCustomerCompany(QString username);
    /*!
     * \brief ACCESSOR: retrieves street
     * \param username(used to find the right user in the database)
     * \return User's street
     */
    QString retrieveCustomerStreet(QString username);
    /*!
     * \brief ACCESSOR: retrieves city
     * \param username(used to find the right user in the database)
     * \return User's City
     */
    QString retrieveCustomerCity(QString username);
    /*!
     * \brief ACCESSOR: retrieves state
     * \param username(used to find the right user in the database)
     * \return User's state
     */
    QString retrieveCustomerState(QString username);
    /*!
     * \brief ACCESSOR: retrieves zip code
     * \param username(used to find the right user in the database)
     * \return User's zip code
     */
    QString retrieveCustomerZip(QString username);
    /*!
     * \brief ACCESSOR: retrieves protection level
     * \param username(used to find the right user in the database)
     * \return User's protection level
     */
    QString retrieveCustomerLevel(QString username);
    /*!
     * \brief ACCESSOR: retrieve number of licenses
     * \param username(used to find the right user in the database)
     * \return User's license count
     */
    QString retrieveCustomerLiscenses(QString username);
    /*!
     * \brief ACCESSOR: retrieves platform
     * \param username(used to find the right user in the database)
     * \return User's platform
     */
    QString retrieveCustomerPlatform(QString username);
    /*!
     * \brief ACCESSOR: retrieve whether or not customer is key
     * \param username(used to find the right user in the database)
     * \return Whether or not user is "key"
     */
    QString retrieveCustomerKey(QString username);
    /*!
     * \brief ACCESSOR: retrieves interest level
     * \param username(used to find the right user in the database)
     * \return User's interest level
     */
    QString retrieveCustomerInterest(QString username);
    /*!
     * \brief ACCESSOR: Gets lists of customer usernames for use in mainwindow
     *
     * Used for filling the tables, this method fills a QVector or usernames based on the parameter passed in
     * Mainwindow can then utilize the utility accessor methods of this class to get the remaining info to fill the table.
     * \param parameter determines which usernames are added to the list
     * \return List of username
     */
    QVector<QString> getUserNames(int parameter);
    /*!
     * \brief MUTATOR: Method for updating a user's account after a purchase
     *
     * Updates the appropriate fields in the database if the user buys a subscription.
     * \param username (used to find the right user in the database)
     * \param platform New platform
     * \param level  New protection level
     * \param quantity New quantity of licenses
     * \return result of the transaction(pass or fail)
     */
    bool BuyProducts(QString username, QString platform, QString level, QString quantity);
    /*!
     * \brief MUTATOR: Updates major info for all users
     *
     * Allows a user to modify most fields for their account.
     * Other fields can only be changed by buying a subscription or having values like key updated by an admin
     * \param username1 Original username (used to find the right user in the database)
     * \param username2 New Username
     * \param name  New real name
     * \param street New street
     * \param state New state
     * \param city New City
     * \param zip New zip code
     * \return result of the update(pass or fail)
     */
    bool UpdateInfo(QString username1, QString username2, QString name, QString street, QString state, QString city, QString zip);
    /*!
     * \brief Admin update for users
     *
     * This method allows the user to update a users key and interest levels from the table
     * \param username User being updated
     * \param interest New interest level
     * \param isKey   New Key level
     * \return success of operation
     */
    bool Update2(QString username, QString interest, QString isKey);

private:
    QSqlDatabase db; //the database
};

#endif // DBMANAGER_H
