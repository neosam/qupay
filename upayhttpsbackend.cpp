#include "upayhttpsbackend.h"

UpayHttpsBackend::UpayHttpsBackend(QString server, quint16 port, QObject *parent) :
    QObject(parent), server(server), port(port)
{
}

QList<Token> UpayHttpsBackend::validate(const QList<Token> &tokens)
{
    return QList<Token>();
}

QList<Token> UpayHttpsBackend::create(const QList<int> &valueList)
{
    return QList<Token>();
}

QList<Token> UpayHttpsBackend::transform(const QList<Token> &oldTokens, const QList<Token> &newTokens)
{
    return QList<Token>();
}
