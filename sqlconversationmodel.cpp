#include <QDateTime>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

#include "sqlconversationmodel.h"
#include "answermanager.h"

SqlConversationModel::SqlConversationModel(QObject *parent) : QSqlRelationalTableModel(parent) {
    setTable("Conversations");
    setSort(0, Qt::DescendingOrder);
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    setRelation(5, QSqlRelation("TopicIcon", "id", "icon"));
}

QString SqlConversationModel::getRecipient() const {
    return this->recipient;
}

void SqlConversationModel::setRecipient(const QString &recipient) {
    if (this->recipient == recipient)
        return;

    this->recipient = recipient;

    const QString filterString = QString::fromLatin1(
        "(recipient = '%1' AND author = 'Me') OR (recipient = 'Me' AND author='%1')").arg(this->recipient);
    setFilter(filterString);
    select();

    emit recipientChanged();
}

QVariant SqlConversationModel::data(const QModelIndex &index, int role) const {
    if (role < Qt::UserRole)
        return QSqlTableModel::data(index, role);

    const QSqlRecord sqlRecord = record(index.row());
    return sqlRecord.value(role - Qt::UserRole);
}

QHash<int, QByteArray> SqlConversationModel::roleNames() const {
    QHash<int, QByteArray> names;
    names[Qt::UserRole] = "id";
    names[Qt::UserRole + 1] = "author";
    names[Qt::UserRole + 2] = "recipient";
    names[Qt::UserRole + 3] = "timestamp";
    names[Qt::UserRole + 4] = "message";
    names[Qt::UserRole + 5] = "icon";
    return names;
}

static int getIconId(QString iconName) {
    QSqlQuery query("SELECT id FROM TopicIcon WHERE icon = '" + iconName + "'");
    query.exec();
    query.first();
    return query.value(0).toInt();
}

void SqlConversationModel::sendMessage(const QString &recipient, const QString &message, const QString &iconName) {
    // Set current recipient and message to AnswerManager object

    answerManager.setRecipient(recipient);
    answerManager.setMessage(message);

    // Retrieve real icon id from TopicIcon because of QtSqlRelationTableModel behaivour
    // So first we must call select() on related model, and then query().value("id")
    // And provide it to new record then
    // relationModel(5)->select();

    QSqlRecord sentMessageRecord = record();
    sentMessageRecord.setValue("author", "Me");
    sentMessageRecord.setValue("recipient", recipient);
    sentMessageRecord.setValue("timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));
    sentMessageRecord.setValue("message", message);
    sentMessageRecord.setValue("icon", getIconId(iconName));

    if (!insertRecord(rowCount(), sentMessageRecord)) {
        qWarning() << "Failed to register sent message: " << lastError().text();
        return;
    }

    QSqlRecord retrievedMessageRecord = record();
    retrievedMessageRecord.setValue("author", recipient);
    retrievedMessageRecord.setValue("recipient", "Me");
    retrievedMessageRecord.setValue("timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));
    retrievedMessageRecord.setValue("message", answerManager.appropriateMessage());
    retrievedMessageRecord.setValue("icon", getIconId(iconName));

    if (!insertRecord(rowCount(), retrievedMessageRecord)) {
        qWarning() << "Failed to register retrieved message:" << lastError().text();
        return;
    }

    submitAll();
}
