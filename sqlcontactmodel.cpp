#include "sqlcontactmodel.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

static void createTable() {
    if (QSqlDatabase::database().tables().contains(QStringLiteral("Topics"))) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'Topics' ("
        "   'name' TEXT NOT NULL,"
        "   PRIMARY KEY(name)"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.exec("INSERT INTO Topics VALUES('Medicines Order')");
    query.exec("INSERT INTO Topics VALUES('Guess your diasease')");
    query.exec("INSERT INTO Topics VALUES('Live Consultation with Doctor')");
}

SqlContactModel::SqlContactModel(QObject *parent) : QSqlQueryModel(parent) {
    createTable();

    QSqlQuery query;
    if (!query.exec("SELECT * FROM Topics"))
        qFatal("Topics SELECT query failed: %s", qPrintable(query.lastError().text()));

    setQuery(query);
    if (lastError().isValid())
        qFatal("Cannot set query on SqlContactModel: %s", qPrintable(lastError().text()));
}
