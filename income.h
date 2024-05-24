#ifndef INCOME_H
#define INCOME_H

#include <QString>
#include <QDate>
#include <QSqlDatabase>

class Income
{
public:
    Income(const QDate &date, const QString &title, double amount, const QString &description = "");

    bool addToDatabase(QSqlDatabase &db);

    QDate getDate() const;
    QString getTitle() const;
    double getAmount() const;
    QString getDescription() const;

private:
    QDate m_date;
    QString m_title;
    double m_amount;
    QString m_description;
};

#endif // INCOME_H
