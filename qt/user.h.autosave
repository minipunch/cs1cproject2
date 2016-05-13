#ifndef USER_H
#define USER_H
#include<QString>
#include <QDebug>

/*!
   * \file user.h
   * \brief  Header for user class(See user class for details)
   *
   * This file contains all of the declarations of the date class
   * (See user class for full details)
   */

/*!
 * \brief The User class
 *
 * This class represents a user, used for transfering data to and from the database in an organized way.
 * It keeps track of a user's real name, username, password, what company they represent, their companies address(street, city, zip etc.)
 * as well as information regarding what their current subscription service is.
 */

class User
{
public:

    //constructor and destructor
    /*!
     * \brief Constructor
     */
    User();

    //User(QString realName);

    /*!
     * \brief Destructor
     */
    ~User();

    //setters unique----------------------------------------------
    /*!
     * \brief MUTATOR: Short cut method for creating a new admin account
     *
     * This is a shortcut method for making a new admin account,
     * it allows the user to create their own username, password a
     * nd enter their display name,but initializes other attributes to default values
     * \param realName The user's real name
     * \param uName The user's desired username
     * \param pWord The user's desired password
     */
    void newAdmin(QString realName,QString uName, QString pWord);
    /*!
     * \brief MUTATOR: Shortcut method for creating a new customer account
     *
     * Shortcut method used when a user creates a new account for themselves
     * Allows them to set almost all fields. Other fields are set to default
     * values until the user buys a service package and/or and admin modifies
     * their interest/key value(s).
     * \param realName User's real name
     * \param uName User's desired username
     * \param pWord User's desired password
     * \param company Company that the user represents
     * \param street Street and number of the address
     * \param city City location of the company
     * \param state State where the company is
     * \param zip Zip code of company's location
     * \param interest User's interest in the product
     */
    void newCustomer(QString realName,QString uName, QString pWord,
                     QString company,  QString street, QString city,
                     QString state, int zip, QString interest);


    //setters, generic-----------------------------
    /*!
     * \brief MUTATOR: sets a user's id
     * \param id New id
     */
    void setId(int id);
    /*!
     * \brief MUTATOR: Sets user's real name
     * \param realName New real name
     */
    void setRName(QString realName);
    /*!
     * \brief MUTATOR: Sets user's username
     * \param uName New username
     */
    void setUName(QString uName);
    /*!
     * \brief MUTATOR: Sets user's password
     * \param pWord New password
     */
    void setpWord(QString pWord);
    /*!
     * \brief MUTATOR: Sets a user's access level (admin or customer)
     * \param access New access level
     */
    void setAccess(int access);
    /*!
     * \brief MUTATOR: Sets a user's company name
     * \param company New company name
     */
    void setCompany(QString company);
    /*!
     * \brief MUTATOR: Sets user's street
     * \param street New street
     */
    void setStreet(QString street);
    /*!
     * \brief MUTATOR: Sets a user's city
     * \param city New City
     */
    void setCity(QString city);
    /*!
     * \brief MUTATOR: Sets a user's state(abbreviated)
     * \param state New state
     */
    void setState(QString state);
    /*!
     * \brief MUTATOR: Sets a user's zip code
     * \param zip New zip code
     */
    void setZip(int zip);
    /*!
     * \brief MUTATOR: Sets a user's protection level(Plat, gold, silver, bronze)
     * \param protectionLvl New protection level
     */
    void setProtection(QString protectionLvl);
    /*!
     * \brief MUTATOR: Sets a user's number of registered licenses
     * \param licenses New licenses count
     */
    void setLicenses(int licenses);
    /*!
     * \brief MUTATOR: Sets a user's registered platform(Windows, Mac, Linux)
     * \param platform New platform
     */
    void setPlatform(QString platform);
    /*!
     * \brief MUTATOR: Set's whether or not a client is "key" to Qtπ's security
     * \param isKey New key value
     */
    void setKey(bool isKey);
    /*!
     * \brief MUTATOR: Sets the user's interest level
     * \param interest New interest level
     */
    void setInterest(QString interest);

    //getters--------------------------------------
    /*!
     * \brief ACCESSOR: Gets a user's id number
     * \return User's id number
     */
    int getId() const;
    /*!
     * \brief ACCESSOR: Gets a user's real name
     * \return User's real name
     */
    QString getRName() const;
    /*!
     * \brief ACCESSOR: Gets a user's username
     * \return User's username
     */
    QString getUName() const;
    /*!
     * \brief ACCESSOR: Gets a user's password
     * \return User's password
     */
    QString getpWord() const;
    /*!
     * \brief ACCESSOR: Gets a user's access level(customer or admin)
     * \return User's access level
     */
    int getAccess() const;
    /*!
     * \brief ACCESSOR: Gets a user's company
     * \return User's company
     */
    QString getCompany() const;
    /*!
     * \brief ACCESSOR: Gets a user's street
     * \return User's street
     */
    QString getStreet() const;
    /*!
     * \brief ACCESSOR: Gets a user's city
     * \return User's city
     */
    QString getCity() const;
    /*!
     * \brief ACCESSOR: Gets a user's state
     * \return User's state
     */
    QString getState() const;
    /*!
     * \brief ACCESSOR: Gets a user's zip code
     * \return User's zip code
     */
    int getZip() const;
    /*!
     * \brief ACCESSOR: Gets a user's protection level(Platinum, Gold, Silver, Bronze)
     * \return User's protection level
     */
    QString getProtection() const;
    /*!
     * \brief ACCESSOR: Gets a user's number of licenses
     * \return User's registered license count
     */
    int getLicenses() const;
    /*!
     * \brief ACCESSOR: Gets a user's platform(windows, mac, linux)
     * \return User's platform
     */
    QString getPlatform() const;
    /*!
     * \brief ACCESSOR: Gets a user's "key" value
     * \return Whether or not the account is key to Qtπ's security
     */
    bool getKey() const;
    /*!
     * \brief ACCESSOR:Gets a user's interest level
     * \return User's interest level
     */
    QString getInterest() const;
    /*!
     * \brief ACCESSOR: Prints a user to the console
     *
     * Prints all attributes to the console using qDebug for debugging
     */
    void PrintDebug() const;

private:
    int id;
    QString realName;
    QString uName;
    QString pWord;
    int access;
    QString company;
    QString street;
    QString city;
    QString state;
    int zip;
    QString protectionLvl; //protection level(Platinum, Gold, Silver, Bronze)
    int licenses; //number of licenses registered
    QString platform; //platform of that the user registered their product on
    bool isKey;
    QString interest;


};

#endif // USER_H
