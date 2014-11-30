#ifndef TOKEN_H
#define TOKEN_H

#include <QObject>
#include <QDateTime>

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

inline uint qHash(const Token &token);

#endif // TOKEN_H
