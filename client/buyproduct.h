#ifndef BUYPRODUCT_H
#define BUYPRODUCT_H

#include <QDialog>

namespace Ui {
class buyProduct;
}

class buyProduct : public QDialog
{
    Q_OBJECT

public:
    explicit buyProduct(QWidget *parent = nullptr);
    ~buyProduct();

private slots:
    void on_pushButton_clicked();

private:
    Ui::buyProduct *ui;
};

#endif // BUYPRODUCT_H
