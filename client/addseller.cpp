#include "addseller.h"
#include "ui_addseller.h"
#include "header.h"

AddSeller::AddSeller(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSeller)
{
    ui->setupUi(this);
}

AddSeller::~AddSeller()
{
    delete ui;
}

//
void AddSeller::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    string mess = "addSeller "+text.toStdString();
    string answer = Connect(mess);
    if(answer=="Продавец добавлен"){
         ui->textBrowser->setText(QString::fromStdString(answer));
    }else{
        ui->textBrowser->setText(QString::fromStdString("Произошла ошибка"));
    }
}

