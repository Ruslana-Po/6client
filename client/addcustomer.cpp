#include "addcustomer.h"
#include "ui_addcustomer.h"
#include "header.h"

addCustomer::addCustomer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addCustomer)
{
    ui->setupUi(this);
}

addCustomer::~addCustomer()
{
    delete ui;
}

void addCustomer::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    string mess = "addCustomer "+text.toStdString();
    string answer = Connect(mess);
    if(answer=="Покупатель добавлен"){
        ui->textBrowser->setText(QString::fromStdString(answer));
    }else{
        ui->textBrowser->setText(QString::fromStdString("Произошла ошибка"));
    }
}

