#ifndef SOCIALRELATIONSMANAGER_H
#define SOCIALRELATIONSMANAGER_H

//Класс, отвечающий за дипломатию с узлами сети.
//Управляет пингами
//Запрашивает необходимые данные из состояния приложения

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

    //Вызывает пинг:
    QTimer pingTimer;

    //Нафиг не нужен пока:
    QTime pongTime;

    //Является ли инициализатором соединения:
    bool isConnectionInitialiser;

    //Проверка известности порта пира
    void portCheckUp();

public:

    SocialRelationsManager(QObject *parent);

    SocialRelationsManager(Connection *_connection, bool connectionInitialiser);

private slots:

    //Обрабатывает полученные данные
    void dataReciever(QString commandTypePrefix, QString message, Connection* fromConnection);

    //Отправить ping:
    void sendPing();

};

#endif // SOCIALRELATIONSMANAGER_H
