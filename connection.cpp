#include "connection.h"

Connection::Connection(QObject *parent)
    : QObject(parent)
{
    tcpSocket= new QTcpSocket();
}

Connection::Connection(QString ip, int port)
{
    tcpSocket= new QTcpSocket();
    qDebug()<<"Connecting to:"<<ip<<":"<<port;
    tcpSocket->connectToHost(ip,port);
    initializator();
}

Connection::Connection(QTcpSocket* concreteSocket){
    tcpSocket=concreteSocket;
    initializator();
    qDebug()<<"Constructed new incomming connection.";
}

void Connection::initializator()
{
    QObject::connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(tcpSocket, SIGNAL(disconnected()),
            this, SLOT(disconnected()));
    QObject::connect(tcpSocket, SIGNAL(readyRead()),
            this, SLOT(reading()));
    QObject::connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(error()));

    nextBlockSize = 0;
}

void Connection::sendData(QString commandTypePrefix, QString message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << quint16(0) << commandTypePrefix << ":" << message;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}

void Connection::connected()
{
    qDebug()<<"Succsessfully connected";
}

void Connection::reading()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_3);

    forever {

        if (nextBlockSize == 0) {
            if (tcpSocket->bytesAvailable() < sizeof(quint16))
                break;
            in >> nextBlockSize;
        }

        if (nextBlockSize == 0xFFFF) {
            closeConnection();
            break;
        }

        if (tcpSocket->bytesAvailable() < nextBlockSize)
            break;

        QString recievedText;
        in >> recievedText;

        emit recievedData(recievedText.section(':',0,1),recievedText.section(':',1,-1));

        nextBlockSize = 0;
    }
}

void Connection::disconnected()
{
    if (nextBlockSize != 0xFFFF)
        qDebug() << "Server dropped connection.";
    closeConnection();
}

void Connection::error()
{
    qDebug()<<"Error:"<<tcpSocket->errorString();
    closeConnection();
}

void Connection::closeConnection()
{
    tcpSocket->close();
}
