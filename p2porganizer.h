#ifndef P2PORGANIZER_H
#define P2PORGANIZER_H

//Класс отвечает за поддержание соединения с пирами, получение новых и раздачу.

#include <connection.h>
#include <globalcondition.h>

#include <QVector>
#include <QTimer>

class P2POrganizer: public QObject
{
    Q_OBJECT

public:
    P2POrganizer(QObject *parent);

    //Добавляет соединенеие функционалу
    void addConnection(Connection* _connection);

private slots:
    //Получает данные от соединений
    void dataReciever(QString commandTypePrefix, QString message, Connection *fromConnection);

    //Обновление по таймеру
    void up();

private:

    //Все соединения:
    QVector<Connection* > connections;

    //Таймер обновления состояния
    QTimer upTimer;

};

#endif // P2PORGANIZER_H
