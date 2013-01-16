#ifndef PRIVATECONNECTIONFUNCTIONALITY_H
#define PRIVATECONNECTIONFUNCTIONALITY_H

//Класс, который реализует функционал, присущий персонально каждому соединению

#include <connection.h>

class PrivateConnectionFunctionality
{
public:
    PrivateConnectionFunctionality();

    //Адрес соединения, к которому присоединен функционал
    Connection* connection;
};

#endif // PRIVATECONNECTIONFUNCTIONALITY_H
