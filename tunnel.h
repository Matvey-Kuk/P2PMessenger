#ifndef TUNNEL_H
#define TUNNEL_H

//�������� � ���� ������ � �������

#include <QString>
#include <QVector>

#include <knownpeer.h>

class tunnel
{
private:
    //����������� ����������� ��������:
    int needRoutersNumber;

    //������ ������ � ��������:
    QVector<KnownPeer* > reuters;

public:
    tunnel();

    //�������� ������ �� ��������� �������:
    void addRouterData(KnownPeer*);

    //�������� ������ � ������� �� ������:
    KnownPeer* getRouter(int number);

    //�������� ����������� ��������:
    int getRoutersNumber();

    //�������� ����������� ����������� ��������:
    int getNeedRoutersNumber();
};

#endif // TUNNEL_H
