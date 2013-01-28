#include "knownpeer.h"

KnownPeer::KnownPeer(QObject *parent) :
    QObject(parent)
{
}

KnownPeer::KnownPeer(QString _ip, int _port){
    ip=_ip;
    port=_port;
}
