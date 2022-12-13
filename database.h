#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

class Database
{
public:
    QSqlDatabase db;
    bool koneksiOpen(){
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("234iwuope");
        db.setDatabaseName("pinjam_lab");
        bool ok = db.open();
        return ok;
    }

    void koneksiClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

};
#endif // DATABASE_H
