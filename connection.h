#ifndef CONNECTION_H
#define CONNECTION_H

//���������������, ����������.

class Connection
{
private:

    //������������� �� � ������ ������ ����������
    bool isConnected();

    //������, ����� ������� ���� �������� ������
    QTcpSocket* tcpSocket;

public:
    Connection();

    //������� ���������� � ���������� �������
    Connection();
};

#endif // CONNECTION_H
