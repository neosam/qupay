#include "token.h"

Token::Token(QObject *parent) :
    QObject(parent)
{
}

Token::Token(const QString &token, quint16 value, const QDateTime &timestamp, bool tainted, QObject *p) :
    QObject(p), token(token), value(value), timestamp(timestamp), tainted(tainted) {

}

Token::Token(const Token &other) {
    this->token = other.getToken();
    this->value = other.getValue();
    this->timestamp = other.getTimestamp();
    this->tainted = other.isTainted();
}

Token &Token::operator =(const Token &other) {
    this->token = other.getToken();
    this->value = other.getValue();
    this->timestamp = other.getTimestamp();
    this->tainted = other.isTainted();
    return *this;
}
