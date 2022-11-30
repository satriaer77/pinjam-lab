#ifndef USERMODEL_HPP
#define USERMODEL_HPP

#include <iostream>
#include "KoneksiDb.hpp"
#include <QSqlQuery>
#include "User.hpp"
#include <QVariant>


class UserModel
{
public :
    bool insertUser(User user)
    {
         KoneksiDb koneksi;
         koneksi.koneksiDb();
//         auto query = new QSqlQuery(koneksi.db);
//         query->prepare("INSERT INTO user(username,password) VALUES(:username,:password)");
//         query->bindValue(":username","as");
//         query->bindValue(":password","ss");
         koneksi.db.exec("INSERT INTO user(username,password) VALUES(asdasd,asda)");

         koneksi.closeKoneksi();

    }

};


#endif // USERMODEL_HPP
