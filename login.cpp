#include "login.h"
#include "ui_login.h"
#include "homepage.h"
#include "permintaan.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);
    bool ok = database.koneksiOpen();
    if (ok){
        ui->labelLogin->setText("Conected");
    }else{
        ui->labelLogin->setText("Not Conected");
    }
    database.koneksiClose();

}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    bool ok = database.koneksiOpen();
    if (ok){
        QString username = ui->username->text();
        QString password = ui->password->text();

        // Query Database
        QSqlQuery query;
        query.prepare("SELECT password FROM user WHERE username = :username");
        query.bindValue(":username", username);

        if (query.exec()){
            QString passwordAdmin;
            int count = 0;
            while(query.next()){
                passwordAdmin = query.value(0).toString();
                count++;
            }
            if (count == 1 && passwordAdmin == password){
                    QMessageBox::information(this, "Success", "Login Success");
                    close();
                    permintaan *perminta;
                    perminta = new permintaan(this);
                    perminta->show();

            }else {
                QMessageBox::information(this, "Failed", "Login Gagal");
            }
        }
    }else{
        QMessageBox::information(this, "Failed", "Database Disconnect");
    }

    database.koneksiClose();
}

