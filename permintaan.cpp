#include "permintaan.h"
#include "ui_permintaan.h"

permintaan::permintaan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::permintaan)
{
    ui->setupUi(this);
}

permintaan::~permintaan()
{
    delete ui;
}
