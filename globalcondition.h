#ifndef GLOBALCONDITION_H
#define GLOBALCONDITION_H

class GlobalCondition
{
private:

public:
    GlobalCondition();

    //����� �� �������� ������ �����:
    static bool needMorePeers;

    //���� �������:
    static int serverPort;
};

#endif // GLOBALCONDITION_H
