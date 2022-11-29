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
        db.setHostName("localhost");
        db.setDatabaseName("pbo_lab");
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

    }

};

#endif // KONEKSIDB_H
