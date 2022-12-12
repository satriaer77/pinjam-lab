#include "daftar.h"
#include "ui_daftar.h"
#include <QDebug>


daftar::daftar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::daftar)
{
    ui->setupUi(this);
    this->setWindowTitle("Daftar Peminjaman Lab");
    bool ok = database.koneksiOpen();

    if (ok){

        QSqlQueryModel *model = new QSqlQueryModel(ui->lab);
        model->setQuery("SELECT nama_lab FROM lab");
        ui->lab->setModel(model);
    }
}

daftar::~daftar()
{
    delete ui;
}

void daftar::on_submit_clicked()
{
//    QMessageBox::information(this, "Success", "Login Success");
    bool ok = database.koneksiOpen();

    if (ok){

        QSqlQueryModel *model = new QSqlQueryModel(ui->lab);
        model->setQuery("SELECT nama_lab FROM lab");
        ui->lab->setModel(model);

        QString nim = ui->nim->text();
        QString nama = ui->nama->text();
        QString tanggal = ui->tanggal->text();
        QString start = ui->start->text();
        QString end = ui->end->text();
        int lab = ui->lab->currentIndex();
        QString ket = ui->ket->toPlainText();

        if (!(nim == "" && nama == "" && ket == "")){
             QSqlQuery query;
             query.prepare("INSERT INTO peminjaman(id_status, id_lab, nama_peminjam, nim_peminjam, tanggal, jam_start, jam_end, keperluan) VALUES (:id_status, :id_lab, :nama_peminjam, :nim_peminjam, :tanggal, :jam_start, :jam_end, :keperluan)");
             query.bindValue(":id_status", 1);
             query.bindValue(":id_lab", lab + 1);
             query.bindValue(":nama_peminjam", nama);
             query.bindValue(":nim_peminjam", nim);
             query.bindValue(":tanggal", QDate::fromString(tanggal, "dd/MM/yyyy"));
             query.bindValue(":jam_start", start);
             query.bindValue(":jam_end", end);
             query.bindValue(":keperluan", ket);
             if (query.exec()){
                 QMessageBox::information(this, "Success", "Peminajam Berhasil Diajukan");
                 close();
                 database.koneksiClose();
             }else {
                  QMessageBox::information(this, "Failed", "Peminajam Gagal Diajukan");
             }
        }else {
            QMessageBox::information(this, "Failed", "Data Wajib Dilengkapi");
        }

    }


}


void daftar::on_pushButton_clicked()
{
    bool ok = database.koneksiOpen();
    if (ok){
        QSqlQueryModel *model = new QSqlQueryModel(ui->lab);
        model->setQuery("SELECT nama_lab FROM lab");
        ui->lab->setModel(model);
    }
}


void daftar::on_back_clicked()
{
    close();
}

