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

bool DatabaseManager::clearExpenses()
{
    QSqlQuery query;
    if (query.exec("DELETE FROM expenses")) {
        qDebug() << "All expenses have been cleared.";
        return true;
    } else {
        qDebug() << "Error clearing expenses:" << query.lastError();
        return false;
    }
}

bool DatabaseManager::clearIncomes()
{
    QSqlQuery query;
    if (query.exec("DELETE FROM incomes")) {
        qDebug() << "All incomes have been cleared.";
        return true;
    } else {
        qDebug() << "Error clearing incomes:" << query.lastError();
        return false;
    }
}

QSqlDatabase& DatabaseManager::getDatabase()
{
    return db;
}

QSqlQueryModel *DatabaseManager::getExpensesModel()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT category, date, title, amount, description FROM expenses ORDER BY category", db);

    // Set headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Category"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Title"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Description"));

    return model;
}

QSqlQueryModel *DatabaseManager::getIncomesModel()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT date, title, amount, description FROM incomes", db);

    // Set headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Amount"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

    return model;
}

DatabaseManager& DatabaseManager::getInstance()
{
    static DatabaseManager instance; // Singleton instance
    return instance;
}
