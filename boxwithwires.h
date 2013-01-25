#ifndef BOXWITHWIRES_H
#define BOXWITHWIRES_H

//������ � ���� ��� ����������.

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
    //��� ����������:
    QVector<Connection* > connections;

    //��������� ����:
    QVector<KnownPeer* > knownPeers;

    //������:
    Server* server;

    //P2P ����������
    P2POrganizer* p2pOrganizer;

    //��������� ���������� ��� ������� ����������:
    QVector<PrivateConnectionFunctionality* > privateConnectionFunctionalities;

    //��������� ����������� ��������� ���������� ����������:
    void addStandartFunctionality(Connection* _connection, bool connectionInitialiser);

private slots:
    //������� ����������, ������� �������� �� �������
    void createConnectionWithSocket(QTcpSocket* socket);

    //�������� ������ ���������� ����:
    void addNewKnownPeer(QString ip, int port);

public:
    BoxWithWires(QObject *parent);

    //�������� ����������:
    Connection* getConnection(int number);

    //�������� ����������� ����������
    int coutConnections();

    //������� ����������:
    void removeConnection(int number);

    //������� ���������� � ���������� ���������:
    void createConnection(QString ip, int port);
};

#endif // BOXWITHWIRES_H
