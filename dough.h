#ifndef DOUGH_H
#define DOUGH_H

#include "expensewidget.h"
#include "incomewidget.h"
#include "qlistview.h"
#include "qpushbutton.h"
#include "qtableview.h"
#include <QWidget>
#include <QDate>
#include <QString>
#include <QSqlTableModel>

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

    void on_tableView_expenses_activated(const QModelIndex &index);
    void on_tableView_incomes_activated(const QModelIndex &index);

private:
    Ui::dough *ui;

    QPushButton *pushButton_expense;
    QPushButton *pushButton_income;

    ExpenseWidget *expenseWidget; // Declare the ExpenseWidget pointer here
    IncomeWidget *incomeWidget; // Declare the IncomeWidget pointer here

    QTableView *tableView_incomes;
    QTableView *tableView_expenses;

    void updateExpensesView();
    void updateIncomesView();
};

#endif // DOUGH_H
