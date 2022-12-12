#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//    Login login;
//    login.setModal(true);
//    login.exec();


//void on_formLogin_clicked();
//void on_peminjam_clicked();
void MainWindow::on_formLogin_clicked()
{
    close();
    login = new Login(this);
    login->show();
}


void MainWindow::on_peminjam_clicked()
{
    close();
    pendaftar = new peminjam(this);
    pendaftar->show();
}

