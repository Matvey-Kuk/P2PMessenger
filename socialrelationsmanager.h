#ifndef SOCIALRELATIONSMANAGER_H
#define SOCIALRELATIONSMANAGER_H

//Класс, отвечающий за дипломатию с узлами сети.
//Управляет пингами
//Запрашивает необходимые данные

#include <privateconnectionfunctionality.h>

class SocialRelationsManager : public PrivateConnectionFunctionality
{
public:
    SocialRelationsManager();
};

#endif // SOCIALRELATIONSMANAGER_H
