#include "privateconnectionfunctionality.h"

PrivateConnectionFunctionality::PrivateConnectionFunctionality(QObject *parent)
    : QObject(parent)
{
}

PrivateConnectionFunctionality::PrivateConnectionFunctionality(){

}

Connection* PrivateConnectionFunctionality::getConnection(){
    return connection;
}
