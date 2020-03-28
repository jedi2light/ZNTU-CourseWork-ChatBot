#ifndef SQLCONTACTMODEL_H
#define SQLCONTACTMODEL_H

#include <QSqlQueryModel>

class SqlContactModel : public QSqlQueryModel {
public:
    SqlContactModel(QObject *parent = 0);
};

#endif // SQLCONTACTMODEL_H
