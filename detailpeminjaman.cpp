#include "detailpeminjaman.h"
#include "ui_detailpeminjaman.h"

DetailPeminjaman::DetailPeminjaman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailPeminjaman)
{
    ui->setupUi(this);
}

DetailPeminjaman::~DetailPeminjaman()
{
    delete ui;
}
