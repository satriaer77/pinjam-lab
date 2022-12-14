#include "detailpeminjaman.h"
#include "ui_detailpeminjaman.h"

DetailPeminjaman::DetailPeminjaman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailPeminjaman)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel(ui->idPinjam);
    QSqlQueryModel *mdl = new QSqlQueryModel(ui->lab);
    model->setQuery("SELECT id_peminjaman FROM peminjaman");
    ui->idPinjam->setModel(model);
    mdl->setQuery("SELECT nama_laboratorium FROM laboratorium");
    ui->lab->setModel(mdl);
}

DetailPeminjaman::~DetailPeminjaman()
{
    delete ui;
}

void DetailPeminjaman::on_pushButton_2_clicked()
{
    QString idPjm = ui->idPinjam->currentText();
    QString nim = ui->nim->text();
    QString nama = ui->nama->text();
    QString tanggal = ui->tanggal->text();
    QString start = ui->start->text();
    QString end = ui->end->text();
    int idLab = ui->lab->currentIndex();
    QString ket = ui->ket->toPlainText();

    if (!(nama == "" && nim == "" && ket == "")){
       QSqlQuery query;
       query.prepare("UPDATE peminjaman SET id_lab=:id_lab, nama_peminjam=:nama_peminjam, nim_peminjam=:nim_peminjam, tanggal=:tanggal,"
                     " jam_start=:jam_start, jam_end=:jam_end, keperluan=:keperluan WHERE id_peminjaman=:id_pinjam ");
       query.bindValue(":d_pinjam", idPjm);
       query.bindValue(":id_lab", idLab + 1);
       query.bindValue(":nama_peminjam", nama);
       query.bindValue(":nim_peminjam", nim);
       query.bindValue(":tanggal", QDate::fromString(tanggal, "yyyy-mm-dd"));
       query.bindValue(":jam_start", start);
       query.bindValue(":jam_end", end);
       query.bindValue(":keperluan", ket);
         if (query.exec()){
             QMessageBox::information(this, "Success", "Peminjama Berhasil Diajukan");
             close();
             database.koneksiClose();
         }else {
              QMessageBox::information(this, "Failed", "Peminjama Gagal Diajukan");
         }
    }else {
        QMessageBox::information(this, "Failed", "Data Wajib Dilengkapi");
    }

}

