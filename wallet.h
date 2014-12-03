#ifndef WALLET_H
#define WALLET_H

#include <QObject>
#include <QHash>
#include <QList>
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
    void taintToken(const Token &token);
    void taintToken(const QList<Token> &tokenList);

    QList<Token> getTokens();


signals:
    void tokenAdded(const Token &);
    void tokenRemoved(const Token &);
    void tokenTainted(const Token &);

public slots:

};

#endif // WALLET_H
