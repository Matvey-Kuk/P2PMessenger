#ifndef CONNECTION_H
#define CONNECTION_H

//���������������, ����������.

#include <QString>
#include <QTcpSocket>
#include <QObject>
#include <QHostAddress>

class Connection : public QObject
{
    Q_OBJECT

private:

    //���� ����
    int port;

    //������������� �� � ������ ������ ����������:
    bool isConnected();

    //������, ����� ������� ���� �������� ������:
    QTcpSocket* tcpSocket;

    //������ ���������� ����� (����� ���������� �������� ������):
    quint16 nextBlockSize;

    //�������������� ��� �������� ����������:
    void initializator();

    void closeConnection();

private slots:

    void connected();

    void disconnected();

    void reading();

    void error();

signals:

    //����� ���������� �������� ����� ������. �������- ������ ����������� ��� ����������.
    void recievedData(QString commandTypePrefix, QString message, Connection* fromConnection);

public:

    explicit Connection(QObject* parent=0);

    //������� ���������� � ���������� �����
    explicit Connection(QString ip, int port);

    //������� ���������� � ���������� �������
    explicit Connection(QTcpSocket* concreteSocket);

    //��������� ������. �������- ������ ����������� �� ���������.
    void sendData(QString commandTypePrefix, QString message);

    //�������� ip
    QString getIp();

    //�������� port
    int getPort();

    //���������� port
    void setPort(int _port);

    //************************************
    //������, ����������� ������������:
    //************************************

    //public relations manager
    int pingTime;
    //p2p organizer
    bool askingPeers;//�������� �� �� �����
    bool sendingPeers;//�������� �� � ���� �����
    bool saidAboutIt;//��������� �� ��� ����� ���� ���������

};

#endif // CONNECTION_H
