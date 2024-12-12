#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>

namespace Ui {
class addProduct;
}

class addProduct : public QDialog
{
    Q_OBJECT

public:
    explicit addProduct(QWidget *parent = nullptr);
    ~addProduct();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addProduct *ui;
};

#endif // ADDPRODUCT_H
