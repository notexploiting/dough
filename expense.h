#ifndef EXPENSE_H
#define EXPENSE_H

#include <QString>
#include <QDate>
#include <QSqlDatabase>

class Expense
{
public:
    Expense(const QString &category, const QDate &date, const QString &title, double amount, const QString &description = "");

    bool addToDatabase(QSqlDatabase &db);

    QString getCategory() const;
    QDate getDate() const;
    QString getTitle() const;
    double getAmount() const;
    QString getDescription() const;

private:
    QString m_category;
    QDate m_date;
    QString m_title;
    double m_amount;
    QString m_description;
};

#endif // EXPENSE_H
