#ifndef BOXWITHWIRES_H
#define BOXWITHWIRES_H

//Хранит в себе все соединения.

#include <connection.h>
#include <server.h>

#include <QVector>
#include <QString>

class BoxWithWires
{
private:
    //Все соединения:
    QVector<Connection* > connections;

public:
    BoxWithWires();

    //Получить адрес соединения:
    Connection* getConnection(int number);

    //Удалить соединение:
    void removeConnection(int number);

    //Создать соединение с конкретным адресатом:
    void createConnection(QString ip, int port);
};

#endif // BOXWITHWIRES_H
