#ifndef DAFTAR_H
#define DAFTAR_H

#include <QDialog>
#include "database.h"
#include "Peminjaman.hpp"
#include "peminjamanModel.hpp"

namespace Ui {
class daftar;
}

class daftar : public QDialog
{
    Q_OBJECT

public:
    explicit daftar(QWidget *parent = nullptr);
    ~daftar();

private slots:
    void on_submit_clicked();

    void on_pushButton_clicked();

    void on_back_clicked();

private:
    Ui::daftar *ui;
    Database database;
    Peminjaman peminjaman;
    PeminjamanModel pinjamModel;

};

#endif // DAFTAR_H
