#ifndef SOCIALRELATIONSMANAGER_H
#define SOCIALRELATIONSMANAGER_H

//�����, ���������� �� ���������� � ������ ����.
//��������� �������
//����������� ����������� ������ �� ��������� ����������

#include <privateconnectionfunctionality.h>

#include <QTimer>
#include <QTime>
#include <QObject>

class SocialRelationsManager : public PrivateConnectionFunctionality
{
    Q_OBJECT

private:

    //�������� ����:
    QTimer pingTimer;

    //����� �� ����� ����:
    QTime pongTime;

public:

    SocialRelationsManager(QObject *parent);

    SocialRelationsManager(Connection *_connection);

private slots:

    //������������ ���������� ������
    void dataReciever(QString commandTypePrefix, QString message);

    //?
    void sendPing();

};

#endif // SOCIALRELATIONSMANAGER_H
