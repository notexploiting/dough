#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {}

DatabaseManager::~DatabaseManager()
{
    closeDatabase();
}

bool DatabaseManager::openDatabase(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open())
    {
        qDebug() << "Error: Connection with database failed";
        return false;
    }
    else
    {
        qDebug() << "Connection with database OK";
        return true;
    }
}

void DatabaseManager::closeDatabase()
{
    db.close();
}

bool DatabaseManager::createTables()
{
    bool success = false;
    QSqlQuery query;

    QString createExpensesTable = R"(
        CREATE TABLE IF NOT EXISTS expenses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            category TEXT,
            date TEXT,
            title TEXT,
            amount REAL,
            description TEXT
        )
    )";

    QString createIncomesTable = R"(
        CREATE TABLE IF NOT EXISTS incomes (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            date TEXT,
            title TEXT,
            amount REAL,
            description TEXT
        )
    )";

    if (query.exec(createExpensesTable) && query.exec(createIncomesTable))
    {
        success = true;
    }
    else
    {
        qDebug() << "Couldn't create the tables:" << query.lastError();
    }

    return success;
}
