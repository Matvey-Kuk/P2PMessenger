#ifndef CONNECTION_H
#define CONNECTION_H

//Непосредственно, соединение.

#include <QString>
#include <QTcpSocket>
#include <QObject>

class Connection : public QObject
{
    Q_OBJECT

private:

    //Функционирует ли в данный момент соединение:
    bool isConnected();

    //Соккет, через который идет передача данных:
    QTcpSocket* tcpSocket;

    //Размер следующего блока (когда соединение получает данные):
    quint16 nextBlockSize;

    //Инициализирует при создании соединения:
    void initializator();

    void closeConnection();

private slots:

    void connected();

    void disconnected();

    void reading();

    void error();

signals:

    //Когда соединение получает новые данные. Префикс- какому обработчику они направлены.
    void recievedData(QString commandTypePrefix, QString message);

public:

    explicit Connection(QObject* parent=0);

    //Создать соединение с конкретным пиром
    explicit Connection(QString ip, int port);

    //Создать соединение с конкретным сокетом
    explicit Connection(QTcpSocket* concreteSocket);

    //Отправить запрос. Префикс- какому обработчику он направлен.
    void sendData(QString commandTypePrefix, QString message);


};

#endif // CONNECTION_H
