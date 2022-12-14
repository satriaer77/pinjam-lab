#include "peminjam.h"
#include "homepage.h"
#include "ui_peminjam.h"
#include <QDebug>
#include <QStandardItemModel>

peminjam::peminjam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::peminjam)
{
    ui->setupUi(this);
    this->setWindowTitle("Peminjam Lab");


    QSqlQueryModel *mdl = new QSqlQueryModel(ui->filterLab);

    QSqlQueryModel * model = new QSqlQueryModel();
    database.koneksiOpen();

    mdl->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(mdl);

    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman");
    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    model->setQuery(*qry);
    ui->tablePeminjam->setModel(model);
    qDebug() << (model->rowCount());

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
    QSqlQueryModel *mdl = new QSqlQueryModel(ui->filterLab);
    QSqlQueryModel * model = new QSqlQueryModel();
    database.koneksiOpen();

    mdl->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(mdl);
    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman");
    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    model->setQuery(*qry);
    ui->tablePeminjam->setModel(model);
    qDebug() << (model->rowCount());
}

void peminjam::on_daftarRequest_clicked()
{   close();
    HomePage *home;
    home = new HomePage(this);
    home->show();

}


void peminjam::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(ui->filterLab);
    QSqlQueryModel * mdl = new QSqlQueryModel(ui->tablePeminjam);
    database.koneksiOpen();
    int lab = ui->filterLab->currentIndex();

    model->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(model);

    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman WHERE id_status = 1 and id_lab=:id_lab");
    qry->bindValue(":id_lab", lab + 1);
    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    mdl->setQuery(*qry);
    ui->tablePeminjam->setModel(mdl);
    qDebug() << (mdl->rowCount());
}

