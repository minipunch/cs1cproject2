#ifndef USER_H
#define USER_H
#include<QString>
#include <QDebug>
/*!
 * \brief The User class
 *
 * This class represents a user, used for transfering data to and from the database in an organized way
 */

class User
{
public:

    //constructor and destructor
    User();

    //User(QString realName);
    ~User();

    //setters unique
    void newAdmin(QString realName,QString uName, QString pWord);
    void newCustomer(QString realName,QString uName, QString pWord,
                     QString company,  QString street, QString city,
                     QString state, int zip, QString interest);


    //setters, generic
    void setId(int id);
    void setRName(QString realName);
    void setUName(QString uName);
    void setpWord(QString pWord);
    void setAccess(int access);
    void setCompany(QString company);
    void setStreet(QString street);
    void setCity(QString city);
    void setState(QString state);
    void setZip(int zip);
    void setProtection(QString protectionLvl);
    void setLicenses(int licenses);
    void setPlatform(QString platform);
    void setKey(bool isKey);
    void setInterest(QString interest);

    //getters
    int getId() const;
    QString getRName() const;
    QString getUName() const;
    QString getpWord() const;
    int getAccess() const;
    QString getCompany() const;
    QString getStreet() const;
    QString getCity() const;
    QString getState() const;
    int getZip() const;
    QString getProtection() const;
    int getLicenses() const;
    QString getPlatform() const;
    bool getKey() const;
    QString getInterest() const;
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
    QString protectionLvl;
    int licenses; //number of licenses registered
    QString platform;
    bool isKey;
    QString interest;


};

#endif // USER_H
