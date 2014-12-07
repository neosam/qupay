#include "walletstorage.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

WalletStorage::WalletStorage(Wallet *wallet, QObject *parent) :
    QObject(parent), wallet(wallet)
{
    settings = new QSettings("muccc", "qupay");
    readTokens();
    qDebug() << "Wallet balance: " << wallet->getBalance();
    connect(wallet, SIGNAL(tokenAdded(Token)), this, SLOT(tokenAdded(Token)));
    connect(wallet, SIGNAL(tokenRemoved(Token)), this, SLOT(tokenRemoved(Token)));
    connect(wallet, SIGNAL(tokenTainted(Token)), this, SLOT(tokenTainted(Token)));
}

WalletStorage::~WalletStorage()
{
    delete settings;
}

void WalletStorage::tokenAdded(const Token &token)
{
    storeToken(token);
}

void WalletStorage::tokenRemoved(const Token &token)
{
    storeToken(token);
}

void WalletStorage::tokenTainted(const Token &token)
{
    storeToken(token);
}

void WalletStorage::storeToken(const Token &token)
{
    QByteArray jsonToken = tokenToJson(token);
    qDebug() << "Store token " << jsonToken;
    settings->beginGroup("tokens");
    settings->setValue(token.getToken(), jsonToken);
    settings->endGroup();
    settings->sync();
}

void WalletStorage::readTokens()
{
    qDebug() << "Read all tokens";
    settings->beginGroup("tokens");
    QStringList keys = settings->allKeys();
    foreach (QString key, keys) {
        Token token = readToken(key);
        if (!token.isTainted()) {
            wallet->addToken(token);
        }
    }
    settings->endGroup();
    qDebug() << "Done reading all tokens";
}

Token WalletStorage::readToken(const QString &key)
{
    qDebug() << "Begn reading token";
    QByteArray jsonValue = settings->value(key).toByteArray();
    QJsonDocument jsonDocument =  QJsonDocument::fromJson(jsonValue);
    if (!jsonDocument.isObject()) {
        return nullToken;
    }
    QJsonObject jsonObject = jsonDocument.object();
    QString tokenId = jsonObject.value("token").toString();
    quint16 value = jsonObject.value("value").toInt();
    QString timestampString = jsonObject.value("timestamp").toString();
    bool tainted = jsonObject.value("tainted").toBool();
    QDateTime timestamp = QDateTime::fromString(timestampString, Qt::ISODate);
    Token token(tokenId, value, timestamp, tainted);
    qDebug() << "Finished readig token";
    return token;
}

QByteArray WalletStorage::tokenToJson(const Token &token)
{
    QJsonObject jsonObject;
    jsonObject["token"] = token.getToken();
    jsonObject["value"] = token.getValue();
    jsonObject["timestamp"] = token.getTimestamp().toString(Qt::ISODate);
    jsonObject["tainted"] = token.isTainted();
    QJsonDocument document(jsonObject);
    return document.toJson();
}
