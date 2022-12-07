QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    laboratorium.cpp \
    main.cpp \
    mainwindow.cpp \
    homepage.cpp \
    login.cpp

HEADERS += \
    Auth.hpp \
    KoneksiDb.hpp \
    Laboratorium.hpp \
    Peminjaman.hpp \
    User.hpp \
    UserModel.hpp \
    laboratoriumModel.hpp \
    mainwindow.h \
    peminjamanModel.hpp \
    homepage.h \
    login.h \
    database.h

FORMS += \
    daftarPeminjamanLab.ui \
    login.ui \
    mainwindow.ui \
    manajemenPeminjaman.ui \
    homepage.ui \
    login.ui

TRANSLATIONS += \
    peminjamanLab_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
