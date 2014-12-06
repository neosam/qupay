#ifndef UPAYHTTPSBACKEND_H
#define UPAYHTTPSBACKEND_H

#include <QObject>
#include <QString>
#include <QList>
#include "token.h"


/**
 * @brief Communication with the upay server.
 *
 * Not implemented yet.
 */
class UpayHttpsBackend : public QObject
{
    Q_OBJECT
private:
    QString server;
    quint16 port;

public:
    explicit UpayHttpsBackend(QString server, quint16 port, QObject *parent = 0);

    /**
     * @brief Check if the tokens are valid.  Return valid tokens.
     * @param tokens List of tokens which should be checked.
     * @return Valid tokens.
     */
    QList<Token> validate(const QList<Token> &tokens);

    /**
     * @brief Create new tokens which have the values specified in the list.
     * @param valueList List of values.
     * @return
     */
    QList<Token> create(const QList<int> &valueList);

    /**
     * @brief Invalidate oldTokens and activate the newTokens.
     * @param oldTokens Tokens to invalidate.
     * @param newTokens Tokens to activate.
     * @return
     */
    QList<Token> transform(const QList<Token> &oldTokens, const QList<Token> &newTokens);

signals:

public slots:

};

#endif // UPAYHTTPSBACKEND_H
