#include "peminjam.h"
#include "ui_peminjam.h"
#include <QDebug>
#include <QStandardItemModel>

peminjam::peminjam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::peminjam)
{
    ui->setupUi(this);
    this->setWindowTitle("Peminjam Lab");
}

peminjam::~peminjam()
{
    delete ui;
}

void peminjam::on_booking_clicked()
{
    formDaftar = new daftar(this);
    formDaftar->show();
}


void peminjam::on_booking_2_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    database.koneksiOpen();

    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman");

    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    model->setQuery(*qry);

    ui->tablePeminjam->setModel(model);
//    database.koneksiClose();

    qDebug() << (model->rowCount());
}

