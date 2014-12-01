#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include "wallet.h"

class AppController : public QObject
{
    Q_OBJECT
private:
    Wallet *wallet;

public:
    explicit AppController(QObject *parent = 0);

signals:

public slots:

};

#endif // APPCONTROLLER_H
