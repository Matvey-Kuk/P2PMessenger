#include <QtCore>

#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
}

void Server::incomingConnection(int socketId)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketId);
    emit newConnection(socket);
}
