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
    //void newAdmin(QString realName, )


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
    QString getState() const;
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
    int licenses; //number of licenses registered
    QString platform;
    bool isKey;
    QString interest;


};

#endif // USER_H
