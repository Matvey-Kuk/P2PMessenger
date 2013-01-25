#ifndef GLOBALCONDITION_H
#define GLOBALCONDITION_H

class GlobalCondition
{
private:

public:
    GlobalCondition();

    //Нужно ли получить больше пиров:
    static bool needMorePeers;

    //Порт сервера:
    static int serverPort;
};

#endif // GLOBALCONDITION_H
