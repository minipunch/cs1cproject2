#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"

#include<QMessageBox>
/*!
   * \file mainwindow.cpp
   * \brief  mainwindow source file
   *
   * This file contains the mainwindow definitions and implementations
   */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isUserLoggedIn = false;

    ui->tabs->removeTab(5);
    // remove admin panel tab
    ui->tabs->removeTab(4);
    // remove account info tab
    ui->tabs->removeTab(3);

    //Inserting Picture
    QPixmap burglar(":/images/sneaker.png");
    ui->picturelabel->setPixmap(burglar);

    username = "Guest";
    /* Sets the widgets to not visable until it is needed*/
    ui->EditAccountBox->setVisible(false);
    ui->EditLabel->setVisible(false);
    ui->saveButton->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ClearTable()
{
    int currentRows = ui->CustomersTable->rowCount();
    int currentCol =  ui->CustomersTable->columnCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->CustomersTable->removeRow(0);
    }

    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->CustomersTable->removeColumn(0);
    }
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
        ui->tabs->addTab(ui->AccountInfoTab, "My Account");
        // set as active tab
        ui->tabs->setCurrentIndex(2);
        ui->tabs->addTab(ui->customerTab, "Customer");
    }
    else if(customerAccessLevel == 2)
    {
        // remove customer login tab
        ui->tabs->removeTab(2);
        // add customer info tab
        ui->tabs->addTab(ui->AccountInfoTab, "My Account");
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

    //clear line edits for account editing

    ui->usernameEdit->clear();
    ui->cityEdit2->clear();
    ui->nameEdit2->clear();
    ui->streetEdit2->clear();
    // ui->stateEdit2->clear();
    ui->zipcodeEdit2->clear();
    //hide the edit account stuff
    ui->EditAccountBox->setVisible(false);
    ui->EditLabel->setVisible(false);
    ui->saveButton->setVisible(false);
    username = "Guest";
    ui->levelBox->setCurrentIndex(0);
    ui->platformBox->setCurrentIndex(0);
    ui->quantityEdit->clear();
}



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
        // set proper tabs
        setCustomerLoginTabs(currentUserAccessLevel);
        // set customer label info
        setCustomerLabelInfo(username);

        this->username = username;
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
        this->username = username;
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

void MainWindow::on_EditInfo_B_clicked()
{
    ui->EditAccountBox->setVisible(true);
    ui->EditLabel->setVisible(true);
    ui->saveButton->setVisible(true);

    ui->usernameEdit->setText(username);
    ui->cityEdit2->setText(db.retrieveCustomerCity(username));
    ui->nameEdit2->setText(db.retrieveCustomerName(username));
    ui->streetEdit2->setText(db.retrieveCustomerStreet(username));
    ui->stateEdit_2->setCurrentText(db.retrieveCustomerState(username));

    //ui->stateEdit2->setText(db.retrieveCustomerState(username));
    ui->zipcodeEdit2->setText(db.retrieveCustomerZip(username));

}

void MainWindow::on_saveButton_clicked()
{

    QString username1 = username;
    QString username2 = ui->usernameEdit->text().simplified();
    QString city      = ui->cityEdit2->text().simplified();
    QString name      = ui->nameEdit2->text().simplified();
    QString street    = ui->streetEdit2->text().simplified();
    QString state     = ui->stateEdit_2->currentText();
    QString zip       = ui->zipcodeEdit2->text().simplified();


    if(db.UpdateInfo(username1, username2, name, street, state, city, zip))
    {
        username = username2;
        QMessageBox::information(this, tr("Success"), "Successfully Updated Information");
    }
    else
    {
        QMessageBox::information(this, tr("Unsuccessful"), "Information Not Updated. Please try again");
    }

    ui->usernameLabel->setText(username);
    ui->nameLabel->setText(name);
    ui->companyLabel->setText(db.retrieveCustomerCompany(username));
    ui->streetLabel->setText(street);
    ui->cityLabel->setText(city);
    ui->stateLabel->setText(state);
    ui->zipLabel->setText(zip);

    ui->EditAccountBox->setVisible(false);
    ui->EditLabel->setVisible(false);
    ui->saveButton->setVisible(false);

}


