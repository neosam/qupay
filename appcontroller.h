#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include "wallet.h"

class AppController : public QObject
{
    Q_OBJECT
private:
    Wallet *wallet;
    quint16 balance;

    void initialize();
public:
    explicit AppController(QObject *parent = 0);

signals:
    void objectInitialized();
    void balanceChanged(quint16 newBalance);

private slots:
    void recalculateBalance();

public slots:
    void addToken(const Token &token);

};

#endif // APPCONTROLLER_H
