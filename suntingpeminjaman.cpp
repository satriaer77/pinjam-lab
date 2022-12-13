#include "suntingpeminjaman.h"
#include "ui_suntingpeminjaman.h"

SuntingPeminjaman::SuntingPeminjaman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SuntingPeminjaman)
{
    ui->setupUi(this);
}

SuntingPeminjaman::~SuntingPeminjaman()
{
    delete ui;
}
