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
    addStandartPrivateFunctionality(connections[connections.count()-1]);
}

void BoxWithWires::createConnectionWithSocket(QTcpSocket* socket){
    connections.append(new Connection(socket));
    addStandartPrivateFunctionality(connections[connections.count()-1]);
}

Connection* BoxWithWires::getConnection(int number){
    return(connections[number]);
}

void BoxWithWires::addStandartPrivateFunctionality(Connection* _connection){
    privateConnectionFunctionalities.append(new SocialRelationsManager(_connection));
}
