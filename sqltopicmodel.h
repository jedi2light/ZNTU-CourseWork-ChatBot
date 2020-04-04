#ifndef SQLTOPICMODEL_H
#define SQLTOPICMODEL_H

#include <QSqlRelationalTableModel>

class SqlTopicModel : public QSqlRelationalTableModel {
public:
    SqlTopicModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // SQLTOPICMODEL_H
