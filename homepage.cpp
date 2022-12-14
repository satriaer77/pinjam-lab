#include "homepage.h"
#include "peminjam.h"
#include "ui_homepage.h"
#include <QStandardItemModel>
#include <QDialog>
#include <QDebug>

HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{

    ui->setupUi(this);
    this->setWindowTitle("HomePage");
    database.koneksiOpen();

    QSqlQueryModel *model = new QSqlQueryModel(ui->filterLab);
    model->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(model);


    QSqlQueryModel * mdl = new QSqlQueryModel(ui->tabelRequest);
    database.koneksiOpen();

    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman WHERE id_status = 2");

    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    mdl->setQuery(*qry);
    ui->tabelRequest->setModel(mdl);
    qDebug() << (mdl->rowCount());

}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_pushButton_clicked()
{
    close();
    peminjam *pinjam;
    pinjam = new peminjam(this);
    pinjam->show();

}


void HomePage::on_pushButton_2_clicked()
{

}


void HomePage::on_pushButton_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(ui->filterLab);
    QSqlQueryModel * mdl = new QSqlQueryModel(ui->tabelRequest);
    database.koneksiOpen();
    int lab = ui->filterLab->currentIndex();

    model->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(model);
    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman WHERE id_status = 2 and id_lab=:id_lab");
    qry->bindValue(":id_lab", lab + 1);
    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    mdl->setQuery(*qry);
    ui->tabelRequest->setModel(mdl);
    qDebug() << (mdl->rowCount());
}


void HomePage::on_pushButton_4_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(ui->filterLab);
    QSqlQueryModel * mdl = new QSqlQueryModel(ui->tabelRequest);
    database.koneksiOpen();
    QString tanggal = ui->filterTgl->text();

    model->setQuery("SELECT nama_lab FROM laboratorium");
    ui->filterLab->setModel(model);
    QSqlQuery* qry = new QSqlQuery(database.db);
    qry->prepare("select * from peminjaman WHERE id_status = 2 and id_lab=:id_lab");
    qry->bindValue(":tanggal", QDate::fromString(tanggal, "yyyy-mm-dd"));
    qDebug()<<tanggal;
    if(!qry->exec())
        qDebug() << qry->lastError().text() << qry->lastQuery();
    else
        qDebug() << qry;

    mdl->setQuery(*qry);
    ui->tabelRequest->setModel(mdl);
    qDebug() << (mdl->rowCount());
}

