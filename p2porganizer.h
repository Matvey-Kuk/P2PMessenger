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

private slots:
    //�������� ������ �� ����������
    void dataReciever(QString commandTypePrefix, QString message, Connection *fromConnection);

    //���������� �� �������
    void up();

private:

    //��� ����������:
    QVector<Connection* > connections;

    //������ ���������� ���������
    QTimer upTimer;

};

#endif // P2PORGANIZER_H
