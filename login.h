#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "database.h"
#include "homepage.h"
#include "peminjam.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    Database database;
    HomePage *home;
    peminjam *pendaftar;
};

#endif // LOGIN_H
