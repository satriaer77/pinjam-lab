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
    void koneksiDb()
    {

        this->db.setHostName("localhost");
        this->db.setDatabaseName("pbo_lab");
        this->db.setUserName("root");
        this->db.setPassword("234iwuope");
        bool ok = this->db.open();

        if(ok)
        {
            cout<<"Koneksi Berhasil";
        }
        else
        {
            cout<<"Koneksi Gagal";
        }

    }

    void closeKoneksi()
    {
        this->db.close();
    }

};

#endif // KONEKSIDB_H
