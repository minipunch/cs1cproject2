#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ClearTable();


private slots:
    void on_signInButton_clicked();//

    void on_signOutButton_clicked();//


    void on_CreatAcct_clicked();//

    void on_pWordToggle_toggled(bool checked);//

    void on_pWordToggle2_toggled(bool checked);//

    void on_pushButton_clicked();//

    void on_pushButton_2_clicked();//

    void on_actionPolicy_2_triggered();//

    void on_actionHelp_triggered();//

    void on_EditInfo_B_clicked();//

    void on_saveButton_clicked();//

    void on_pushButton_3_clicked();//

    void on_keyCustomersButton_clicked();//

    void on_tabs_tabBarClicked(int index);//

    void on_signOutButton_2_clicked();//

    void on_customersButton_clicked();//

    void on_adminButton_clicked();//

    void on_BuyButton_clicked();

    void on_lineEdit_2_returnPressed();

private:
    Ui::MainWindow *ui;
    dbManager db;
    bool isUserLoggedIn;
    int currentUserAccessLevel;
    void Login(const QString& username, const QString& pword);//
    void setCustomerLabelInfo(QString customerUsername);
    void setCustomerLoginTabs(int customerAccessLevel);
    QString username;
};

#endif // MAINWINDOW_H
