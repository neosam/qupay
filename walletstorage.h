#ifndef WALLETSTORAGE_H
#define WALLETSTORAGE_H

#include <QObject>
#include <QSettings>
#include "wallet.h"

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

signals:

public slots:
    void tokenAdded(const Token &token);
    void tokenRemoved(const Token &token);
    void tokenTainted(const Token &token);

};

#endif // WALLETSTORAGE_H
