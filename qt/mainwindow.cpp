#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include <QTextBlock>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isUserLoggedIn = false;
    // remove admin panel tab
    ui->tabs->removeTab(4);
    // remove customer info tab
    ui->tabs->removeTab(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// sign in button
void MainWindow::on_signInButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString pword = ui->lineEdit_2->text();

    // 0 = guest acces level
    if(db.checkLogin(username, pword) == 0)
    {
        qDebug() << "Guest access level detected.";
    }
    // 1 = customer acces level
    else if(db.checkLogin(username, pword) == 1)
    {
        isUserLoggedIn = true;
        currentUserAccessLevel = 1;
        qDebug() << "Customer access level detected.";
        // remove customer login tab
        ui->tabs->removeTab(2);
        // add customer info tab
        ui->tabs->addTab(ui->myAccount2, "My Account");
        // set as active tab
        ui->tabs->setCurrentIndex(2);
        // set label info
        ui->nameLabel->setText(db.retrieveCustomerName(username));
        ui->usernameLabel->setText(db.retrieveCustomerUsername(username));
    }
    // 2 = admin acces level
    else if(db.checkLogin(username, pword) == 2)
    {
        isUserLoggedIn = true;
        currentUserAccessLevel = 2;
        qDebug() << "Admin access level detected.";
        // remove customer login tab
        ui->tabs->removeTab(2);
        // add customer info tab
        ui->tabs->addTab(ui->myAccount2, "My Account");
        // set as active tab
        ui->tabs->setCurrentIndex(2);
        // add admin panel tab
        ui->tabs->addTab(ui->adminPanel, "Admin Panel");
        // set label info
        ui->nameLabel->setText(db.retrieveCustomerName(username));
        ui->usernameLabel->setText(db.retrieveCustomerUsername(username));
    }
}

void MainWindow::on_signOutButton_clicked()
{
    if(currentUserAccessLevel == 2)
    {
        ui->tabs->removeTab(2);
        ui->tabs->removeTab(2);
        ui->tabs->addTab(ui->myAccount, "My Account");
        isUserLoggedIn = false;
        currentUserAccessLevel = 0;
    }
    if(currentUserAccessLevel == 1)
    {
        ui->tabs->removeTab(2);
        ui->tabs->addTab(ui->myAccount, "My Account");
        isUserLoggedIn = false;
        currentUserAccessLevel = 0;
    }
}
