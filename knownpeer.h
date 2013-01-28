#ifndef KNOWNPEER_H
#define KNOWNPEER_H

#include <QObject>

class KnownPeer : public QObject
{
    Q_OBJECT
public:
    explicit KnownPeer(QObject *parent = 0);

    explicit KnownPeer(QString _ip, int _port);
    
    //Адрес
    QString ip;

    //Порт
    int port;

signals:
    
public slots:
    
};

#endif // KNOWNPEER_H
