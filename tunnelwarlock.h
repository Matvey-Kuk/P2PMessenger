#ifndef TUNNELWARLOCK_H
#define TUNNELWARLOCK_H

//Класс отвечает за организацию туннелей по существующим соединениям
//, обслуживание этих туннелей и достоверность доставки.

#include <connection.h>
#include <globalcondition.h>
#include <tunnel.h>

#include <QVector>
#include <QTimer>

class TunnelWarlock: public QObject
{
    Q_OBJECT

public:
    TunnelWarlock(QObject *parent);

    //Добавить соединение в функционал:
    void addConnection(Connection* _connection);

    //Удаляет соединение из функционала:
    void removeConnection(Connection* _connection);

private slots:
    //Получает данные от соединений
    void dataReciever(QString commandTypePrefix, QString message, Connection *fromConnection);

    //Обновление по таймеру
    void up();

private:
    //Все туннели
    QVector<Tunnel*> tunnels;

    //Все соединения:
    QVector<Connection* > connections;

    //Таймер обновления состояния
    QTimer upTimer;

    //Создать туннель
    void makeTunnel();
};

#endif // TUNNELWARLOCK_H
