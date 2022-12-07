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

    User userA;
    userA.setUsername("jaka");
    userA.setPassword("jaka123");

    UserModel uModel;

    cout<<uModel.insertUser(userA);

    LaboratoriumModel labMdl;
    labMdl.getLaboratoriumData();
    while(labMdl.getData->next())
    {
        cout<<labMdl.getData->value(1).toString().toStdString();
    }

    Peminjaman pjm;
//    pjm.setnamaPeminjam("sss");
//    pjm.setnimPeminjam("32");
//    pjm.setTanggal("2022-02-22");
//    pjm.setidStatus(2);
//    pjm.setidLab(4);
//    pjm.setjamStart("09:30");
//    pjm.setjamEnd("12:00");
//    pjm.setKeperluan("GDSC");

    PeminjamanModel pjmMdl;
//    pjmMdl.pinjamLab(pjm);



    //Edit

    pjm.setnamaPeminjam("George");
    pjm.setnimPeminjam("21041110043");
    pjm.setidStatus(2);
    pjm.setidLab(3);
    pjm.setjamStart("09:30");
    pjm.setjamEnd("12:00");
    pjm.setKeperluan("UTM Competition");
    pjm.setidPeminjaman(2);
    pjmMdl.editPinjamLab(pjm);


    return a.exec();
}

//void MainWindow::handleButton()
//{
//  // change the text
//  m_button->setText("Example");
//  // resize button
//  m_button->resize(100,100);
//}
