#include "managementpeminjaman.h"
#include "ui_managementpeminjaman.h"
#include "permintaan.h"
#include "detailpeminjaman.h"
#include <QSqlQuery>

ManagementPeminjaman::ManagementPeminjaman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagementPeminjaman)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel(ui->filterLab);
    QSqlQueryModel *mdl = new QSqlQueryModel(ui->tabelPeminjam);
    database.koneksiOpen();
    model->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(model);

    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman");

    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    mdl->setQuery(*qry);
    ui->tabelPeminjam->setModel(mdl);
    qDebug() << (mdl->rowCount());

}

ManagementPeminjaman::~ManagementPeminjaman()
{
    delete ui;
}

void ManagementPeminjaman::on_pushButton_clicked()
{
    close();
    permintaan *perminta;
    perminta = new permintaan(this);
    perminta->show();
}


void ManagementPeminjaman::on_pushButton_4_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel(ui->filterLab);
    QSqlQueryModel *mdl = new QSqlQueryModel(ui->tabelPeminjam);
    database.koneksiOpen();
    model->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(model);

    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman");

    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    mdl->setQuery(*qry);
    ui->tabelPeminjam->setModel(mdl);
    qDebug() << (mdl->rowCount());
}


void ManagementPeminjaman::on_pushButton_3_clicked()
{
    DetailPeminjaman *editPinjam;
    editPinjam = new DetailPeminjaman(this);
    editPinjam->show();
}

