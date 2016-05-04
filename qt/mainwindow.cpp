#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"

#include<QMessageBox>

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
    QString username = ui->lineEdit->text().simplified();
    QString pword = ui->lineEdit_2->text().simplified();
    try
    {
        Login(username, pword);
    }catch(...)
    {
        //temp message
        //this should change to be a label that displays on screen
        QMessageBox::information(this, tr("Invalid!"),
                                 "Invalid username or password, please try again.");
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
    //clear out the line edits
    ui->Indicator->setText("Guest");
    ui->lineEdit_2->clear();
    ui->lineEdit->clear();
    ui->FNameEdit->clear();
    ui->PwordEdit->clear();
    ui->UNameEdit->clear();
    ui->pWordToggle->setChecked(false);
    ui->pWordToggle2->setChecked(false);


}



void MainWindow::on_CreatAcct_clicked()
{
    QString name = ui->FNameEdit->text().simplified();

    QString uName= ui->UNameEdit->text().simplified();

    QString pWord = ui->PwordEdit->text().simplified();


    ui->PwordEdit->setEchoMode(QLineEdit::Password);

    if(db.addPerson(name, uName, pWord))
    {

        Login(uName, pWord);
    }
    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 "Username is taken, pick another .");
    }



}

void MainWindow::on_pWordToggle_toggled(bool checked)
{
    if(checked)
    {
        ui->PwordEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->PwordEdit->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_pWordToggle2_toggled(bool checked)
{
    if(checked)
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::Login(const QString& username, const QString& pword)
{
    // 0 = guest acces level
    if(db.checkLogin(username, pword) == 0)
    {
        throw 0;
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
        ui->Indicator->setText(db.retrieveCustomerName(username));
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
        ui->Indicator->setText(db.retrieveCustomerName(username));
        ui->usernameLabel->setText(db.retrieveCustomerUsername(username));
    }

}
