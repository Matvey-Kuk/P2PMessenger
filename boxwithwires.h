#ifndef BOXWITHWIRES_H
#define BOXWITHWIRES_H

//Хранит в себе все соединения.

#include <connection.h>
#include <server.h>
#include <socialrelationsmanager.h>
#include <publicconnectionfunctional.h>
#include <privateconnectionfunctionality.h>
#include <p2porganizer.h>
#include <globalcondition.h>
#include <knownpeer.h>

#include <QObject>
#include <QVector>
#include <QString>

class BoxWithWires : public QObject
{
    Q_OBJECT

private:
    //Все соединения:
    QVector<Connection* > connections;

    //Известные пиры:
    QVector<KnownPeer* > knownPeers;

    //Сервер:
    Server* server;

    //P2P функционал
    P2POrganizer* p2pOrganizer;

    //Приватный функционал для каждого соединения:
    QVector<PrivateConnectionFunctionality* > privateConnectionFunctionalities;

    //Добавляет стандартный приватный функционал соединению:
    void addStandartFunctionality(Connection* _connection, bool connectionInitialiser);

private slots:
    //Создает соединение, которое получает от сервера
    void createConnectionWithSocket(QTcpSocket* socket);

    //Добавить нового известного пира:
    void addNewKnownPeer(QString ip, int port);

public:
    BoxWithWires(QObject *parent);

    //Получить соединение:
    Connection* getConnection(int number);

    //Получить колличество соединений
    int coutConnections();

    //Удалить соединение:
    void removeConnection(int number);

    //Создать соединение с конкретным адресатом:
    void createConnection(QString ip, int port);
};

#endif // BOXWITHWIRES_H
