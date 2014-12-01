#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "token.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow ui;

public:
    explicit MainWindow(QWidget *parent = 0);

signals:
    void newToken(const Token &token);
    void balanceChanged(int balance);
    void taintToken(const Token &token);

public slots:
    void setNewBalance(quint16 balance);
    void addToken();
    void taintToken();

};

#endif // MAINWINDOW_H
