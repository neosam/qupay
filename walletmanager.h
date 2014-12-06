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

    /**
     * @brief Create new transaction by removing tokens from the wallet
     *
     * The value must be smaller or equal to the balance of the wallet.
     * If it is higher, this method will return a nullTransaction.
     * It will communicate with the upay server if it cannot find the
     * matching tokens for this value since it has break one token into two
     * pieces.
     *
     * @param value The value of the transaction.
     * @param comment An optional transaction comment.
     * @return The transaction (can be nullTransaction).
     */
    Transaction createTransaction(quint32 value, const QString &comment = "");

    /**
     * @brief Add value of the transaction to the wallet.
     *
     * This method will check if the token are valid.  If not it will return
     * false.  Then it will transform all the tokens in one new token which
     * is only known by the server and the app and will add the token to the
     * wallet.
     *
     * @param transaction
     * @return
     */
    bool cashTransaction(const Transaction &transaction);

    /**
     * @brief Transforms a list of tokens into one new token
     * @param tokenList
     * @return
     */
    Token transformTokens(const QList<Token> &tokenList);

signals:
    /**
     * @brief Emitted when a transaction was successfully created.
     * @param transaction
     */
    void exportedTransaction(const Transaction &transaction);

    /**
     * @brief Emitted when a transaction was successfully imported.
     * @param transaction
     */
    void importedTransaction(const Transaction &transaction);

public slots:

};

#endif // WALLETMANAGER_H
