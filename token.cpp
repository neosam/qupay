#include "token.h"

Token nullToken("null", 0, QDateTime());

Token::Token(): token(""), value(0), timestamp(), tainted(false)
{
}

Token::Token(const QString &token, quint16 value, const QDateTime &timestamp, bool tainted) :
    token(token), value(value), timestamp(timestamp), tainted(tainted) {

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

uint qHash(const Token &token) {
    return qHash(token.getToken());
}
