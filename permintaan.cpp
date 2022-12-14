#include "permintaan.h"
#include "ui_permintaan.h"
#include "managementpeminjaman.h"
#include <QDebug>
#include <QStandardItemModel>

permintaan::permintaan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::permintaan)
{
    ui->setupUi(this);
    this->setWindowTitle("Request Peminjam Lab");

    QSqlQueryModel *model = new QSqlQueryModel(ui->filterLab);
    QSqlQueryModel *mdl = new QSqlQueryModel(ui->tablePeminjam);
    database.koneksiOpen();
    model->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(model);

    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman WHERE id_status=2");

    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    mdl->setQuery(*qry);
    ui->tablePeminjam->setModel(mdl);
    qDebug() << (mdl->rowCount());

}

permintaan::~permintaan()
{
    delete ui;
}



void permintaan::on_pushButton_2_clicked()
{
    close();
    ManagementPeminjaman *mngpjm;
    mngpjm = new ManagementPeminjaman(this);
    mngpjm->show();

}

