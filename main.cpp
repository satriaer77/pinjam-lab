#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "UserModel.hpp"


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

    uModel.insertUser(userA);

    return a.exec();
}

//void MainWindow::handleButton()
//{
//  // change the text
//  m_button->setText("Example");
//  // resize button
//  m_button->resize(100,100);
//}
