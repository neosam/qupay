#ifndef WALLETSTORAGE_H
#define WALLETSTORAGE_H

#include <QObject>
#include <QSettings>
#include "wallet.h"

/**
 * @brief Observer class to save the wallet.
 *
 * This class will observe a wallet and store all changes in
 * a local storage.
 *
 * TODO:  This class is not finished.
 */
class WalletStorage : public QObject
{
    Q_OBJECT
private:
    Wallet *wallet;
    QSettings *settings;

    void readTokens();
    Token readToken(const QString &key);
public:
    explicit WalletStorage(Wallet *wallet, QObject *parent = 0);
    ~WalletStorage();

    void storeToken(const Token &token);
    QByteArray tokenToJson(const Token &token);

signals:

public slots:
    void tokenAdded(const Token &token);
    void tokenRemoved(const Token &token);
    void tokenTainted(const Token &token);

};

#endif // WALLETSTORAGE_H
