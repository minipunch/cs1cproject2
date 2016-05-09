#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include <QVector>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Inserting Picture
    QPixmap burglar("M:/Pictures/Saved Pictures/sneaker.png");
    ui->picturelabel->setPixmap(burglar);

    isUserLoggedIn = false;
    // remove admin panel tab
    ui->tabs->removeTab(4);
    // remove customer info tab
    ui->tabs->removeTab(3);

    // set up columns/rows for admin panel table
    for(int x = 0; x < 10; x++)
    {
        ui->CustomersTable->insertColumn(x);
        ui->CustomersTable->insertRow(x);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCustomerLabelInfo(QString customerUsername)
{
    // set label info
    ui->nameLabel->setText(db.retrieveCustomerName(customerUsername));
    ui->Indicator->setText(db.retrieveCustomerName(customerUsername));
    ui->usernameLabel->setText(db.retrieveCustomerUsername(customerUsername));
    ui->companyLabel->setText(db.retrieveCustomerCompany(customerUsername));
    ui->streetLabel->setText(db.retrieveCustomerStreet(customerUsername));
    ui->cityLabel->setText(db.retrieveCustomerCity(customerUsername));
    ui->stateLabel->setText(db.retrieveCustomerState(customerUsername));
    ui->zipLabel->setText(db.retrieveCustomerZip(customerUsername));
}

void MainWindow::setCustomerLoginTabs(int customerAccessLevel)
{
    if(customerAccessLevel == 1)
    {
        // remove customer login tab
        ui->tabs->removeTab(2);
        // add customer info tab
        ui->tabs->addTab(ui->myAccount2, "My Account");
        // set as active tab
        ui->tabs->setCurrentIndex(2);
    }
    else if(customerAccessLevel == 2)
    {
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

// sign in button
void MainWindow::on_signInButton_clicked()
{
    QString username = ui->lineEdit->text().simplified();
    QString pword = ui->lineEdit_2->text().simplified();

    if(username.isEmpty() || pword.isEmpty())
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 "Please fill both fields");
    }
    else
    {
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



}

void MainWindow::on_signOutButton_clicked()
{
    if(currentUserAccessLevel == 2)
    {
        ui->tabs->removeTab(2);
        ui->tabs->removeTab(2);
        ui->tabs->addTab(ui->myAccount, "My Account");
        // set as myAccount tab as active
        ui->tabs->setCurrentIndex(2);
        isUserLoggedIn = false;
        currentUserAccessLevel = 0;
    }
    if(currentUserAccessLevel == 1)
    {
        ui->tabs->removeTab(2);
        ui->tabs->addTab(ui->myAccount, "My Account");
        // set as myAccount tab as active
        ui->tabs->setCurrentIndex(2);
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

    ui->FNameEdit->clear();
    ui->companyEdit->clear();
    ui->streetEdit->clear();
    ui->cityEdit->clear();
    ui->stateEdit->setCurrentIndex(0);
    ui->zipEdit->clear();
    ui->UNameEdit->clear();
    ui->PwordEdit->clear();
    ui->InterestEdit->setCurrentIndex(0);


}
//new user creates an account, can only be customer access level
void MainWindow::on_CreatAcct_clicked()
{
    User toAdd;
    QString name, uName, pWord, company, street, city, state, zipTemp, interest;
    name = ui->FNameEdit->text().simplified();
    uName= ui->UNameEdit->text().simplified();
    pWord = ui->PwordEdit->text().simplified();
    company = ui->companyEdit->text().simplified();
    street = ui->streetEdit->text().simplified();
    city = ui->cityEdit->text().simplified();
    state = ui->stateEdit->currentText();
    zipTemp = ui->zipEdit->text().simplified();
    int zip = zipTemp.toInt();
    interest = ui->InterestEdit->currentText();

    if(name.isEmpty() || uName.isEmpty() || pWord.isEmpty() || company.isEmpty() || street.isEmpty() ||
       city.isEmpty() || zipTemp.isEmpty())
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 "Please fill all fields.");
    }
    else
    {
        toAdd.newCustomer(name, uName, pWord, company, street, city, state, zip, interest);

        ui->PwordEdit->setEchoMode(QLineEdit::Password);

        if(db.addPerson(toAdd))
        {
            Login(uName, pWord);
        }
        else
        {
            QMessageBox::information(this, tr("Invalid!"),
                                     "Username is taken, pick another .");
        }
    }

}
//show password
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
//show password
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

//logs in the correct people
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
        // set proper tabs
        setCustomerLoginTabs(currentUserAccessLevel);
        // set customer label info
        setCustomerLabelInfo(username);
    }
    // 2 = admin acces level
    else if(db.checkLogin(username, pword) == 2)
    {
        isUserLoggedIn = true;
        currentUserAccessLevel = 2;
        qDebug() << "Admin access level detected.";
        // set proper tabs
        setCustomerLoginTabs(currentUserAccessLevel);
        // set customer label info
        setCustomerLabelInfo(username);
    }

}

