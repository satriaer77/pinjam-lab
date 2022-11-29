#ifndef KONEKSIDB_HPP
#define KONEKSIDB_HPP

#endif // KONEKSIDB_HPP


class KoneksiDb
{

    QSqlDatabase db = QSqlDatabase::addDatabase("pbo_lab");
    db.setHostName("localhosr");
    db.setDatabaseName("pbo_lab");
    db.setUserName("root");
    db.setPassword("234iwuope");
    bool ok = db.open();
};
