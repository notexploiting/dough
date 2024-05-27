#include "expensewidget.h"

ExpenseWidget::ExpenseWidget(QWidget *parent)
    : QWidget{parent}
{
    // Set the popup size
    resize(300, 200);

    // Create and configure labels, input fields, and button(s)
    QList<QWidget*>widgetsList;

    QLabel *label_category = new QLabel(this);
    label_category->setText("Category");
    QLineEdit *lineEdit_category = new QLineEdit(this);
    widgetsList.append(label_category);
    widgetsList.append(lineEdit_category);

    QLabel *label_date = new QLabel(this);
    label_date->setText("Date");
    QDateTimeEdit *dateTimeEdit_date = new QDateTimeEdit(this);
    widgetsList.append(label_date);
    widgetsList.append(dateTimeEdit_date);

    QLabel *label_title = new QLabel(this);
    label_title->setText("Title");
    QLineEdit *lineEdit_title = new QLineEdit(this);
    widgetsList.append(label_title);
    widgetsList.append(lineEdit_title);

    QLabel *label_amount = new QLabel(this);
    label_amount->setText("Amount");
    QLineEdit *lineEdit_amount = new QLineEdit(this);
    widgetsList.append(label_amount);
    widgetsList.append(lineEdit_amount);

    QLabel *label_description = new QLabel(this);
    label_description->setText("Description");
    QLineEdit *lineEdit_description = new QLineEdit(this);
    widgetsList.append(label_description);
    widgetsList.append(lineEdit_description);

    pushButton_Submit = new QPushButton("Submit", this);

    // Connect the submit button's clicked signal to the slot
    connect(pushButton_Submit, &QPushButton::clicked, this, &ExpenseWidget::on_pushButton_Submit_clicked);

    // Create and set layout
    QVBoxLayout *layout = new QVBoxLayout();
    for (QWidget *widget : widgetsList) {
        layout->addWidget(widget);
    }
    setLayout(layout); // Set the layout to the ExpenseWidget, ensuring proper memory management
}

ExpenseWidget::~ExpenseWidget()
{
}

void ExpenseWidget::on_pushButton_Submit_clicked()
{
    // Handle submit button click (e.g., retrieve input data)
    close();
}
