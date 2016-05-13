#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
/*!
   * \file mainwindow.h
   * \brief  Header for mainwindow class(see class page for more details)
   *
   */
namespace Ui {
class MainWindow;
}
/*!
 * \brief The MainWindow class
 *
 * This contains all of the implementations for the event driven parts of the project.
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     * \brief Destructor
     */
    ~MainWindow();
    /*!
     * \brief Clears the admin table
     */
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

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    dbManager db;   //list of users
    bool isUserLoggedIn; //whether or not someone is logged in
    int currentUserAccessLevel; //current user's access level
    void Login(const QString& username, const QString& pword);//checks the database to see if a user's inputted data is found
    void setCustomerLabelInfo(QString customerUsername); //sets the labels for the "My Account" tab once logged in
    void setCustomerLoginTabs(int customerAccessLevel); //sets tabs based on login
    QString username; //username of current user logged in
};

#endif // MAINWINDOW_H
