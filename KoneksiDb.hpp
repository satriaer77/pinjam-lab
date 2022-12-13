#ifndef KONEKSIDB_HPP
#define KONEKSIDB_HPP
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>

using namespace std;


class KoneksiDb
{
public :

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    bool koneksiDb()
    {
        db.setHostName("localhost");
        db.setDatabaseName("pinjam_lab");
        db.setUserName("root");
        db.setPassword("234iwuope");
        bool ok = db.open();

        if(ok)
        {
            cout<<"Koneksi Berhasil";
        }
        else
        {
            cout<<"Koneksi Gagal";
        }
        return ok;

    }

    void closeKoneksi()
    {
        this->db.close();
    }

};

#endif // KONEKSIDB_H
