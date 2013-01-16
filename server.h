#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
signals:
    void newConnection(QTcpSocket* newSocket);
private:
    void incomingConnection(int socketId);
};


#endif // SERVER_H
