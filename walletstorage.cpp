#include "walletstorage.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

WalletStorage::WalletStorage(Wallet *wallet, QObject *parent) :
    QObject(parent), wallet(wallet)
{
    settings = new QSettings("muccc", "qupay");
    readTokens();
}

WalletStorage::~WalletStorage()
{
    delete settings;
}

void WalletStorage::tokenAdded(const Token &token)
{

}

void WalletStorage::tokenRemoved(const Token &token)
{

}

void WalletStorage::tokenTainted(const Token &token)
{

}

void WalletStorage::readTokens()
{
    settings->beginGroup("tokens");
    QStringList keys = settings->allKeys();
    foreach (QString key, keys) {
        readToken(key);
    }
}

Token WalletStorage::readToken(const QString &key)
{
    QByteArray jsonValue = settings->value(key).toByteArray();
    QJsonDocument jsonDocument =  QJsonDocument::fromJson(jsonValue);
    if (jsonDocument.isObject()) {
        return nullToken;
    }
    QJsonObject jsonObject = jsonDocument.object();
    QString tokenId = jsonObject.value("token").toString();
    quint16 value = jsonObject.value("value").toInt();
    QString timestampString = jsonObject.value("timestamp").toString();
    bool tainted = jsonObject.value("tainted").toBool();
    QDateTime timestamp = QDateTime::fromString(timestampString, Qt::ISODate);
    Token token(tokenId, value, timestamp, tainted);
    return token;
}
