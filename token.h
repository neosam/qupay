#ifndef TOKEN_H
#define TOKEN_H

#include <QObject>
#include <QDateTime>

/**
 * @brief Holds the relevant data needed for a token.
 *
 * It contains a token (QString), the value (quint16), a timestamp (QDateTime)
 * and if it's tainted (bool).
 * The first three values are part of the upay protocol.  Tainted means,
 * if the token was already used.  Using this value it is possible to keep
 * tokens stored in the wallet even if they are used.
 *
 * The value usually is equivalent with euro cents.
 */
class Token
{
private:
    QString token;
    quint16 value;
    QDateTime timestamp;
    bool tainted;

public:
    Token();
    Token(const QString &token, quint16 value, const QDateTime &timestamp, bool tainted = false);
    Token(const Token &other);

    inline QString getToken() const { return token; }
    inline void setToken(const QString &token) { this->token = token; }
    inline quint16 getValue() const { return value; }
    inline void setValue(quint16 value) {this->value = value; }
    inline QDateTime getTimestamp() const { return timestamp; }
    inline void setTimestamp(const QDateTime &timestamp) { this->timestamp = timestamp; }
    inline bool isTainted() const { return tainted; }
    inline void setTainted(bool tainted) { this->tainted = tainted; }

    Token &operator =(const Token &other);
    bool operator ==(const Token &other) const { return token == other.getToken(); }
};

uint qHash(const Token &token);

extern Token nullToken;

#endif // TOKEN_H
