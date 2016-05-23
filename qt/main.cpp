#include "mainwindow.h"
#include <QApplication>


/*!
   * \file main.cpp
   * \brief  main
   *
   * This file contains the mainwindow instance
   */

/*!
 * \brief The main
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-image:https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=0ahUKEwiGseym0u7MAhUX6WMKHQ7pCxYQjRwIBw&url=%2Furl%3Fsa%3Di%26rct%3Dj%26q%3D%26esrc%3Ds%26source%3Dimages%26cd%3D%26cad%3Drja%26uact%3D8%26ved%3D0ahUKEwiGseym0u7MAhUX6WMKHQ7pCxYQjRwIBw%26url%3Dhttp%253A%252F%252Fwww.towerfoundation.com%252Frsvp%252Fgold-level-sponsorship%26psig%3DAFQjCNHM8_QpNkbd0YYETyWNOM2CPKwF6g%26ust%3D1464039500496654&psig=AFQjCNHM8_QpNkbd0YYETyWNOM2CPKwF6g&ust=1464039500496654");
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
