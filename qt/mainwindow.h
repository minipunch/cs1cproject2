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


private slots:
    void on_signInButton_clicked();

    void on_signOutButton_clicked();


    void on_CreatAcct_clicked();

    void on_pWordToggle_toggled(bool checked);

    void on_pWordToggle2_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    dbManager db;
    bool isUserLoggedIn;
    int currentUserAccessLevel;
    void Login(const QString& username, const QString& pword);
};

#endif // MAINWINDOW_H
