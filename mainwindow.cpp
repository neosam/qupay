#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::setNewBalance(quint16 balance)
{
    qDebug() << "MainWindow::setNewBalance";
    emit balanceChanged(balance);
}

void MainWindow::addToken()
{
    qDebug() << "MainWindow::addToken";
    QString tokenId = ui.tokenIdField->text();
    QString tokenValueString = ui.valueField->text();
    int tokenValue = tokenValueString.toInt();
    QDateTime timestamp = ui.timestamp->dateTime();
    Token token(tokenId, tokenValue, timestamp);
    emit newToken(token);
}

void MainWindow::taintToken()
{
    QString tokenId = ui.taintTokenIdField->text();
    Token token;
    token.setToken(tokenId);
    emit taintToken(token);
}

void MainWindow::removeToken()
{
    qDebug() << "MainWindow::removeToken";
    QString tokenId = ui.removeTokenField->text();
    Token token;
    token.setToken(tokenId);
    emit removeToken(token);
}
