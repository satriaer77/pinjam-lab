#ifndef LABORATORIUMMODEL_HPP
#define LABORATORIUMMODEL_HPP

#include <iostream>
#include "KoneksiDb.hpp"
#include <QSqlQuery>
#include "Laboratorium.hpp"
using namespace std;


class LaboratoriumModel
{
public:
    QSqlQuery *getData;
    void getLaboratoriumData()
    {
        KoneksiDb koneksi;
        koneksi.koneksiDb();
        getData = new QSqlQuery(koneksi.db);
        getData->exec("SELECT * FROM laboratorium");

    }


};

#endif // LABORATORIUMMODEL_HPP
