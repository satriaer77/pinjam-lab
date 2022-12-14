#ifndef PEMINJAMANMODEL_HPP
#define PEMINJAMANMODEL_HPP


#include <iostream>
#include "database.h"
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


    //==== CRUD Peminjaman ====//

    //INSERT//
    bool pinjamLab(Peminjaman peminjaman)
    {

        Database koneksi;
        koneksi.koneksiOpen();
        auto query = new QSqlQuery(koneksi.db);

        QString idStatus     = QString::fromStdString(to_string(peminjaman.getidStatus()));
        QString idLab        = QString::fromStdString(to_string(peminjaman.getidLab()));

        query->prepare("INSERT INTO peminjaman(id_status,id_lab,nama_peminjam,nim_peminjam,tanggal,jam_start,jam_end,keperluan) "
                            "VALUES(:idStatus,:idLab,:namaPeminjam,:nimPeminjam,:tanggal,:jamStart,:jamEnd,:keperluan)");
        query->bindValue("idStatus",idStatus);
        query->bindValue("idLab",idLab);
        query->bindValue("idStatus",peminjaman.getnamaPeminjam());
        query->bindValue("idStatus",peminjaman.getnimPeminjam());
        query->bindValue("idStatus",peminjaman.getTanggal());
        query->bindValue("idStatus",peminjaman.getjamStart());
        query->bindValue("idStatus",peminjaman.getjamEnd());
        query->bindValue("idStatus",peminjaman.getKeperluan());
        bool queryInsert = query->exec();
//        bool queryInsert = query->exec("INSERT INTO peminjaman(id_status,id_lab,nama_peminjam,nim_peminjam,tanggal,jam_start,jam_end,keperluan) "
//                                       "VALUES("+idStatus+","
//                                                ""+idLab+","
//                                                "'"+peminjaman.getnamaPeminjam()+"',"
//                                                "'"+peminjaman.getnimPeminjam()+"',"
//                                                "'"+QString::fromQDate(peminjaman.getTanggal())+"',"
//                                                "'"+peminjaman.getjamStart()+"',"
//                                                "'"+peminjaman.getjamEnd()+"',"
//                                                "'"+peminjaman.getKeperluan()+"')");
        cout<<queryInsert;

        koneksi.koneksiClose();
        return queryInsert;
    }
    //---------//



//    bool editPinjamLab(Peminjaman peminjaman)
//    {

//        Database koneksi;
//        koneksi.koneksiOpen();
//        auto query = new QSqlQuery(koneksi.db);

//        QString idPeminjaman = QString::fromStdString(to_string(peminjaman.getidPeminjaman()));
//        QString idLab        = QString::fromStdString(to_string(peminjaman.getidLab()));
//        QString namaPeminjam = QString::fromStdString(peminjaman.getnamaPeminjam());
//        QString nimPeminjam  = QString::fromStdString(peminjaman.getnimPeminjam());
//        QString keperluan    = QString::fromStdString(peminjaman.getKeperluan());
//        QString tanggal      = QString::fromStdString(peminjaman.getTanggal());
//        QString jamStart     = QString::fromStdString(peminjaman.getjamStart());
//        QString jamEnd       = QString::fromStdString(peminjaman.getjamEnd());


//        bool queryInsert = query->exec("UPDATE peminjaman SET "
//                                       "id_lab="+idLab+","
//                                       "nama_peminjam='"+namaPeminjam+"',"
//                                       "nim_peminjam='"+nimPeminjam+"',"
//                                       "tanggal='"+tanggal+"',"
//                                       "jam_start='"+jamStart+":00',"
//                                       "jam_end='"+jamEnd+":00',"
//                                       "keperluan='"+keperluan+"' WHERE id_peminjaman="+idPeminjaman);
//        cout<<queryInsert;

