#ifndef WALLET_H
#define WALLET_H

#include <QObject>
#include <QHash>
#include "token.h"

class Wallet : public QObject
{
    Q_OBJECT
private:
    QHash<QString, Token> tokenHash;

public:
    explicit Wallet(QObject *parent = 0);

    quint32 getBalance();
    void addToken(const Token &token);
    void addToken(const QList<Token> &tokenList);
    void removeToken(const Token &token);
    void removeToken(const QList<Token> &tokenList);

signals:

public slots:

};

#endif // WALLET_H
