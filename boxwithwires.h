#ifndef BOXWITHWIRES_H
#define BOXWITHWIRES_H

//Хранит в себе все соединения.

#include <connection.h>
#include <server.h>

#include <QObject>
#include <QVector>
#include <QString>

class BoxWithWires : public QObject
{
    Q_OBJECT

private:
    //Все соединения:
    QVector<Connection* > connections;

    //Сервер:
    Server* server;

private slots:

    //Создает соединение, которое получает от сервера
    void createConnectionWithSocket(QTcpSocket* socket);

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
