#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabs->removeTab(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
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
    }
    // 2 = admin acces level
    else if(db.checkLogin(ui->lineEdit->text(), ui->lineEdit_2->text()) == 2)
    {
        qDebug() << "Admin access level detected.";
        ui->tabs->addTab(ui->adminPanel, "Admin Panel");
    }
}
