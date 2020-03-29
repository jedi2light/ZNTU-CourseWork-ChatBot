#include "sqlconversationmodel.h"

#include <QDateTime>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

static const char *conversationsTableName = "Conversations";

static void createTable() {
    if (QSqlDatabase::database().tables().contains(conversationsTableName)) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Conversations' ("
        "'author' TEXT NOT NULL,"
        "'recipient' TEXT NOT NULL,"
        "'timestamp' TEXT NOT NULL,"
        "'message' TEXT NOT NULL,"
        "FOREIGN KEY('author') REFERENCES Topics ( name ),"
        "FOREIGN KEY('recipient') REFERENCES Topics ( name )"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.exec("INSERT INTO Conversations VALUES('Medicines Order', 'Me', '2016-01-07T14:36:16',"
               "'Hello. You can order medicines here.')");
    query.exec("INSERT INTO Conversations VALUES('Guess your diasease', 'Me', '2016-01-07T14:36:16',"
               "'Hello. Tell me your symptoms and I`ll try to guess your diasease.')");
    query.exec("INSERT INTO Conversations VALUES('Live Consultation with Doctor', 'Me', '2015-11-20T08:21:03',"
               "'Hello. Tell me about your troubles and I`ll try to help you with them.')");
}

SqlConversationModel::SqlConversationModel(QObject *parent) : QSqlTableModel(parent) {
    createTable();
    setTable(conversationsTableName);
    setSort(2, Qt::DescendingOrder);
    // Ensures that the model is sorted correctly after submitting a new row.
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

QString SqlConversationModel::recipient() const {
    return m_recipient;
}

void SqlConversationModel::setRecipient(const QString &recipient) {
    if (recipient == m_recipient)
        return;

    m_recipient = recipient;

    const QString filterString = QString::fromLatin1(
        "(recipient = '%1' AND author = 'Me') OR (recipient = 'Me' AND author='%1')").arg(m_recipient);
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
    names[Qt::UserRole] = "author";
    names[Qt::UserRole + 1] = "recipient";
    names[Qt::UserRole + 2] = "timestamp";
    names[Qt::UserRole + 3] = "message";
    return names;
}

void SqlConversationModel::sendMessage(const QString &recipient, const QString &message) {
    AnswerManager answerManager = AnswerManager(recipient, message);

    QSqlRecord retrievedMessageRecord = record();
    retrievedMessageRecord.setValue("author", recipient);
    retrievedMessageRecord.setValue("recipient", "Me");
    retrievedMessageRecord.setValue("timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));
    retrievedMessageRecord.setValue("message", answerManager.appropriateMessage());
    if (!insertRecord(rowCount(), retrievedMessageRecord)) {
        qWarning() << "ailed to register retrieved message:" << lastError().text();
        return;
    }

    QSqlRecord sentMessageRecord = record();
    sentMessageRecord.setValue("author", "Me");
    sentMessageRecord.setValue("recipient", recipient);
    sentMessageRecord.setValue("timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));
    sentMessageRecord.setValue("message", message);
    if (!insertRecord(rowCount(), sentMessageRecord)) {
        qWarning() << "Failed to register sent message: " << lastError().text();
        return;
    }

    submitAll();
}
