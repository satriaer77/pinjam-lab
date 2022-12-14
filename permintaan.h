#ifndef PERMINTAAN_H
#define PERMINTAAN_H

#include <QDialog>
#include "database.h"
#include <QSqlQuery>

namespace Ui {
class permintaan;
}

class permintaan : public QDialog
{
    Q_OBJECT

public:
    explicit permintaan(QWidget *parent = nullptr);
    ~permintaan();



private slots:
    void on_pushButton_2_clicked();

private:
    Ui::permintaan *ui;
    Database database;
};

#endif // PERMINTAAN_H
