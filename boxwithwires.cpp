#include "boxwithwires.h"

BoxWithWires::BoxWithWires(QObject *parent)
    : QObject(parent)
{
    //Установка глобального состояния:
    GlobalCondition::needMorePeers=true;

    //Создание сервера:
    server= new Server();
    if (!server->listen()) {
        qDebug() << "Server:Failed to bind to port";
    }
    connect(server,SIGNAL(newConnection(QTcpSocket*)),this,SLOT(createConnectionWithSocket(QTcpSocket*)));
    qDebug()<<"Server started at port:"<<server->serverPort();
    GlobalCondition::serverPort=server->serverPort();

    //Создание p2p функционала:
    p2pOrganizer= new P2POrganizer(this);
    connect(p2pOrganizer,SIGNAL(newKnownPeer(QString,int)),this,SLOT(addNewKnownPeer(QString,int)));
}

int BoxWithWires::coutConnections(){
    return connections.count();
}

void BoxWithWires::createConnection(QString ip, int port){
    connections.append(new Connection(ip,port));
    addStandartFunctionality(connections[connections.count()-1],true);
}

void BoxWithWires::createConnectionWithSocket(QTcpSocket* socket){
    connections.append(new Connection(socket));
    addStandartFunctionality(connections[connections.count()-1],false);
}

Connection* BoxWithWires::getConnection(int number){
    return(connections[number]);
}

void BoxWithWires::addStandartFunctionality(Connection* _connection,bool connectionInitialiser){
    privateConnectionFunctionalities.append(new SocialRelationsManager(_connection,connectionInitialiser));
    p2pOrganizer->addConnection(_connection);
}

void BoxWithWires::addNewKnownPeer(QString ip, int port){
    knownPeers.append(new KnownPeer(ip,port));
}
