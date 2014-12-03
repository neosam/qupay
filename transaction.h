#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QSet>
#include <QDateTime>
#include "token.h"

class Transaction
{
private:
    QString transactionId;
    quint16 value;
    QString comment;
    QSet<Token> tokens;
    QDateTime timestamp;

public:
    Transaction(): transactionId(""), value(0), comment("") {}
    Transaction(const QString &transactionId, quint16 value, const QString &comment) :
        transactionId(transactionId), value(value), comment(comment) {}
    Transaction(const QString &transactionId, quint16 value, const QString &comment,
                const QSet<Token> &tokens, const QDateTime &timestamp) :
        transactionId(transactionId), value(value), comment(comment),
        tokens(tokens), timestamp(timestamp) {}
    Transaction(const Transaction &other);


    inline const QString &getTransactionId() const { return transactionId; }
    inline void setTransactionId(const QString &t) { transactionId = t; }

    inline quint16 getValue() const { return value; }
    inline void setValue(int v) { value = v; }

    inline const QString &getComment() const { return comment; }
    inline void setComment(const QString &c) { comment = c; }

    inline QDateTime &getTimestamp() { return timestamp; }
    inline void setDateTime(const QDateTime &t) { timestamp = t; }


    QList<Token> getTokens() const;
    void addToken(const Token &token);


    inline bool operator ==(const Transaction &other) { return transactionId == other.getTransactionId(); }
    Transaction &operator=(const Transaction &other);
};

inline uint qHash(const Transaction &tx) { return qHash(tx.getTransactionId()); }

extern Transaction nullTransaction;

#endif // TRANSACTION_H
