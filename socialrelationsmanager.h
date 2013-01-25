#ifndef SOCIALRELATIONSMANAGER_H
#define SOCIALRELATIONSMANAGER_H

//�����, ���������� �� ���������� � ������ ����.
//��������� �������
//����������� ����������� ������ �� ��������� ����������

#include <privateconnectionfunctionality.h>
#include <globalcondition.h>

#include <QTimer>
#include <QTime>
#include <QObject>
#include <QString>

class SocialRelationsManager : public PrivateConnectionFunctionality
{
    Q_OBJECT

private:

    //�������� ����:
    QTimer pingTimer;

    //����� �� ����� ����:
    QTime pongTime;

    //�������� �� ��������������� ����������:
    bool isConnectionInitialiser;

    //�������� ����������� ����� ����
    void portCheckUp();

public:

    SocialRelationsManager(QObject *parent);

    SocialRelationsManager(Connection *_connection, bool connectionInitialiser);

private slots:

    //������������ ���������� ������
    void dataReciever(QString commandTypePrefix, QString message, Connection* fromConnection);

    //��������� ping:
    void sendPing();

};

#endif // SOCIALRELATIONSMANAGER_H
