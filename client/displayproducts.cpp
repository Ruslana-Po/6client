#include "displayproducts.h"
#include "ui_displayproducts.h"
#include"header.h"

displayProducts::displayProducts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::displayProducts)
{
    ui->setupUi(this);
}

displayProducts::~displayProducts()
{
    delete ui;
}

void displayProducts::on_pushButton_clicked()
{
    string mess = "displayProducts";
    string answer = Connect(mess);
    ui->textBrowser->setText(QString::fromStdString(answer));
}

