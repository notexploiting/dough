#pragma once

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    static DatabaseManager& getInstance(); // Singleton instance method

    bool openDatabase(const QString &path);
    void closeDatabase();
    bool createTables();
    bool clearExpenses();
    bool clearIncomes();
    QSqlDatabase& getDatabase();

    QSqlQueryModel* getExpensesModel();
    QSqlQueryModel* getIncomesModel();

private:
    DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
