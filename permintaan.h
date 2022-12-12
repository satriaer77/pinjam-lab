#ifndef PERMINTAAN_H
#define PERMINTAAN_H

#include <QDialog>

namespace Ui {
class permintaan;
}

class permintaan : public QDialog
{
    Q_OBJECT

public:
    explicit permintaan(QWidget *parent = nullptr);
    ~permintaan();

private:
    Ui::permintaan *ui;
};

#endif // PERMINTAAN_H
