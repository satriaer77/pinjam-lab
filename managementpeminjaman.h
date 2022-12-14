#ifndef MANAGEMENTPEMINJAMAN_H
#define MANAGEMENTPEMINJAMAN_H

#include <QDialog>
#include "database.h"

namespace Ui {
class ManagementPeminjaman;
}

class ManagementPeminjaman : public QDialog
{
    Q_OBJECT

public:
    explicit ManagementPeminjaman(QWidget *parent = nullptr);
    ~ManagementPeminjaman();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ManagementPeminjaman *ui;
    Database database;
};

#endif // MANAGEMENTPEMINJAMAN_H
