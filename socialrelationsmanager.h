#ifndef SOCIALRELATIONSMANAGER_H
#define SOCIALRELATIONSMANAGER_H

//�����, ���������� �� ���������� � ������ ����.
//��������� �������
//����������� ����������� ������ �� ��������� ����������

#include <privateconnectionfunctionality.h>

class SocialRelationsManager : public PrivateConnectionFunctionality
{
public:
    SocialRelationsManager(Connection *_connection);
};

#endif // SOCIALRELATIONSMANAGER_H
