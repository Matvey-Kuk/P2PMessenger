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

    //Удаляет соединение из функционала:
    void removeConnection(Connection* _connection);

    //Указатель на коробку с проводами:
    //BoxWithWires* boxWithWires;

private slots:
    //Получает данные от соединений
    void dataReciever(QString commandTypePrefix, QString message, Connection *fromConnection);

    //Обновление по таймеру
    void up();

signals:
    //Зарегистрировать нового полученного пира
    void newKnownPeer(QString ip, int port);

private:
    //Все соединения:
    QVector<Connection* > connections;

    //Таймер обновления состояния
    QTimer upTimer;

    //Рассказать о нескольких пирах по соединению
    void tellAboutANumberOfPeers(int number, Connection* target);

    //Проверка пира и генерация сигнала о его регистрации
    void checkNewPeer(QString ip, int port);

};

#endif // P2PORGANIZER_H