//        koneksi.koneksiClose();
//        return queryInsert;
//    }


    //DELETE//
    bool hapusPeminjaman(Peminjaman peminjaman)
    {

        Database koneksi;
        koneksi.koneksiOpen();
        auto query = new QSqlQuery(koneksi.db);

        QString idPeminjaman = QString::fromStdString(to_string(peminjaman.getidPeminjaman()));


        bool queryUpdate = query->exec("DELETE FROM peminjaman WHERE id_peminjaman="+idPeminjaman);
        cout<<queryUpdate;

        koneksi.koneksiClose();
        return queryUpdate;
    }
    //------//


    //ACC Admin//
    bool accAdmin(Peminjaman peminjaman)
    {

        Database koneksi;
        koneksi.koneksiOpen();
        auto query = new QSqlQuery(koneksi.db);

        QString idPeminjaman = QString::fromStdString(to_string(peminjaman.getidPeminjaman()));


        bool queryUpdate = query->exec("UPDATE peminjaman SET id_status=1 WHERE id_peminjaman="+idPeminjaman);
        cout<<queryUpdate;

        koneksi.koneksiClose();
        return queryUpdate;
    }
    //------//







    //--------- GET DATA METHOD ----------//

    //Get ALL Data Peminjaman
    void getDataPeminjaman()
    {
        Database koneksi;
        koneksi.koneksiOpen();
        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman");
        koneksi.koneksiClose();
    }
    //========================


    //Get Data Peminjaman
    void get1DataPeminjaman(int idPjm)
    {
        Database koneksi;
        koneksi.koneksiOpen();
        QString idPeminjaman      = QString::fromStdString(to_string(idPjm));

        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman WHERE id_lab='"+idPeminjaman+"'");
        koneksi.koneksiClose();
    }
     //========================


    //Get ALL Data Peminjaman With Date Filter (using tanggal)
    void getDataPeminjamanAsDate(string tgl)
    {
        Database koneksi;
        koneksi.koneksiOpen();
        QString tanggal      = QString::fromStdString(tgl);

        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman WHERE tanggal='"+tanggal+"'");
        koneksi.koneksiClose();
    }
     //========================


    //Get ALL Data Peminjaman With Lab Filter (using idLab)
    void getDataPeminjamanAsLab(int iLab)
    {
        Database koneksi;
        koneksi.koneksiOpen();
        QString idLab      = QString::fromStdString(to_string(iLab));

        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman WHERE id_lab='"+idLab+"'");
        koneksi.koneksiClose();
    }
     //========================


    //Get ALL Data Peminjaman With Lab And Date Filter (using idLab)
    void getDataPeminjamanAsLabAndDate(int iLab, string tgl)
    {
        Database koneksi;
        koneksi.koneksiOpen();
        QString idLab      = QString::fromStdString(to_string(iLab));
        QString tanggal      = QString::fromStdString(tgl);

        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman WHERE id_lab='"+idLab+"' and tanggal='"+tanggal+"'");
        koneksi.koneksiClose();
    }
     //========================


    //Get ALL Data Peminjaman Where not accepted with laboratorium and tanggal filter
    void getDataPeminjamanAsLabAndDateNotAcc(int iLab, string tgl)
    {
        Database koneksi;
        koneksi.koneksiOpen();
        QString idLab    = QString::fromStdString(to_string(iLab));
        QString tanggal  = QString::fromStdString(tgl);

        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman WHERE id_lab='"+idLab+"' and tanggal='"+tanggal+"' and id_status=2");
        koneksi.koneksiClose();
    }
     //========================


    //Get ALL Data Peminjaman Where accepted with laboratorium and tanggal filter
    void getDataPeminjamanAsLabAndDateAcc(int iLab, string tgl)
    {
        Database koneksi;
        koneksi.koneksiOpen();
        QString idLab    = QString::fromStdString(to_string(iLab));
        QString tanggal  = QString::fromStdString(tgl);

        peminjamanModel = new QSqlQuery(koneksi.db);
        peminjamanModel->exec("SELECT * FROM peminjaman WHERE id_lab='"+idLab+"' and tanggal='"+tanggal+"' and id_status=1");
        koneksi.koneksiClose();
    }
     //========================
};

#endif // PEMINJAMANMODEL_HPP
