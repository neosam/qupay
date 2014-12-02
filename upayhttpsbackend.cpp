#include "upayhttpsbackend.h"

UpayHttpsBackend::UpayHttpsBackend(QString server, quint16 port, QObject *parent) :
    QObject(parent), server(server), port(port)
{
}

QList<Token> validate(QList<Token> tokens)
{
    return QList<Token>();
}

QList<Token> create(QList<int> valueList)
{
    return QList<Token>();
}

QList<Token> transform(QList<Token> oldTokens, QList<Token> newTokens)
{
    return QList<Token>();
}
