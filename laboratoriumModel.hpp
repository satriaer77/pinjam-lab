#ifndef LABORATORIUMMODEL_HPP
#define LABORATORIUMMODEL_HPP

#include <iostream>
#include "KoneksiDb.hpp"
#include <QSqlQuery>
#include "Peminjaman.hpp"

class LaboratoriumModel
{
public :
    bool pinjamLab(Peminjaman pinjam)
    {
         QSqlQuery query;
         query.prepare("INSERT INTO user (username,password) VALUES(:username,:password)")
    }

};

#endif // LABORATORIUMMODEL_HPP
