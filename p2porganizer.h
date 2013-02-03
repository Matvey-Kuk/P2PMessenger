#ifndef P2PORGANIZER_H
#define P2PORGANIZER_H

//����� �������� �� ����������� ���������� � ������, ��������� ����� � �������.

#include <connection.h>
#include <globalcondition.h>

#include <QVector>
#include <QTimer>

class P2POrganizer: public QObject
{
    Q_OBJECT

public:
    P2POrganizer(QObject *parent);

    //��������� ����������� �����������
    void addConnection(Connection* _connection);

    //������� ���������� �� �����������:
    void removeConnection(Connection* _connection);

    //��������� �� ������� � ���������:
    //BoxWithWires* boxWithWires;

private slots:
    //�������� ������ �� ����������
    void dataReciever(QString commandTypePrefix, QString message, Connection *fromConnection);

    //���������� �� �������
    void up();

signals:
    //���������������� ������ ����������� ����
    void newKnownPeer(QString ip, int port);

private:
    //��� ����������:
    QVector<Connection* > connections;

    //������ ���������� ���������
    QTimer upTimer;

    //���������� � ���������� ����� �� ����������
    void tellAboutANumberOfPeers(int number, Connection* target);

    //�������� ���� � ��������� ������� � ��� �����������
    void checkNewPeer(QString ip, int port);

};

#endif // P2PORGANIZER_H
