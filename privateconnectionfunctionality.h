#ifndef PRIVATECONNECTIONFUNCTIONALITY_H
#define PRIVATECONNECTIONFUNCTIONALITY_H

//�����, ������� ��������� ����������, �������� ����������� ������� ����������

#include <connection.h>

#include <QObject>

class PrivateConnectionFunctionality : public QObject
{
    Q_OBJECT

public:
    PrivateConnectionFunctionality();

    PrivateConnectionFunctionality(QObject *parent);

    //����� ����������, � �������� ����������� ����������
    Connection* connection;

    //���������� ����� ����������:
    Connection* getConnection();
};

#endif // PRIVATECONNECTIONFUNCTIONALITY_H
