#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainwindow.h"
#include "appcontroller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    AppController c;
    QObject::connect(&w, SIGNAL(newToken(Token)), &c, SLOT(addToken(Token)));
    QObject::connect(&c, SIGNAL(balanceChanged(quint16)), &w, SLOT(setNewBalance(quint16)));
    w.show();

    return app.exec();
}
