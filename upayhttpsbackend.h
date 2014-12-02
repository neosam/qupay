#ifndef UPAYHTTPSBACKEND_H
#define UPAYHTTPSBACKEND_H

#include <QObject>
#include <QString>
#include <QList>
#include "token.h"

class UpayHttpsBackend : public QObject
{
    Q_OBJECT
private:
    QString servername;
    quint16 port;

public:
    explicit UpayHttpsBackend(QString server, quint16 port, QObject *parent = 0);

    QList<Token> validate(QList<Token> tokens);
    QList<Token> create(QList<int> valueList);
    QList<Token> transform(QList<Token> oldTokens, QList<Token> newTokens);

signals:

public slots:

};

#endif // UPAYHTTPSBACKEND_H