void MainWindow::on_pushButton_clicked()
{
    ui->tabs->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tabs->setCurrentIndex(2);
}

void MainWindow::on_actionPolicy_2_triggered()
{
    QMessageBox::information(this, tr("Guarantee Policy")
, "We guarantee that you will be satisfied because satisfaction is our guarantee.");
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(this, tr("Contact Us")
, "If you have any complaints or feedback, you may contact us through the number (555)666-7777\nOr you may mail it instead to our P.O. Box at\n"
    "555 Suck It Blvd. Home of the Bald Eagles 66666, India");
}


void MainWindow::on_keyCustomersButton_clicked()
{
    ui->CustomersTable->clear();
    ui->CustomersTable->horizontalHeader()->setVisible(true);


    /* Sets the columns of the of table for Registered customers*/
    ui->CustomersTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->CustomersTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Username"));
    ui->CustomersTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Company"));
    ui->CustomersTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Interest"));


    /*  Will fill tables depending on how information is collected from database
     *   need to run through a loop
     */

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Customer Name"));
    ui->CustomersTable->setItem(0, 1, new QTableWidgetItem("Customer Username"));
    ui->CustomersTable->setItem(0, 2, new QTableWidgetItem("Company Name"));
    ui->CustomersTable->setItem(0, 3, new QTableWidgetItem("Company Interest"));
}

void MainWindow::on_registeredButton_clicked()
{

    ui->CustomersTable->clear();
    ui->CustomersTable->horizontalHeader()->setVisible(true);


    /* Sets the columns of the of table for Registered customers*/
    ui->CustomersTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));

    ui->CustomersTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Username"));

    ui->CustomersTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Company"));

    ui->CustomersTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Interest"));


    /*  Will fill tables depending on how information is collected from database
     *   need to run through a loop
     */


    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Customer Name"));

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Customer Username"));

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Company Name"));

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Company Interest"));

}

void MainWindow::on_purchasesButton_clicked()
{

    int col = 0;

    ui->CustomersTable->clear();

    ui->CustomersTable->horizontalHeader()->setVisible(true);

    /* Sets the columns of the of table for Registered customers*/
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Company"));
    col++;

    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Level"));
    col++;

    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Quantity"));
    col++;

    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Total Spent"));
    col++;


    /*  Will fill tables depending on how information is collected from database
     *   need to run through a loop
     */

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Company Name"));

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Level Bought"));

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Quantity Bought"));

    ui->CustomersTable->setItem(0, 0, new QTableWidgetItem("Total Company Spent"));

}
//shortcut login button
void MainWindow::on_pushButton_3_clicked()
{
    this->Login("yuge","wall");
}

void MainWindow::on_signOutButton_2_clicked()
{
    ui->EditLabel->setVisible(true);
}
