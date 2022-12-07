#include "mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QString>
#include <QVariant>
#include <QSqlQuery>
#include "UserModel.hpp"
#include "laboratoriumModel.hpp"
#include "peminjamanModel.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "peminjamanLab_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();


    //USER//
    User userA;
    userA.setUsername("jaka");
    userA.setPassword("jaka123");

    UserModel uModel;

    cout<<uModel.insertUser(userA);
    //---//


    LaboratoriumModel labMdl;
//    labMdl.getDataPeminjamanAsLabAndDate(5,);

//    while(labMdl.getData->next())
//    {
//        cout<<endl<<labMdl.getData->value(1).toString().toStdString()<<endl;
//    }

    Peminjaman pjm;


    PeminjamanModel pjmMdl;
//    pjmMdl.pinjamLab(pjm);
//    pjmMdl.getDataPeminjamanAsLabAndDate(5,"2022-02-21");
//    while(pjmMdl.peminjamanModel->next())
//    {
//        cout<<endl<<pjmMdl.peminjamanModel->value(4).toString().toStdString()<<endl;
//    }


//     pjmMdl.get1DataPeminjaman(3);


    //GEORGE Obj Peminjaman
    pjm.setnamaPeminjam("Jake");
    pjm.setnimPeminjam("21041110098");
    pjm.setTanggal("2022-05-22");
    pjm.setidStatus(2);
    pjm.setidLab(6);
    pjm.setjamStart("07:30");
    pjm.setjamEnd("09:00");
    pjm.setKeperluan("Demo Project");
    // ====================



    //TEST INSERT//
    pjmMdl.pinjamLab(pjm);

    //TEST UPDATE Get data and update//
    pjmMdl.get1DataPeminjaman(5);
    pjmMdl.peminjamanModel->next();
    cout<<endl<<
    "\nID Peminjaman : "+pjmMdl.peminjamanModel->value(0).toString().toStdString()+
    "\nID Status     : "+pjmMdl.peminjamanModel->value(1).toString().toStdString()+
    "\nID LAB        : "+pjmMdl.peminjamanModel->value(2).toString().toStdString()+
    "\nNama Peminjam : "+pjmMdl.peminjamanModel->value(3).toString().toStdString()+
    "\nNIM Peminjam  : "+pjmMdl.peminjamanModel->value(4).toString().toStdString()+
    "\nTanggal       : "+pjmMdl.peminjamanModel->value(5).toString().toStdString()+
    "\nJam Mulai     : "+pjmMdl.peminjamanModel->value(6).toString().toStdString()+
    "\nJam Selesai   : "+pjmMdl.peminjamanModel->value(7).toString().toStdString()+
    "\nKeperluan     : "+pjmMdl.peminjamanModel->value(8).toString().toStdString()+
    "\n";
//    pjm.setidPeminjaman(pjmMdl.peminjamanModel->value(8).toString().toStdString(0));
//    pjmMdl.editPinjamLab(pjm);

    //GET ALL DATA//
    pjmMdl.getDataPeminjaman();
    while(pjmMdl.peminjamanModel->next())
    {
        cout<<endl<<"+---------------------------------------+"
        "\nID Peminjaman : "+pjmMdl.peminjamanModel->value(0).toString().toStdString()+
        "\nID Status     : "+pjmMdl.peminjamanModel->value(1).toString().toStdString()+
        "\nID LAB        : "+pjmMdl.peminjamanModel->value(2).toString().toStdString()+
        "\nNama Peminjam : "+pjmMdl.peminjamanModel->value(3).toString().toStdString()+
        "\nNIM Peminjam  : "+pjmMdl.peminjamanModel->value(4).toString().toStdString()+
        "\nTanggal       : "+pjmMdl.peminjamanModel->value(5).toString().toStdString()+
        "\nJam Mulai     : "+pjmMdl.peminjamanModel->value(6).toString().toStdString()+
        "\nJam Selesai   : "+pjmMdl.peminjamanModel->value(7).toString().toStdString()+
        "\nKeperluan     : "+pjmMdl.peminjamanModel->value(8).toString().toStdString()+
        "\n+---------------------------------------+\n";
    }

    pjm.setidPeminjaman(8);
    pjmMdl.hapusPeminjaman(pjm);

    pjm.setidPeminjaman(7);
    pjmMdl.hapusPeminjaman(pjm);





    //ALEXANDRA Obj Peminjaman
//    pjm.setnamaPeminjam("Alexandra");
//    pjm.setnimPeminjam("21041110043");
//    pjm.setTanggal("2022-02-21");
//    pjm.setidStatus(2);
//    pjm.setidLab(5);
//    pjm.setjamStart("13:00");
//    pjm.setjamEnd("15:00");
//    pjm.setKeperluan("UAS");
//    pjm.setidPeminjaman(3);
    // ====================

//    pjmMdl.pinjamLab(pjm);


//    pjmMdl.editPinjamLab(pjm);
//    pjmMdl.hapusPeminjaman(pjm);



    return a.exec();
}

