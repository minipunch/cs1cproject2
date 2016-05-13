#include "mainwindow.h"
#include <QApplication>


/*!
   * \file main.cpp
   * \brief  main
   *
   * This file contains the mainwindow instance
   */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
/**
\mainpage Qtπs Cyber Security Documentation

Qtπs Cyber Security - Making your security great again.

Our mock cyber security website built to advertise a internet security product.
Built for CS1C group project number 2 at saddleback college, spring 2016.

Tools and languages used:
- Qt creator: C++ implementation, ui design, database interfacing
- SqliteStudio: Sql database creation and management
- Doxygen - HTML Documentation(What you see now)
- Dia - UML Diagram
- Waffle IO and Github - keeping track of everything

Additional information and source code found here: https://github.com/minipunch/cs1cproject2

Team Qtπs members:
- Ashly Hernandez
- Dallas Wendt
- Dustin Vuong
- Josh Yolles
- Nick Sidaris


© 2016 Team Qtπs. All Rights Reserved.
*/
