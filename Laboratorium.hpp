#ifndef LABORATORIUM_HPP
#define LABORATORIUM_HPP

#include <iostream>
using namespace std;

class Laboratorium
{
private :
    int idLab;
    string namaLab;

public:
    int getidLab()
    {
        return this->idLab;
    }
    string getnamaLab()
    {
        return this->namaLab;
    }

    void setnamaLab(string nmLab)
    {
        this->namaLab = nmLab;
    }
    void setidLab(int idLab)
    {
        this->idLab = idLab;
    }

};

#endif // LABORATORIUM_HPP
