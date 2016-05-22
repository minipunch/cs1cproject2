#ifndef ADMIN_H
#define ADMIN_H

#include "date.h"
#include "user.h"

/*!
 * \file admin.h
 * \brief  Header for admin class
 *
 * This file contains all of the declarations of the admin class
 */

/*!
 * \brief Represents an admin
 *
 * Keeps track of the hire date
 */
class Admin : public User
{
public:
    /*!
     * \brief Constructor
     */
    Admin();
    /*!
     * \brief Destructor
     */
    ~Admin(){}
    /*!
     * \brief gets the hire date
     * \return the hire date
     */
    Date *getdate() const;
    /*!
     * \brief sets hire date
     * \param hiredate new hiredate
     */
    void setDate(Date* hiredate);



    /*!
     * \brief Prints admins hire date to console
     */
    void virtual PrintDebug()
    {
       qDebug() << QString::fromStdString( hiredate->DisplayDate());

    }
    /*!
     * \brief Sees if 2 admins were hired on the same day
     * \param a1 First admin
     * \param a2 Second admin
     * \return result
     */
    friend bool operator == (Admin & a1, Admin & a2);

private:
    Date *hiredate;
};

#endif // ADMIN_H
