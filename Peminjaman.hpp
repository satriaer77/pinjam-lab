#ifndef PEMINJAMAN_HPP
#define PEMINJAMAN_HPP
#include <iostream>
#include <QString>
#include <QDate>
using namespace std;

class Peminjaman
{
private :
    int idPeminjaman,idStatus,idLab;
    QString namaPeminjam,nimPeminjam, keperluan, jamStart,jamEnd,tanggal;

public :
    int getidPeminjaman()
    {
        return this->idPeminjaman;
    }
    int getidStatus()
    {
        return this->idStatus;
    }
    int getidLab()
    {
        return this->idLab;
    }
    QString getnamaPeminjam()
    {
        return this->namaPeminjam;
    }
    QString getnimPeminjam()
    {
        return this->nimPeminjam;
    }
    QString getKeperluan()
    {
        return this->keperluan;
    }
    QString getTanggal()
    {
        return this->tanggal;
    }
    QString getjamStart()
    {
        return this->jamStart;
    }
    QString getjamEnd()
    {
        return this->jamEnd;
    }



    //Set Attributes
    void setidPeminjaman(int idPjm)
    {
        this->idPeminjaman = idPjm;
    }
    void setidStatus(int idSts)
    {
        this->idStatus = idSts;
    }
    void setidLab(int idLb)
    {
        this->idLab = idLb;
    }
    void setnamaPeminjam(QString namaPjm)
    {
        this->namaPeminjam = namaPjm;
    }
    void setnimPeminjam(QString nimPjm)
    {
        this->nimPeminjam = nimPjm;
    }
    void setTanggal(QString tgl)
    {
        this->tanggal = tgl;
    }
    void setjamStart(QString jamSt)
    {
        this->jamStart = jamSt;
    }
    void setjamEnd(QString jamEd)
    {
        this->jamEnd = jamEd;
    }
    void setKeperluan(QString perlu)
    {
        this->keperluan = perlu;
    }
};

#endif // PEMINJAMAN_HPP
