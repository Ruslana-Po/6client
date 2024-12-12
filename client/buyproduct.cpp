#include "buyproduct.h"
#include "ui_buyproduct.h"
#include "header.h"
buyProduct::buyProduct(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::buyProduct)
{
    ui->setupUi(this);
}

buyProduct::~buyProduct()
{
    delete ui;
}

void buyProduct::on_pushButton_clicked()
{
    string filename="cheque.txt";
    QString text = ui->lineEdit->text();
    string mess = "buyProduct "+text.toStdString();
    string answer = Connect(mess);
    if(answer=="Ошибка: Покупатель не найден"){
        ui->textBrowser->setText(QString::fromStdString(answer));
    }else if(answer=="Ошибка: Товар не найден"){
        ui->textBrowser->setText(QString::fromStdString(answer));
    }else if(answer=="Ошибка: Недостаточно товара на складе"){
        ui->textBrowser->setText(QString::fromStdString(answer));
    }else if(answer=="Ошибка: Недостаточно средств на балансе"){
        ui->textBrowser->setText(QString::fromStdString(answer));
    }else{
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла для записи: " << filename << endl;
            return;
        }
        file<<answer;
        file.close();
        // Открываем текстовый файл с помощью системной команды
        string command = "xdg-open " + filename;
        system(command.c_str());

    }

}

