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

private:
    Ui::MainWindow *ui;
    dbManager db;
    int currentAccessLevel;
};

#endif // MAINWINDOW_H
