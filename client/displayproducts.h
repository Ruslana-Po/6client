#ifndef DISPLAYPRODUCTS_H
#define DISPLAYPRODUCTS_H

#include <QDialog>

namespace Ui {
class displayProducts;
}

class displayProducts : public QDialog
{
    Q_OBJECT

public:
    explicit displayProducts(QWidget *parent = nullptr);
    ~displayProducts();

private slots:
    void on_pushButton_clicked();

private:
    Ui::displayProducts *ui;
};

#endif // DISPLAYPRODUCTS_H
