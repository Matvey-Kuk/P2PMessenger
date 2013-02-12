#include "tunnelwarlock.h"

static const int upInterval = 3 * 1001;
static const int outTunnelsNeedNumber = 1;

TunnelWarlock::TunnelWarlock(QObject *parent=0)
{
    upTimer.setInterval(upInterval);
    QObject::connect(&upTimer, SIGNAL(timeout()), this,SLOT(up()));
    upTimer.start();
}

void TunnelWarlock::addConnection(Connection* _connection){
    connections.append(_connection);
    connect(_connection,SIGNAL(recievedData(QString,QString,Connection*)),this,SLOT(dataReciever(QString,QString,Connection*)));
}

void TunnelWarlock::removeConnection(Connection *_connection){
    for( int i=0 ; i<connections.count() ; i++ ){
        if(connections[i]==_connection){
            connections.remove(i);
        }
    }
}

void TunnelWarlock::dataReciever(QString commandTypePrefix, QString message, Connection* fromConnection){
    if(commandTypePrefix=="tunnel"){
        qDebug()<<"tunnelWarloc recieved:"<<message;
    }
}

void TunnelWarlock::up(){
    for(int i=0;i<connections.count();i++){
        connections[i]->sendData("tunnel","hello tunnel");
    }
}

void TunnelWarlock::makeTunnel(){
    //»щем незан€тый коннект с минимальным пингом:
    for( int i = 0 ; i < connections.count() ; i++ ){
        bool connectionIsFree=true;
        for( int j = 0 ; j < tunnels.count() ; j++ ){
            if( (connections[i]->getPort() > 0) && (connections[i]->getPort()==tunnels[j]->getRouter(0)->getPort()) && (connections[i]->getIp()==tunnels[j]->getRouter(0)->getIp()) ){
                connectionIsFree=false;
            }
        }
        if(connectionIsFree){
            tunnels.append(new Tunnel());
        }
    }
}
