#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "daftar.h"
#include "peminjam.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_formLogin_clicked();
    void on_peminjam_clicked();

private:
    Ui::MainWindow *ui;
    Login *login;
    daftar *formDaftar;
    peminjam *pendaftar;
};
#endif // MAINWINDOW_H
