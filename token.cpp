#include "token.h"

#include <QJsonDocument>
#include <QJsonObject>

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

QByteArray Token::toJson(bool divideByHundred, bool noTainted) {
    QJsonObject jsonObject;
    jsonObject["token"] = token;
    jsonObject["timestamp"] = timestamp.toString(Qt::ISODate);
    if (!noTainted) {
        jsonObject["tainted"] = tainted;
    }
    if (divideByHundred) {
        jsonObject["value"] = (value / 100) + "." + (value % 100);
    } else {
        jsonObject["value"] = value;
    }
    QJsonDocument document(jsonObject);
    return document.toJson();
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
