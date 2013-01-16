#ifndef BOXWITHWIRES_H
#define BOXWITHWIRES_H

//������ � ���� ��� ����������.

#include <connection.h>
#include <server.h>

#include <QObject>
#include <QVector>
#include <QString>

class BoxWithWires : public QObject
{
    Q_OBJECT

private:
    //��� ����������:
    QVector<Connection* > connections;

    //������:
    Server* server;

private slots:

    //������� ����������, ������� �������� �� �������
    void createConnectionWithSocket(QTcpSocket* socket);

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
