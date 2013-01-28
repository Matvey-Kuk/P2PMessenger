#include "p2porganizer.h"

static const int upInterval = 3 * 1000;

P2POrganizer::P2POrganizer(QObject* parent=0){
    upTimer.setInterval(upInterval);
    QObject::connect(&upTimer, SIGNAL(timeout()), this,SLOT(up()));
    upTimer.start();
}

void P2POrganizer::addConnection(Connection* _connection){
    connections.append(_connection);
    connect(_connection,SIGNAL(recievedData(QString,QString,Connection*)),this,SLOT(dataReciever(QString,QString,Connection*)));

    tellAboutANumberOfPeers(10,_connection);
    //Установка первоначальных данных
    _connection->askingPeers=false;
    _connection->sendingPeers=false;
    _connection->saidAboutIt=false;
}

void P2POrganizer::dataReciever(QString commandTypePrefix, QString message, Connection* fromConnection){
    if(commandTypePrefix=="p2p"){
        qDebug()<<"p2p recieved:"<<message;
        if(message=="morePeers") fromConnection->askingPeers=true;
        if(message=="noMorePeers") fromConnection->askingPeers=false;
    }
    if(commandTypePrefix=="newPeer"){
        qDebug()<<"newPeer:"<<message;
        checkNewPeer(message.section(':',0,0),message.section(':',1,-1).toInt());
    }
}

void P2POrganizer::up(){
    //Запрос новых пиров если нужно
    for(int i=0; i<connections.count(); i++){
        if(GlobalCondition::needMorePeers!=connections[i]->sendingPeers){
            if( GlobalCondition::needMorePeers ){
                connections[i]->sendData("p2p","morePeers");
            } else {
                connections[i]->sendData("p2p","noMorePeers");
            }
            connections[i]->sendingPeers=GlobalCondition::needMorePeers;
        }
    }

    //Рассказывает о новых пирах
    for(int i=0; i<connections.count(); i++){
        if( (!connections[i]->saidAboutIt) && connections[i]->getPort()>0 ){
            connections[i]->saidAboutIt=true;
            for(int j=0; j<connections.count(); j++){
                if(connections[j]->askingPeers && i!=j){
                    connections[j]->sendData("newPeer",connections[i]->getIp()+":"+QString::number(connections[i]->getPort()));
                }
            }
        }
    }

}

void P2POrganizer::tellAboutANumberOfPeers(int number, Connection* target){
    for(int i=0; i<connections.count(); i++){
        if(target!=connections[i] && i<number && connections[i]->getPort()>0){
            target->sendData("newPeer",connections[i]->getIp()+":"+QString::number(connections[i]->getPort()));
        }
    }
}

void P2POrganizer::checkNewPeer(QString ip, int port){
    emit newKnownPeer(ip,port);
}
