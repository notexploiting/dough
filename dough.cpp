#include "dough.h"
#include "expensewidget.h"
#include "./ui_dough.h"
#include <QDebug>
#include <QMessageBox>

dough::dough(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dough)
    , expenseWidget(nullptr) // Initialize the pointer to nullptr
{
    ui->setupUi(this);
    connect(ui->pushButton_expense, &QPushButton::clicked, this, &dough::on_pushButton_expense_clicked);
}

dough::~dough()
{
    delete ui;
}

void dough::on_pushButton_expense_clicked()
{
    if (!expenseWidget) {
        expenseWidget = new ExpenseWidget(this);
        expenseWidget->setAttribute(Qt::WA_DeleteOnClose); // Ensure it deletes itself when closed
        connect(expenseWidget, &ExpenseWidget::finished, this, &dough::onExpenseWidgetClosed);
        expenseWidget->show(); // Show the dialog non-modally
    }
}

void dough::onExpenseWidgetClosed(int result)
{
    if (result == QDialog::Accepted) {
        // Handle any necessary actions after the dialog is accepted
        // For example: QMessageBox::information(this, "Popup Accepted", "The popup was accepted.");
    }
    expenseWidget = nullptr; // Reset the pointer after the dialog is closed
}
