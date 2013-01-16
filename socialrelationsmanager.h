#ifndef SOCIALRELATIONSMANAGER_H
#define SOCIALRELATIONSMANAGER_H

//Класс, отвечающий за дипломатию с узлами сети.
//Управляет пингами
//Запрашивает необходимые данные из состояния приложения

#include <privateconnectionfunctionality.h>

#include <QTimer>
#include <QTime>
#include <QObject>

class SocialRelationsManager : public PrivateConnectionFunctionality
{
    Q_OBJECT

private:

    //Вызывает пинг:
    QTimer pingTimer;

    //Нафиг не нужен пока:
    QTime pongTime;

public:

    SocialRelationsManager(QObject *parent);

    SocialRelationsManager(Connection *_connection);

private slots:

    //Обрабатывает полученные данные
    void dataReciever(QString commandTypePrefix, QString message);

    //?
    void sendPing();

};

#endif // SOCIALRELATIONSMANAGER_H
