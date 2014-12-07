#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainwindow.h"
#include "appcontroller.h"
#include "walletstorage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    AppController c;
    WalletStorage ws(c.getWallet());

    MainWindow w;
    QObject::connect(&w, SIGNAL(newToken(Token)), &c, SLOT(addToken(Token)));
    QObject::connect(&w, SIGNAL(taintToken(Token)), &c, SLOT(taintToken(Token)));
    QObject::connect(&c, SIGNAL(balanceChanged(quint16)), &w, SLOT(setNewBalance(quint16)));

    c.recalculateBalance();
    w.show();

    return app.exec();
}
