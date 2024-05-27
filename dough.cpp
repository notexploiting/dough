#include "dough.h"
#include "expensewidget.h"
#include "./ui_dough.h"
#include <QDebug>

dough::dough(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dough)
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
    ExpenseWidget *expenseWidget = new ExpenseWidget(this);
    expenseWidget->setAttribute(Qt::WA_DeleteOnClose);
    expenseWidget->show();
}

