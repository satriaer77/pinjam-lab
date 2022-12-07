#ifndef USERMODEL_HPP
#define USERMODEL_HPP

#include <iostream>
#include "KoneksiDb.hpp"
#include <QSqlQuery>
#include "User.hpp"
#include <QVariant>
using namespace std;


class UserModel
{
public :
    bool insertUser(User user)
    {
         KoneksiDb koneksi;
         koneksi.koneksiDb();
         auto query = new QSqlQuery(koneksi.db);
         QString username = QString::fromStdString(user.getUsername());
         QString password = QString::fromStdString(user.getPassword());

         bool queryInsert = query->exec("INSERT INTO user(username,password) VALUES('"+username+"','"+password+"')");

         koneksi.closeKoneksi();
         return queryInsert;

    }

    bool updateUser(User user)
    {
        KoneksiDb koneksi;
        koneksi.koneksiDb();
        auto query = new QSqlQuery(koneksi.db);
        QString username = QString::fromStdString(user.getUsername());
        QString password = QString::fromStdString(user.getPassword());


        bool queryUpdate = query->exec("UPDATE user SET username='"+username+"' WHERE id_user="+user.getidUser()+" ");

        return queryUpdate;
    }

};


#endif // USERMODEL_HPP
