#ifndef MANAGEMENTPEMINJAMAN_H
#define MANAGEMENTPEMINJAMAN_H

#include <QDialog>

namespace Ui {
class ManagementPeminjaman;
}

class ManagementPeminjaman : public QDialog
{
    Q_OBJECT

public:
    explicit ManagementPeminjaman(QWidget *parent = nullptr);
    ~ManagementPeminjaman();

private:
    Ui::ManagementPeminjaman *ui;
};

#endif // MANAGEMENTPEMINJAMAN_H
