#include "managementpeminjaman.h"
#include "ui_managementpeminjaman.h"

ManagementPeminjaman::ManagementPeminjaman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagementPeminjaman)
{
    ui->setupUi(this);
}

ManagementPeminjaman::~ManagementPeminjaman()
{
    delete ui;
}
