#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

signals:
    void LoginInput(QString, QString);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoginWindow *ui;
    QString username;
    QString password;


};

#endif // LOGINWINDOW_H
