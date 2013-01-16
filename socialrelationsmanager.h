#ifndef SOCIALRELATIONSMANAGER_H
#define SOCIALRELATIONSMANAGER_H

//Класс, отвечающий за дипломатию с узлами сети.
//Управляет пингами
//Запрашивает необходимые данные из состояния приложения

#include <privateconnectionfunctionality.h>

class SocialRelationsManager : public PrivateConnectionFunctionality
{
public:
    SocialRelationsManager(Connection *_connection);
};

#endif // SOCIALRELATIONSMANAGER_H
