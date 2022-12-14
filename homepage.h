#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QDialog>
#include "database.h"
#include "Laboratorium.hpp"
#include "laboratoriumModel.hpp"

namespace Ui {
class HomePage;
}

class HomePage : public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private:
    Ui::HomePage *ui;
    Database database;
    Laboratorium *lab;
    LaboratoriumModel *labModel;



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // HOMEPAGE_H
