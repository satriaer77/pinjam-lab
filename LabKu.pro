QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    daftar.cpp \
    detailpeminjaman.cpp \
    homepage.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    managementpeminjaman.cpp \
    peminjam.cpp \
    permintaan.cpp \
    suntingpeminjaman.cpp

HEADERS += \
    daftar.h \
    database.h \
    detailpeminjaman.h \
    homepage.h \
    login.h \
    mainwindow.h \
    managementpeminjaman.h \
    peminjam.h \
    permintaan.h \
    suntingpeminjaman.h

FORMS += \
    daftar.ui \
    detailpeminjaman.ui \
    homepage.ui \
    login.ui \
    mainwindow.ui \
    managementpeminjaman.ui \
    peminjam.ui \
    permintaan.ui \
    suntingpeminjaman.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
