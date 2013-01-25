#include "socialrelationsmanager.h"

static const int PingInterval = 10 * 1000;

SocialRelationsManager::SocialRelationsManager(QObject *parent)
{

}

SocialRelationsManager::SocialRelationsManager(Connection* _connection, bool connectionInitialiser)
{
    isConnectionInitialiser=connectionInitialiser;
    connection=_connection;
    connect(connection,SIGNAL(recievedData(QString,QString,Connection*)),this,SLOT(dataReciever(QString,QString,Connection*)));

    pingTimer.setInterval(PingInterval);
    QObject::connect(&pingTimer, SIGNAL(timeout()), this,SLOT(sendPing()));
    if(isConnectionInitialiser)pingTimer.start();

    //Устновка начальных данных:
    //Порт не известен
    _connection->setPort(-1);
}

void SocialRelationsManager::dataReciever(QString commandTypePrefix, QString message, Connection *fromConnection){
    if(commandTypePrefix=="ping"){
        if ( message == "PING" ) {
            connection->sendData("ping","PONG");
            pongTime.restart();
            portCheckUp();
        }
        if ( message == "PONG" ) {
            connection->sendData("ping","PING2");
            connection->pingTime=pongTime.elapsed();
            qDebug()<<"Ping:"<<connection->pingTime;
        }
        if ( message == "PING2" ){
            connection->pingTime=pongTime.elapsed();
            qDebug()<<"Ping:"<<connection->pingTime;
        }
    }

    if(commandTypePrefix=="port"){
        qDebug()<<"port message:"<<message;
        if( message == "request" ){
            connection->sendData("port",QString::number(GlobalCondition::serverPort));
        } else {
            fromConnection->setPort(message.toInt());
        }
    }
}

void SocialRelationsManager::sendPing(){
    connection->sendData("ping","PING");
    pongTime.restart();
    portCheckUp();
}

void SocialRelationsManager::portCheckUp(){
    if(connection->getPort()<0) connection->sendData("port","request");
}
