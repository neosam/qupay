#ifndef TOKEN_H
#define TOKEN_H

#include <QObject>
#include <QDateTime>

class Token : public QObject
{
    Q_OBJECT
private:
    QString token;
    quint16 value;
    QDateTime timestamp;
    bool tainted;

public:
    explicit Token(QObject *parent = 0);
    Token(const QString &token, quint16 value, const QDateTime &timestamp, bool tainted = false, QObject *p = 0);
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


signals:

public slots:

};

#endif // TOKEN_H
