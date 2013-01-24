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
}

void P2POrganizer::dataReciever(QString commandTypePrefix, QString message, Connection* fromConnection){
    if(commandTypePrefix=="p2p"){
        qDebug()<<"p2p recieved:"<<message;
    }
}

void P2POrganizer::up(){
    for(int i=0; i<connections.count(); i++){
        qDebug()<<"P2P welcomed.";
        connections[i]->sendData("p2p","Hello P2P!");
    }
}
