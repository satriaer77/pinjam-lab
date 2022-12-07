#ifndef PEMINJAMANMODEL_HPP
#define PEMINJAMANMODEL_HPP


#include <iostream>
#include "KoneksiDb.hpp"
#include <QSqlQuery>
#include <QString>
#include "User.hpp"
#include "Peminjaman.hpp"

#include <QVariant>

using namespace std;

class PeminjamanModel
{
public:
    QSqlQuery *peminjamanModel;
    bool pinjamLab(Peminjaman peminjaman)
    {
//        int idPeminjaman,idStatus,idLab;
//        string namaPeminjam,nimPeminjam, keperluan, tanggal, jamStart,jamEnd;
        KoneksiDb koneksi;
        koneksi.koneksiDb();
        auto query = new QSqlQuery(koneksi.db);

        QString idStatus     = QString::fromStdString(to_string(peminjaman.getidStatus()));
        QString idLab        = QString::fromStdString(to_string(peminjaman.getidLab()));
        QString namaPeminjam = QString::fromStdString(peminjaman.getnamaPeminjam());
        QString nimPeminjam  = QString::fromStdString(peminjaman.getnimPeminjam());
        QString keperluan    = QString::fromStdString(peminjaman.getKeperluan());
        QString tanggal      = QString::fromStdString(peminjaman.getTanggal());
        QString jamStart     = QString::fromStdString(peminjaman.getjamStart());
        QString jamEnd       = QString::fromStdString(peminjaman.getjamEnd());


        bool queryInsert = query->exec("INSERT INTO peminjaman(id_status,id_lab,nama_peminjam,nim_peminjam,tanggal,jam_start,jam_end,keperluan) "
                                       "VALUES("+idStatus+","
                                                ""+idLab+","
                                                "'"+namaPeminjam+"',"
                                                "'"+nimPeminjam+"',"
                                                "'"+tanggal+"',"
                                                "'"+jamStart+"',"
                                                "'"+jamEnd+"',"
                                                "'"+keperluan+"')");
        cout<<queryInsert;

        koneksi.closeKoneksi();
        return queryInsert;
    }

    bool accAdmin(Peminjaman peminjaman)
    {

        KoneksiDb koneksi;
        koneksi.koneksiDb();
        auto query = new QSqlQuery(koneksi.db);

        QString idPeminjaman = QString::fromStdString(to_string(peminjaman.getidPeminjaman()));


        bool queryUpdate = query->exec("UPDATE peminjaman SET id_status=1 WHERE id_peminjaman="+idPeminjaman);
        cout<<queryUpdate;

        koneksi.closeKoneksi();
        return queryUpdate;
    }

    bool editPinjamLab(Peminjaman peminjaman)
    {

        KoneksiDb koneksi;
        koneksi.koneksiDb();
        auto query = new QSqlQuery(koneksi.db);

        QString idPeminjaman = QString::fromStdString(to_string(peminjaman.getidPeminjaman()));
        QString idLab        = QString::fromStdString(to_string(peminjaman.getidLab()));
        QString namaPeminjam = QString::fromStdString(peminjaman.getnamaPeminjam());
        QString nimPeminjam  = QString::fromStdString(peminjaman.getnimPeminjam());
        QString keperluan    = QString::fromStdString(peminjaman.getKeperluan());
        QString tanggal      = QString::fromStdString(peminjaman.getTanggal());
        QString jamStart     = QString::fromStdString(peminjaman.getjamStart());
        QString jamEnd       = QString::fromStdString(peminjaman.getjamEnd());


        bool queryInsert = query->exec("UPDATE peminjaman SET "
                                       "id_lab="+idLab+","
                                       "nama_peminjam='"+namaPeminjam+"',"
                                       "nim_peminjam='"+nimPeminjam+"',"
                                       "tanggal='"+tanggal+"',"
                                       "jam_start='"+jamStart+":00',"
                                       "jam_end='"+jamEnd+":00',"
                                       "keperluan='"+keperluan+"' WHERE id_peminjaman="+idPeminjaman);
        cout<<queryInsert;
        if(!queryInsert)
        {
            query->lastError();
        }
        koneksi.closeKoneksi();
        return queryInsert;
    }

    bool hapusPeminjaman(Peminjaman peminjaman)
    {

        KoneksiDb koneksi;
        koneksi.koneksiDb();
        auto query = new QSqlQuery(koneksi.db);

        QString idPeminjaman = QString::fromStdString(to_string(peminjaman.getidPeminjaman()));


        bool queryUpdate = query->exec("DELETE FROM peminjaman WHERE id_peminjaman="+idPeminjaman);
        cout<<queryUpdate;

        koneksi.closeKoneksi();
        return queryUpdate;
    }

//    bool editPinjamLab(Peminjaman peminjaman)
//    {
//        return queryEdit;
//    }




    void getDataPeminjaman()
    {
        KoneksiDb koneksi;
        koneksi.koneksiDb();
        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman");
    }

    void getDataPeminjamanAsDate(string tgl)
    {
        KoneksiDb koneksi;
        koneksi.koneksiDb();
        QString tanggal      = QString::fromStdString(tgl);

        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman WHERE tanggal='"+tanggal+"'");
    }
};

#endif // PEMINJAMANMODEL_HPP
