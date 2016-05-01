#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include <QTextBlock>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // remove admin panel tab
    ui->tabs->removeTab(4);
    // remove customer info tab
    ui->tabs->removeTab(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInButton_clicked()
{
    // 0 = guest acces level
    if(db.checkLogin(ui->lineEdit->text(), ui->lineEdit_2->text()) == 0)
    {
        qDebug() << "Guest access level detected.";
    }
    // 1 = customer acces level
    else if(db.checkLogin(ui->lineEdit->text(), ui->lineEdit_2->text()) == 1)
    {
        qDebug() << "Customer access level detected.";
        // remove customer login tab
        ui->tabs->removeTab(2);
        // add customer info tab
        ui->tabs->addTab(ui->myAccount2, "My Account");
        // set as active tab
        ui->tabs->setCurrentIndex(2);
    }
    // 2 = admin acces level
    else if(db.checkLogin(ui->lineEdit->text(), ui->lineEdit_2->text()) == 2)
    {
        qDebug() << "Admin access level detected.";
        // remove customer login tab
        ui->tabs->removeTab(2);
        // add customer info tab
        ui->tabs->addTab(ui->myAccount2, "My Account");
        // set as active tab
        ui->tabs->setCurrentIndex(2);
        // add admin panel tab
        ui->tabs->addTab(ui->adminPanel, "Admin Panel");
    }
}
