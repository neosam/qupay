#include "appcontroller.h"

#include <QDebug>

AppController::AppController(QObject *parent) :
    QObject(parent)
{
    initialize();
}

void AppController::initialize()
{
    wallet = new Wallet();
    connect(wallet, SIGNAL(tokenAdded(Token)), this, SLOT(recalculateBalance()));
    connect(wallet, SIGNAL(tokenRemoved(Token)), this, SLOT(recalculateBalance()));
    connect(wallet, SIGNAL(tokenTainted(Token)), this, SLOT(recalculateBalance()));
    emit objectInitialized();
}

void AppController::recalculateBalance()
{
    qDebug() << "AppController::recalculateBalance";
    balance = wallet->getBalance();
    emit balanceChanged(balance);
}

void AppController::addToken(const Token &token)
{
    qDebug() << "AppController::addToken";
    wallet->addToken(token);
}
