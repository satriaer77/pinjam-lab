#ifndef LABORATORIUMMODEL_HPP
#define LABORATORIUMMODEL_HPP

#include <iostream>
#include "database.h"

#include "Laboratorium.hpp"
using namespace std;


class LaboratoriumModel
{
public:
    QSqlQuery *laboratorium;
    void getLaboratoriumData()
    {
        Database koneksi;
        koneksi.koneksiOpen();
        laboratorium = new QSqlQuery(koneksi.db);
        laboratorium->exec("SELECT * FROM laboratorium");
        koneksi.koneksiClose();
    }

    void getAllLaboratoriumNama()
    {
        Database koneksi;
        koneksi.koneksiOpen();
        laboratorium = new QSqlQuery(koneksi.db);
        laboratorium->exec("SELECT nama_lab FROM laboratorium");
        koneksi.koneksiClose();
    }




};

#endif // LABORATORIUMMODEL_HPP
