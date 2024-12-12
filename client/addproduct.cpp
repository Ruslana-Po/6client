#include "addproduct.h"
#include "ui_addproduct.h"
#include "header.h"

addProduct::addProduct(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addProduct)
{
    ui->setupUi(this);
}

addProduct::~addProduct()
{
    delete ui;
}

void addProduct::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    string mess = "addProduct "+text.toStdString();
    string answer = Connect(mess);
    ui->textBrowser->setText(QString::fromStdString(answer));
}

