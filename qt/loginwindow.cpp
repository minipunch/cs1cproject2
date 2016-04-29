#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);



}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_buttonBox_accepted()
{
    bool valid = false;


        username = ui->name->text();
        password = ui->password->text();

        //Check to see if valid

        if(username.isEmpty() || password.isEmpty())
        {
            QMessageBox::information(this, tr("Invalid Input"),
               "Please enter valid username or password");
        }
        else
        {
            //Check the list to make sure input is valid
            //Set valid to true

            LoginInput(username, password);
        }





}
