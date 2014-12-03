#include "walletmanager.h"

#include <QUuid>

WalletManager::WalletManager(Wallet *wallet, QObject *parent) :
    QObject(parent), wallet(wallet)
{
}

Transaction WalletManager::createTransaction(quint32 value, const QString &comment)
{
    /* Return nullTransaction if the balance is not enough */
    if (value > wallet->getBalance()) {
        return nullTransaction;
    }

    /* Initialize the transaction */
    const QUuid uuid = QUuid::createUuid();
    const QString transactionId = uuid.toString();
    Transaction finalTransaction(transactionId, 0, comment);

    /* Create the lists which holds the tokens which are needed to collect the
     * tokens which are needed for the transaction.  The sum of the transaction
     * values must equal the "value" */
    QList<Token> tokenList = wallet->getTokens();
    QList<Token> transactionTokens;
    QList<Token> leftTokens;

    /* Collect tokens as long as their sum is smaller than "value".
     * Store these transactions in "transactionTokens" and store
     * the others which are too big in "leftTokens".
     */
    quint16 currentSum = 0;
    foreach (Token token, tokenList) {
        if (token.getValue() + currentSum > value) {
            leftTokens.append(token);
        } else {
            transactionTokens.append(token);
            currentSum += token.getValue();
        }
    }

    /* Caluclate the delta between the current collected tokens
     * and "value".  Every entry in leftToken must be bigger than
     * then this delta.  Change one of the unused tokens into
     * to have one exact fitting token.
     * If delta equals 0, we can skip this, since we already
     * have the exact matching token value sum.
     */
    quint16 delta = value - currentSum;
    if (delta != 0) {
        /* This should not happen but we catch it anyway.
         * If the balance of the wallet is bigger than "value",
         * there must be at least on unused tokens left. */
        if (leftTokens.isEmpty()) {
            return nullTransaction;
        }

        /* Take one token which is unused which must be bigger than "delta".
         * We check it anyway and return a nullTransaction if it's smaller. */
        Token anyLeftToken = leftTokens.at(0);
        if (anyLeftToken.getValue() < delta) {
            return nullTransaction;
        }

        /* Split this left token into new token where one of the tokens
         * value equals exactly the "delta".*/
        QList<Token> changedTokens = changeToken(anyLeftToken, delta);
        transactionTokens.append(changedTokens[0]);

        /* Replace it in the wallet */
        wallet->taintToken(anyLeftToken);
        wallet->addToken(changedTokens[0]);
        wallet->addToken(changedTokens[1]);
    }

    /* Fill the transaction with the collected tokens. */
    foreach (Token transactionToken, transactionTokens) {
        finalTransaction.addToken(transactionToken);
    }

    /* Finally... */
    return finalTransaction;
}

bool WalletManager::cashTransaction(const Transaction &transaction)
{
    return true;
}

QList<Token> WalletManager::changeToken(const Token &token, quint16 firstValue)
{
    /* Return empty list if "firstValue" is higher than the token value */
    if (firstValue > token.getValue()) {
        return QList<Token>();
    }

    /* The secondValue is most likely the difference between the first value and the token value */
    quint16 secondValue = token.getValue() - firstValue;

    /* Prepare the values needed by the upay server to get the new tokens. */
    QList<int> valueList;
    valueList << firstValue << secondValue;

    /* Get the new tokens */
    QList<Token> newTokens = upay->create(valueList);

    /* Prepare the list of the old tokens which contains just the one token */
    QList<Token> oldTokens;
    oldTokens << token;

    /* Actually transform the tokens */
    upay->transform(oldTokens, newTokens);

    return newTokens;
}
