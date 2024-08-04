#include "dough.h"
#include "databasemanager.h"
#include "expensewidget.h"
#include "incomewidget.h"
#include "./ui_dough.h"
#include <QDebug>
#include <QMessageBox>

dough::dough(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dough)
    , expenseWidget(nullptr) // Initialize the pointer to nullptr
    , incomeWidget(nullptr) // Initialize the pointer to nullptr
{
    ui->setupUi(this);

    widget_home = ui->widget_home;
    widget_expenses = ui->widget_expenses;
    widget_incomes = ui->widget_incomes;
    widget_reports = ui->widget_report;

    connect(ui->pushButton_expense, &QPushButton::clicked, this, &dough::on_pushButton_expense_clicked);
    connect(ui->pushButton_income, &QPushButton::clicked, this, &dough::on_pushButton_income_clicked);
    connect(ui->pushButton_homepage, &QPushButton::clicked, this, &dough::showHomePage);
    connect(ui->pushButton_expensepage, &QPushButton::clicked, this, &dough::showExpensePage);
    connect(ui->pushButton_incomepage, &QPushButton::clicked, this, &dough::showIncomePage);
    connect(ui->pushButton_reportpage, &QPushButton::clicked, this, &dough::showReportPage);

    // Assign tableView_expenses and tableView_incomes from UI
    tableView_expenses = ui->tableView_expenses;
    tableView_incomes = ui->tableView_incomes;

    DatabaseManager &dbManager = DatabaseManager::getInstance();
    // tableView_expenses->setModel(dbManager.getExpensesModel());
    // tableView_incomes->setModel(dbManager.getIncomesModel());
    dbManager.clearExpenses();
    dbManager.clearIncomes();

    ui->stackedWidget->setCurrentWidget(widget_home);
}

dough::~dough()
{
    delete ui;
}

void dough::on_pushButton_expense_clicked()
{
    qDebug() << "Expense button clicked";
    if (!expenseWidget) {
        expenseWidget = new ExpenseWidget(this);
        expenseWidget->setAttribute(Qt::WA_DeleteOnClose); // Ensure it deletes itself when closed
        connect(expenseWidget, &ExpenseWidget::finished, this, &dough::onExpenseWidgetClosed);
        expenseWidget->show(); // Show the dialog non-modally
    }
}

void dough::onExpenseWidgetClosed(int result)
{
    qDebug() << "Expense widget closed with result:" << result;
    if (result == QDialog::Accepted) {
        qDebug() << "Dialog accepted";
        // Handle any necessary actions after the dialog is accepted
        // For example: QMessageBox::information(this, "Popup Accepted", "The popup was accepted.");
    }
    expenseWidget = nullptr; // Reset the pointer after the dialog is closed
    updateExpensesView();
}

void dough::on_pushButton_income_clicked()
{
    qDebug() << "Income button clicked";
    if (!incomeWidget) {
        incomeWidget = new IncomeWidget(this);
        incomeWidget->setAttribute(Qt::WA_DeleteOnClose); // Ensure it deletes itself when closed
        connect(incomeWidget, &IncomeWidget::finished, this, &dough::onIncomeWidgetClosed);
        incomeWidget->show(); // Show the dialog non-modally
    }
}

void dough::onIncomeWidgetClosed(int result)
{
    qDebug() << "Income widget closed with result:" << result;
    if (result == QDialog::Accepted) {
        qDebug() << "Dialog accepted";
        // Handle any necessary actions after the dialog is accepted
        // For example: QMessageBox::information(this, "Popup Accepted", "The popup was accepted.");
    }
    incomeWidget = nullptr; // Reset the pointer after the dialog is closed
    updateIncomesView();
}

void dough::on_tableView_expenses_activated(const QModelIndex &index)
{
    qDebug() << "Expenses list view activated";
    QSqlTableModel *model_expenses = new QSqlTableModel(this);
    model_expenses->setTable("expenses");
    model_expenses->select(); // Fetch data from database
    // QListView *tableView_expenses = findChild<QListView*>("tableView_expenses");
    // if (tableView_expenses) {
    //     tableView_expenses->setModel(model_expenses);
    // }
}

void dough::on_tableView_incomes_activated(const QModelIndex &index)
{
    qDebug() << "Incomes list view activated";
    QSqlTableModel *model_incomes = new QSqlTableModel(this);
    model_incomes->setTable("incomes");
    model_incomes->select(); // Fetch data from database
}

void dough::updateExpensesView()
{
    qDebug() << "Updating expenses view";
    DatabaseManager &dbManager = DatabaseManager::getInstance();
    if (tableView_expenses) {
        tableView_expenses->setModel(dbManager.getExpensesModel());
        qDebug() << "Expenses view updated";
    } else {
        qDebug() << "tableView_expenses is nullptr";
    }
}

void dough::updateIncomesView()
{
    qDebug() << "Updating incomes view";
    DatabaseManager &dbManager = DatabaseManager::getInstance();
    if (tableView_incomes) {
        tableView_incomes->setModel(dbManager.getIncomesModel());
        qDebug() << "Incomes view updated";
    } else {
        qDebug() << "tableView_incomes is nullptr";
    }
}

void dough::showHomePage()
{
    ui->stackedWidget->setCurrentWidget(widget_home);
}

void dough::showExpensePage()
{
    ui->stackedWidget->setCurrentWidget(widget_expenses);
}

void dough::showIncomePage()
{
    ui->stackedWidget->setCurrentWidget(widget_incomes);
}

void dough::showReportPage()
{
    ui->stackedWidget->setCurrentWidget(widget_reports);
}
