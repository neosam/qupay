#include "upayhttpsbackend.h"

#include <QNetworkReply>

UpayHttpsBackend::UpayHttpsBackend(QString server, quint16 port, QObject *parent) :
    QObject(parent), server(server), port(port)
{
}

QList<Token> UpayHttpsBackend::validate(const QList<Token> &tokens)
{
    QNetworkRequest request("https://" + server + ":" + port + "/validate");
    QString jsonTokenList = "[";
    bool first = true;
    foreach(Token token, tokens) {
        if (!first) {
            jsonTokenList += ",";
        }
        QString jsonToken = token.toJson(true, true);
        jsonTokenList += jsonToken;
    }
    jsonTokenList += "]";
    QNetworkReply *reply = networkAccessManager.post(request, jsonTokenList.toLocal8Bit());
    reply->waitForReadyRead(5000);
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
