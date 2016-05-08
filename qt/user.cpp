#include "user.h"
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
//setters
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
QString User::getState() const
{
    return state;
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
