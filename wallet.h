#ifndef WALLET_H
#define WALLET_H

#include <QObject>
#include <QHash>
#include <QList>
#include "token.h"

/**
 * @brief Stores tokens and emits signals if something changes.
 *
 * It simply stores tokens in the memory.  The emitted signals can
 * be used by a IO subsystem to observe the wallet and save the
 * changes on a permantent memory.
 *
 * This class does not check if the tokens are valid.  Direct access
 * to this class can be dangerous.  Use WalletManager to access
 * the wallet in a proper way.
 *
 */
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
