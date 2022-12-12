#ifndef DETAILPEMINJAMAN_H
#define DETAILPEMINJAMAN_H

#include <QDialog>

namespace Ui {
class DetailPeminjaman;
}

class DetailPeminjaman : public QDialog
{
    Q_OBJECT

public:
    explicit DetailPeminjaman(QWidget *parent = nullptr);
    ~DetailPeminjaman();

private:
    Ui::DetailPeminjaman *ui;
};

#endif // DETAILPEMINJAMAN_H
