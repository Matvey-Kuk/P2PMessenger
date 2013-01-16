#include "boxwithwires.h"

BoxWithWires::BoxWithWires(QObject *parent)
    : QObject(parent)
{
    //Создание сервера:
    server= new Server();
    if (!server->listen()) {
        qDebug() << "Server:Failed to bind to port";
    }
    connect(server,SIGNAL(newConnection(QTcpSocket*)),this,SLOT(createConnectionWithSocket(QTcpSocket*)));
    qDebug()<<"Server started at port:"<<server->serverPort();

}

int BoxWithWires::coutConnections(){
    return connections.count();
}

void BoxWithWires::createConnection(QString ip, int port){
    connections.append(new Connection(ip,port));
}

void BoxWithWires::createConnectionWithSocket(QTcpSocket* socket){
    connections.append(new Connection(socket));
}

Connection* BoxWithWires::getConnection(int number){
    return(connections[number]);
}

