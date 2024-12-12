#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"header.h"
#include"addseller.h"
#include "addproduct.h"
#include "addcustomer.h"
#include "displayproducts.h"
#include "buyproduct.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void ErrorOrNo(int meaning) {
    if (meaning < 0) {
        cerr << "Error\n";
        exit(0);
    }
}

void sendRequest(int socket, const string& request) {
    char buffer[MAX_SIZE_BUF];
    for(int i=0;i<request.length();i++){
        buffer[i]=request[i];
    }
    buffer[request.length()]='\0';
    send(socket, buffer, MAX_SIZE_BUF, 0);
}

string receiveResponse(int socket) {
    char buffer[MAX_SIZE_BUF];
    int bytes_received = recv(socket, buffer, MAX_SIZE_BUF, 0);
    if (bytes_received <= 0) {
        cerr << "Ошибка при получении ответа от сервера." << endl;
        exit(1);
    }
    buffer[bytes_received] = '\0';
    return string(buffer);
}

string Connect(string text) {
    int client;
    struct sockaddr_in server_address;

    client = socket(AF_INET, SOCK_STREAM, 0);
    ErrorOrNo(client);

    server_address.sin_port = htons(NUMBER_PORT);
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

    int ret = connect(client, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address));
    ErrorOrNo(ret);

    cout << "Подключено к серверу." << endl;
    sendRequest(client, text);
    string mess=receiveResponse(client);
    //close(client);
    return mess;
}

void MainWindow::on_pushButton_clicked()
{
    AddSeller window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    addProduct window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    addCustomer window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    displayProducts window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    buyProduct window;
    window.setModal(true);
    window.exec();
}

