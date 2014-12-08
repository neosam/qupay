#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include "wallet.h"

/**
 * @brief Handles user interaction.
 */
class AppController : public QObject
{
    Q_OBJECT
private:
    Wallet *wallet;
    quint16 balance;

    void initialize();
public:
    explicit AppController(QObject *parent = 0);
    inline Wallet *getWallet() const { return wallet; }

signals:
    void objectInitialized();
    void balanceChanged(quint16 newBalance);

public slots:
    void recalculateBalance();

    void addToken(const Token &token);
    void taintToken(const Token &token);
    void removeToken(const Token &token);

};

#endif // APPCONTROLLER_H
