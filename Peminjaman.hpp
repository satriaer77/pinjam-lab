#ifndef PEMINJAMAN_HPP
#define PEMINJAMAN_HPP
#include <iostream>
using namespace std;

class Peminjaman
{
private :
    int idPeminjaman,idStatus,idLab;
    string namaPeminjam,nimPeminjam, keperluan, tanggal, jamStart,jamEnd;


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
    string getnamaPeminjam()
    {
        return this->namaPeminjam;
    }
    string getnimPeminjam()
    {
        return this->nimPeminjam;
    }
    string getKeperluan()
    {
        return this->keperluan;
    }
    string getTanggal()
    {
        return this->tanggal;
    }
    string getjamStart()
    {
        return this->jamStart;
    }
    string getjamEnd()
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
    void setnamaPeminjam(string namaPjm)
    {
        this->namaPeminjam = namaPjm;
    }
    void setnimPeminjam(string nimPjm)
    {
        this->nimPeminjam = nimPjm;
    }
    void setTanggal(string tgl)
    {
        this->tanggal = tgl;
    }
    void setjamStart(string jamSt)
    {
        this->jamStart = jamSt;
    }
    void setjamEnd(string jamEd)
    {
        this->jamEnd = jamEd;
    }
    void setKeperluan(string perlu)
    {
        this->keperluan = perlu;
    }
};

#endif // PEMINJAMAN_HPP
