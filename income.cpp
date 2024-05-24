#include "Income.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Income::Income(const QDate &date, const QString &title, double amount, const QString &description)
{
    m_date = date;
    m_title = title;
    m_amount = amount;
    m_description = description;
}

bool Income::addToDatabase(QSqlDatabase &db)
{
    if (!db.isOpen()) {
        qDebug() << "Database is not open";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO incomes (date, title, amount, description) "
                  "VALUES (:date, :title, :amount, :description)");
    query.bindValue(":date", m_date);
    query.bindValue(":title", m_title);
    query.bindValue(":amount", m_amount);
    query.bindValue(":description", m_description);

    if (!query.exec()) {
        qDebug() << "Error adding income to database:" << query.lastError();
        return false;
    }

    return true;
}

QDate Income::getDate() const
{
    return m_date;
}

QString Income::getTitle() const
{
    return m_title;
}

double Income::getAmount() const
{
    return m_amount;
}

QString Income::getDescription() const
{
    return m_description;
}
