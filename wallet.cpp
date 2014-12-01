#include "wallet.h"

#include "token.h"

Wallet::Wallet(QObject *parent) :
    QObject(parent)
{
}

quint32 Wallet::getBalance() {
    quint16 sum = 0;
    QList<Token> tokenList = tokenHash.values();
    Token token;
    foreach(token, tokenList) {
        if (!token.isTainted()) {
            sum += token.getValue();
        }
    }
    return sum;
}

void Wallet::addToken(const Token &token) {
    tokenHash.insert(token.getToken(), token);
    emit tokenAdded(token);
}

void Wallet::addToken(const QList<Token> &tokens) {
    Token token;
    foreach (token, tokens) {
        addToken(token);
    }
}

void Wallet::removeToken(const Token &token) {
    Token storedToken = tokenHash[token.getToken()];
    tokenHash.remove(token.getToken());
    emit tokenRemoved(storedToken);
}

void Wallet::removeToken(const QList<Token> &tokens) {
    foreach (Token token, tokens) {
        removeToken(token);
    }
}
