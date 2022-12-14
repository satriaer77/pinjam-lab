#ifndef DETAILPEMINJAMAN_H
#define DETAILPEMINJAMAN_H

#include <QDialog>
#include "database.h"
namespace Ui {
class DetailPeminjaman;
}

class DetailPeminjaman : public QDialog
{
    Q_OBJECT

public:
    explicit DetailPeminjaman(QWidget *parent = nullptr);
    ~DetailPeminjaman();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DetailPeminjaman *ui;
    Database database;
};

#endif // DETAILPEMINJAMAN_H
