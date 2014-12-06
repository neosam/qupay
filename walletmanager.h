#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <QObject>
#include "wallet.h"

#include "transaction.h"
#include "upayhttpsbackend.h"


/**
 * @brief Used to access the wallet and the upay server.
 *
 * Stores the wallet and the upay server and can take and put
 * tokens into the wallet.  This class works with Transactions
 * which holds several Tokens and some other useful information.
 *
 * To get tokens from the wallet, the createTransaction(...) method
 * cann be used.  It receives a wallet and an optional comment and
 * returns a Transaction which holds several tokens which sum equals
 * the value which is passed.  The upay server is used to change tokens
 * if necessary.
 *
 * With cashTransaction it is possible to put transactions in the wallet.
 * It will check if the tokens in the transaction are valid and will
 * create new tokens and invalidate the one in the transaction.
 */
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
