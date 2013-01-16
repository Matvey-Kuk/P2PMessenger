#ifndef BOXWITHWIRES_H
#define BOXWITHWIRES_H

//������ � ���� ��� ����������.

#include <connection.h>
#include <server.h>

#include <QVector>
#include <QString>

class BoxWithWires
{
private:
    //��� ����������:
    QVector<Connection* > connections;

public:
    BoxWithWires();

    //�������� ����� ����������:
    Connection* getConnection(int number);

    //������� ����������:
    void removeConnection(int number);

    //������� ���������� � ���������� ���������:
    void createConnection(QString ip, int port);
};

#endif // BOXWITHWIRES_H
