#ifndef DOUGH_H
#define DOUGH_H

#include "expensewidget.h"
#include "incomewidget.h"
#include "qpushbutton.h"
#include <QWidget>
#include <QDate>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class dough;
}
QT_END_NAMESPACE

class dough : public QWidget
{
    Q_OBJECT

public:
    dough(QWidget *parent = nullptr);
    ~dough();

private slots:

    void on_pushButton_expense_clicked();
    void onExpenseWidgetClosed(int result);

    void on_pushButton_income_clicked();
    void onIncomeWidgetClosed(int result);

private:
    Ui::dough *ui;
    QPushButton *pustButton_expense;
    QPushButton *pushButton_income;
    ExpenseWidget *expenseWidget; // Declare the ExpenseWidget pointer here
    IncomeWidget *incomeWidget; // Declare the IncomeWidget pointer here
};

#endif // DOUGH_H
