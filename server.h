#ifndef SERVER_H
#define SERVER_H

//Класс сервера, ждет соединения и отдает их для создания объектов

#include <QTcpServer>

class Server : public QTcpServer
{
public:
    Server();
};

#endif // SERVER_H
