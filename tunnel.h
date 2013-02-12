#ifndef TUNNEL_H
#define TUNNEL_H

//�������� � ���� ������ � �������

#include <QString>
#include <QVector>

#include <knownpeer.h>

class Tunnel
{
private:
    //����������� ����������� ��������:
    int needRoutersNumber;

    //������ ������ � ��������:
    QVector<KnownPeer* > routers;

public:
    Tunnel();

    Tunnel(KnownPeer* firstPeer);

    //�������� ������ �� ��������� �������:
    void addRouterData(KnownPeer*);

    //�������� ������ � ������� �� ������:
    KnownPeer* getRouter(int number);

    //�������� ����������� ��������:
    int getRoutersNumber();

    //�������� ����������� ����������� ��������: �����?
    int getNeedRoutersNumber();
};

#endif // TUNNEL_H
