#ifndef SUNTINGPEMINJAMAN_H
#define SUNTINGPEMINJAMAN_H

#include <QDialog>

namespace Ui {
class SuntingPeminjaman;
}

class SuntingPeminjaman : public QDialog
{
    Q_OBJECT

public:
    explicit SuntingPeminjaman(QWidget *parent = nullptr);
    ~SuntingPeminjaman();

private:
    Ui::SuntingPeminjaman *ui;
};

#endif // SUNTINGPEMINJAMAN_H
