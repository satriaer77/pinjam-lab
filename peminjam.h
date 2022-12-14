#ifndef PEMINJAM_H
#define PEMINJAM_H

#include <QDialog>
#include "daftar.h"
#include "database.h"


namespace Ui {
class peminjam;
}

class peminjam : public QDialog
{
    Q_OBJECT

public:
    explicit peminjam(QWidget *parent = nullptr);
    ~peminjam();

private slots:
    void on_booking_clicked();

    void on_booking_2_clicked();

    void on_daftarRequest_clicked();

    void on_pushButton_clicked();

private:
    Ui::peminjam *ui;
    daftar *formDaftar;
    Database database;
};

#endif // PEMINJAM_H
