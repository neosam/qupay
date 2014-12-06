#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <QObject>
#include "wallet.h"

#include "transaction.h"
#include "upayhttpsbackend.h"

class WalletManager : public QObject
{
    Q_OBJECT
private:
    Wallet *wallet;
    UpayHttpsBackend *upay;

    QList<Token> changeToken(const Token &token, quint16 firstValue);

public:
    explicit WalletManager(Wallet *wallet, QObject *parent = 0);

    Transaction createTransaction(quint32 value, const QString &comment = "");
    bool cashTransaction(const Transaction &transaction);
    Token transformTokens(const QList<Token> &tokenList);

signals:
    void exportedTransaction(const Transaction &transaction);
    void importedTransaction(const Transaction &transaction);

public slots:

};

#endif // WALLETMANAGER_H
