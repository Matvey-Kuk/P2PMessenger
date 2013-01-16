#include "socialrelationsmanager.h"

SocialRelationsManager::SocialRelationsManager(QObject *parent)
{

}

SocialRelationsManager::SocialRelationsManager(Connection* _connection)
{
    connection=_connection;
    connect(connection,SIGNAL(recievedData(QString,QString)),this,SLOT(dataReciever(QString,QString)));

    pingTimer.setInterval(5*1000);
    QObject::connect(&pingTimer, SIGNAL(timeout()), this,SLOT(sendPing()));
    pingTimer.start();

    qDebug()<<"Created SocialRelationsManager for concrete connection.";
}

void SocialRelationsManager::dataReciever(QString commandTypePrefix, QString message){
    if(commandTypePrefix=="ping"){
        qDebug()<<"Recieved ping message:"<<message;
    }
}

void SocialRelationsManager::sendPing(){
    connection->sendData("ping","HELLO PING!");
    qDebug()<<"Ping message sent.";
}
