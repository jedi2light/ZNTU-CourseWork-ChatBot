#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

#include "sqltopicmodel.h"

SqlTopicModel::SqlTopicModel(QObject *parent) : QSqlRelationalTableModel(parent) {
   setTable("Topics");
   setRelation(2, QSqlRelation("TopicIcon", "id", "icon"));
   select();
}

QVariant SqlTopicModel::data(const QModelIndex &index, int role) const {
    if (role < Qt::UserRole)
        return QSqlTableModel::data(index, role);

    const QSqlRecord sqlRecord = record(index.row());
    return sqlRecord.value(role - Qt::UserRole);
}

QHash<int, QByteArray> SqlTopicModel::roleNames() const {
    QHash<int, QByteArray> names;
    names[Qt::UserRole] = "id";
    names[Qt::UserRole + 1] = "name";
    names[Qt::UserRole + 2] = "icon";
    return names;
}
