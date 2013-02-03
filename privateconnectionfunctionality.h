#ifndef PRIVATECONNECTIONFUNCTIONALITY_H
#define PRIVATECONNECTIONFUNCTIONALITY_H

//Класс, который реализует функционал, присущий персонально каждому соединению

#include <connection.h>

#include <QObject>

class PrivateConnectionFunctionality : public QObject
{
    Q_OBJECT

public:
    PrivateConnectionFunctionality();

    PrivateConnectionFunctionality(QObject *parent);

    //Адрес соединения, к которому присоединен функционал
    Connection* connection;

    //Возвращает адрес соединения:
    Connection* getConnection();
};

#endif // PRIVATECONNECTIONFUNCTIONALITY_H
