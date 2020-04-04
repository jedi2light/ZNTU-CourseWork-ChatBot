#ifndef SQLCONVERSATIONMODEL_H
#define SQLCONVERSATIONMODEL_H

#include <QSqlRelationalTableModel>

#include "answermanager.h"

class SqlConversationModel : public QSqlRelationalTableModel {
    Q_OBJECT
    Q_PROPERTY(QString recipient READ getRecipient WRITE setRecipient NOTIFY recipientChanged)

public:
    SqlConversationModel(QObject *parent = 0);

    QString icon() const;

    QString getRecipient() const;
    void setRecipient(const QString &recipient);

    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void sendMessage(const QString &recipient, const QString &message, const QString &iconName);

signals:
    void recipientChanged();

private:
    QString recipient;
    AnswerManager answerManager;
};

#endif // SQLCONVERSATIONMODEL_H