void MainWindow::on_keyCustomersButton_clicked()
{
    ClearTable();

    int col = 0;
    int row = 0;

    ui->CustomersTable->horizontalHeader()->setVisible(true);

    /* Sets the columns of the of table for Registered customers*/
    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Company"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Name"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Username"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Zip Code"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Protection Level"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Licenses"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Platform"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Key"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Interest Level"));
    col++;


    QVector<QString> list = db.getUserNames(3);

    for(int i = 0; i < list.size(); i++)
    {
        QString username = list.at(i);

        ui->CustomersTable->insertRow(row);
        ui->CustomersTable->setItem(row, 0, new QTableWidgetItem(db.retrieveCustomerCompany(username)));
        ui->CustomersTable->setItem(row, 1, new QTableWidgetItem(db.retrieveCustomerName(username)));
        ui->CustomersTable->setItem(row, 2, new QTableWidgetItem(username));
        ui->CustomersTable->setItem(row, 3, new QTableWidgetItem(db.retrieveCustomerZip(username)));
        ui->CustomersTable->setItem(row, 4, new QTableWidgetItem(db.retrieveCustomerLevel(username)));
        ui->CustomersTable->setItem(row, 5, new QTableWidgetItem(db.retrieveCustomerLiscenses(username)));
        ui->CustomersTable->setItem(row, 6, new QTableWidgetItem(db.retrieveCustomerPlatform(username)));
        ui->CustomersTable->setItem(row, 7, new QTableWidgetItem(db.retrieveCustomerKey(username)));
        ui->CustomersTable->setItem(row, 8, new QTableWidgetItem(db.retrieveCustomerInterest(username)));
        row++;
    }

    ui->CustomersTable->resizeColumnsToContents();
    ui->CustomersTable->horizontalHeader()->setStretchLastSection(true);
}



void MainWindow::on_tabs_tabBarClicked(int index)
{
    if(index == 4)
    {
        ClearTable();
    }
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


void MainWindow::on_customersButton_clicked()
{
    ClearTable();

    int col = 0;
    int row = 0;

    ui->CustomersTable->horizontalHeader()->setVisible(true);

    /* Sets the columns of the of table for Registered customers*/
    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Company"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Name"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Username"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Zip Code"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Protection Level"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Licenses"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Platform"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Key"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Interest Level"));
    col++;


    /*  Will fill tables depending on how information is collected from database
     *   need to run through a loop
     */

    QVector<QString> list = db.getUserNames(1);

    for(int i = 0; i < list.size(); i++)
    {
        QString username = list.at(i);

        ui->CustomersTable->insertRow(row);
        ui->CustomersTable->setItem(row, 0, new QTableWidgetItem(db.retrieveCustomerCompany(username)));
        ui->CustomersTable->setItem(row, 1, new QTableWidgetItem(db.retrieveCustomerName(username)));
        ui->CustomersTable->setItem(row, 2, new QTableWidgetItem(username));
        ui->CustomersTable->setItem(row, 3, new QTableWidgetItem(db.retrieveCustomerZip(username)));
        ui->CustomersTable->setItem(row, 4, new QTableWidgetItem(db.retrieveCustomerLevel(username)));
        ui->CustomersTable->setItem(row, 5, new QTableWidgetItem(db.retrieveCustomerLiscenses(username)));
        ui->CustomersTable->setItem(row, 6, new QTableWidgetItem(db.retrieveCustomerPlatform(username)));
        ui->CustomersTable->setItem(row, 7, new QTableWidgetItem(db.retrieveCustomerKey(username)));
        ui->CustomersTable->setItem(row, 8, new QTableWidgetItem(db.retrieveCustomerInterest(username)));
        row++;
    }

    ui->CustomersTable->resizeColumnsToContents();
    ui->CustomersTable->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_adminButton_clicked()
{
    ClearTable();

    int col = 0;
    int row = 0;

    ui->CustomersTable->horizontalHeader()->setVisible(true);


    /* Sets the columns of the of table for Registered customers*/
    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Name"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Username"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Zip"));
    col++;

    ui->CustomersTable->insertColumn(col);
    ui->CustomersTable->setHorizontalHeaderItem(col, new QTableWidgetItem("State"));
    col++;


    /*  Will fill tables depending on how information is collected from database
     *   need to run through a loop
     */

    QVector<QString> list = db.getUserNames(2);

    for(int i = 0; i < list.size(); i++)
    {
        QString username = list.at(i);

        ui->CustomersTable->insertRow(row);
        ui->CustomersTable->setItem(row, 0, new QTableWidgetItem(db.retrieveCustomerName(username)));
        ui->CustomersTable->setItem(row, 1, new QTableWidgetItem(username));
        ui->CustomersTable->setItem(row, 2, new QTableWidgetItem(db.retrieveCustomerZip(username)));
        ui->CustomersTable->setItem(row, 3, new QTableWidgetItem(db.retrieveCustomerState(username)));
        row++;
    }

    ui->CustomersTable->resizeColumnsToContents();
    ui->CustomersTable->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_BuyButton_clicked()
{
    QString platform = ui->platformBox->currentText();
    QString level    = ui->levelBox->currentText();
    QString quantity = ui->quantityEdit->text();
    if(username != "Guest")
    {
        if(db.BuyProducts(username, platform, level, quantity))
        {
            QMessageBox::information(this, tr("Success"), "Successfully purchased products");
        }
        else
        {
            QMessageBox::information(this, tr("Unsuccessful"), "Order did not go through. Please try again");
        }
    }
    else
    {
        QMessageBox::information(this, tr("You need to sign in!")
                                 , "Please login or make an account to buy licenses");
    }

    ui->levelBox->setCurrentIndex(0);
    ui->platformBox->setCurrentIndex(0);
    ui->quantityEdit->clear();


}

void MainWindow::on_lineEdit_2_returnPressed()
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
