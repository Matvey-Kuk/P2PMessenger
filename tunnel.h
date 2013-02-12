#ifndef TUNNEL_H
#define TUNNEL_H

//Содержит в себе данные о туннеле

#include <QString>
#include <QVector>

#include <knownpeer.h>

class Tunnel
{
private:
    //Необходимое колличество роутеров:
    int needRoutersNumber;

    //Массив данных о роутерах:
    QVector<KnownPeer* > routers;

public:
    Tunnel();

    Tunnel(KnownPeer* firstPeer);

    //Добавить данные об известном роутере:
    void addRouterData(KnownPeer*);

    //Получить данные о роутере по номеру:
    KnownPeer* getRouter(int number);

    //Получить колличество роутеров:
    int getRoutersNumber();

    //Получить необходимое колличество роутеров: зачем?
    int getNeedRoutersNumber();
};

#endif // TUNNEL_H
