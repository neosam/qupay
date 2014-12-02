#include "transaction.h"

Transaction::Transaction(const Transaction &other)
{
    transactionId = other.transactionId;
    value = other.value;
    comment = other.comment;
    foreach (Token token, other.tokens) {
        tokens.insert(token);
    }
    timestamp = other.timestamp;
}


QList<Token> Transaction::getTokens() const
{
    return tokens.toList();
}

void Transaction::addToken(const Token &token)
{
    tokens.insert(token);
}



Transaction &Transaction::operator =(const Transaction &other)
{
    transactionId = other.transactionId;
    value = other.value;
    comment = other.comment;
    foreach (Token token, other.tokens) {
        tokens.insert(token);
    }
    timestamp = other.timestamp;
    return *this;
}
