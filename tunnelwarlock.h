#ifndef TUNNELWARLOCK_H
#define TUNNELWARLOCK_H

//����� �������� �� ����������� �������� �� ������������ �����������
//, ������������ ���� �������� � ������������� ��������.

#include <connection.h>
#include <globalcondition.h>
#include <tunnel.h>

#include <QVector>
#include <QTimer>

class TunnelWarlock: public QObject
{
    Q_OBJECT

public:
    TunnelWarlock(QObject *parent);

    //�������� ���������� � ����������:
    void addConnection(Connection* _connection);

    //������� ���������� �� �����������:
    void removeConnection(Connection* _connection);

private slots:
    //�������� ������ �� ����������
    void dataReciever(QString commandTypePrefix, QString message, Connection *fromConnection);

    //���������� �� �������
    void up();

private:
    //��� �������
    QVector<Tunnel*> tunnels;

    //��� ����������:
    QVector<Connection* > connections;

    //������ ���������� ���������
    QTimer upTimer;

    //������� �������
    void makeTunnel();
};

#endif // TUNNELWARLOCK_H
