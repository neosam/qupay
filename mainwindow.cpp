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
