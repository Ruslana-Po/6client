#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>


#define SERVER_IP "127.0.0.1"
#define NUMBER_PORT 1614
#define MAX_SIZE_BUF 10000

using namespace std;
string Connect(string text);
#endif // HEADER_H
