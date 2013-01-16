#ifndef CONNECTION_H
#define CONNECTION_H

//Непосредственно, соединение.

class Connection
{
private:

    //Функционирует ли в данный момент соединение
    bool isConnected();

    //Соккет, через который идет передача данных
    QTcpSocket* tcpSocket;

public:
    Connection();

    //Создать соединение с конкретным сокетом
    Connection();
};

#endif // CONNECTION_H
