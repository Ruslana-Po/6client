#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include <QDialog>

namespace Ui {
class addCustomer;
}

class addCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit addCustomer(QWidget *parent = nullptr);
    ~addCustomer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addCustomer *ui;
};

#endif // ADDCUSTOMER_H
