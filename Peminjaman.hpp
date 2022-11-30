#ifndef PEMINJAMAN_HPP
#define PEMINJAMAN_HPP
#include <iostream>
using namespace std;

class Peminjaman
{
private :
    int idPeminjam,idStatus,idLab;
    string namaPeminjam,nimPeminjam, keperluan, tanggal, jamStart,jamEnd;


public :
    int getidPeminjam()
    {
        return this->idPeminjam;
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



    //Set Obj



#endif // PEMINJAMAN_HPP
