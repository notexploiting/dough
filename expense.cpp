#include "Expense.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Expense::Expense(const QString &category, const QDate &date, const QString &title, double amount, const QString &description)
{
    m_category = category;
    m_date = date;
    m_title = title;
    m_amount = amount;
    m_description = description;
}

bool Expense::addToDatabase(QSqlDatabase &db)
{
    if (!db.isOpen()) {
        qDebug() << "Database is not open";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO expenses (category, date, title, amount, description) "
                  "VALUES (:category, :date, :title, :amount, :description)");
    query.bindValue(":category", m_category);
    query.bindValue(":date", m_date);
    query.bindValue(":title", m_title);
    query.bindValue(":amount", m_amount);
    query.bindValue(":description", m_description);

    if (!query.exec()) {
        qDebug() << "Error adding expense to database:" << query.lastError();
        return false;
    }

    return true;
}

QString Expense::getCategory() const
{
    return m_category;
}

QDate Expense::getDate() const
{
    return m_date;
}

QString Expense::getTitle() const
{
    return m_title;
}

double Expense::getAmount() const
{
    return m_amount;
}

QString Expense::getDescription() const
{
    return m_description;
}
