#include "user.h"

/*!
   * \file user.cpp
   * \brief  Source file for user class methods
   *
   * This file contains all of the definitions of the user class
   */
/*
 * Constructors and destructors
 *
*/
User::User()
{
    id = 0;
    realName = " ";
    uName = " ";
    pWord = " ";
    access = 0;
    company = " ";
    street = " ";
    city = " ";
    state = " ";
    licenses = 0;
    platform = " ";
    isKey = false;
    interest = " ";

}

User::~User()
{

}

//setters unique

void User::newAdmin(QString realName,QString uName, QString pWord)
{
    this->realName = realName;
    this->uName = uName;
    this->pWord = pWord;
    access = 2;\
    company = "Qtπ's Security";
    street = "28000 Marguerite Pkwy";
    city = "Mission Viejo";
    state = "CA";
    zip = 92692;
    protectionLvl = "Platinum";
    licenses = 0;
    platform = "Windows";
    isKey = false;
    interest = "very interested";
}
void User::newCustomer(QString realName, QString uName, QString pWord, QString company,
                       QString street, QString city, QString state, int zip, QString interest)
{
    this->realName = realName;
    this->uName = uName;
    this->pWord = pWord;
    this->company = company;
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->interest = interest;
    access = 1;
    licenses = 0;
    isKey = false;
    protectionLvl = "no protection";
    platform = "n/a";

}

//setters, generic
void User::setId(int id)
{
    this->id = id;
}
void User::setRName(QString realName)
{
    this->realName = realName;
}
void User::setUName(QString uName)
{
    this->uName = uName;
}
void User::setpWord(QString pWord)
{
    this->pWord = pWord;
}
void User::setAccess(int access)
{
    this->access = access;
}
void User::setCompany(QString company)
{
    this->company = company;
}
void User::setStreet(QString street)
{
    this->street = street;
}
void User::setCity(QString city)
{
    this->city = city;
}
void User::setState(QString state)
{
    this->state = state;
}
void User::setZip(int zip)
{
    this->zip = zip;
}
void User::setProtection(QString protectionLvl)
{
    this->protectionLvl = protectionLvl;
}

void User::setLicenses(int licenses)
{
    this->licenses = licenses;
}
void User::setPlatform(QString platform)
{
    this->platform = platform;
}
void User::setKey(bool isKey)
{
    this->isKey = isKey;
}
void User::setInterest(QString interest)
{
    this->interest = interest;
}

//getters
void User::PrintDebug() const
{
    qDebug() << "Id: " << id << endl;
    qDebug() << "Real Name: " << realName << endl;
    qDebug() << "UserName: " << uName << endl;
    qDebug() << "Password: " << pWord << endl;
    qDebug() << "Access Level: " << access << endl;
    qDebug() << "Company: " << company << endl;
    qDebug() << "Street: " << street << endl;
    qDebug() << "City: " << city << endl;
    qDebug() << "State: " << state << endl;
    qDebug() << "Num Licenses: " << licenses << endl;
    qDebug() << "Platform: " << platform << endl;
    qDebug() << "Key: " << isKey << endl;
    qDebug() << "Interest" << interest << endl;

}
int User::getId() const
{
    return id;
}
QString User::getUName() const
{
    return uName;
}
QString User::getRName() const
{
    return realName;
}
QString User::getpWord() const
{
    return pWord;
}
int User::getAccess() const
{
    return access;
}
QString User::getCompany() const
{
    return company;
}
QString User::getStreet() const
{
    return street;
}
QString User::getCity() const
{
    return city;
}
QString User::getState() const
{
    return state;
}
int User::getZip() const
{
    return zip;
}
QString User::getProtection() const
{
    return protectionLvl;
}
int User::getLicenses() const
{
    return licenses;
}
QString User::getPlatform() const
{
    return platform;
}
bool User::getKey() const
{
    return isKey;
}
QString User::getInterest() const
{
    return interest;
}
