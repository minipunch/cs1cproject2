#include "admin.h"

Admin::Admin()
{
    hiredate = new Date;
}
void Admin::setDate(Date *hiredate)
{
    this->hiredate = hiredate;
}
Date *Admin::getdate() const
{
    return hiredate;
}
 bool operator == (Admin & a1, Admin & a2)
 {
    return(a1.hiredate == a2.hiredate);
 }

/*!
 * \file admin.cpp
 * \brief  Source file for admin class
 *
 * This file contains all of the definitions of the admin class
 */
