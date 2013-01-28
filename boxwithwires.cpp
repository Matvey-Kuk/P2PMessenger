#include "boxwithwires.h"

static const int upInterval=10*1000;

BoxWithWires::BoxWithWires(QObject *parent)
    : QObject(parent)
{
    //Таймер:
    upTimer.setInterval(upInterval);
    QObject::connect(&upTimer, SIGNAL(timeout()), this,SLOT(up()));
    upTimer.start();

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

void BoxWithWires::up(){
    bool allConnectionsAreReady=true;
    for( int j=0 ; j < connections.count() ; j++ ){
        if(connections[j]->getPort()<0) allConnectionsAreReady=false;
        if(!connections[j]->connectionEstablished()) allConnectionsAreReady=false;
    }

    if(connections.count()<10 && allConnectionsAreReady==true){
        for( int i = 0 ; i < knownPeers.count() ; i++ ){
            bool okPeer=true;
            for( int j=0 ; j < connections.count() ; j++ ){
                if(connections[j]->getIp()==knownPeers[i]->ip && connections[j]->getPort()==knownPeers[i]->port){
                    okPeer=false;
                }
            }
            if(knownPeers[i]->port==GlobalCondition::serverPort){//TODO: научиться находить себя более логичным методом
                okPeer=false;
            }
            if(okPeer) {
                createConnection(knownPeers[i]->ip,knownPeers[i]->port);
            }
        }
    }
}
