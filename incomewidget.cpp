#include "incomewidget.h"

IncomeWidget::IncomeWidget(QWidget *parent)
    : QDialog{parent}
{
    // Set the popup size
    setFixedSize(400, 300);

    // Initialize and configure labels, input fields, and button(s)
    label_date = new QLabel("Date", this);
    dateTimeEdit_date = new QDateTimeEdit(this);
    dateTimeEdit_date->setDateTime(QDateTime::currentDateTime());

    label_title = new QLabel("Title", this);
    lineEdit_title = new QLineEdit(this);

    label_amount = new QLabel("Amount", this);
    lineEdit_amount = new QLineEdit(this);

    label_description = new QLabel("Description", this);
    lineEdit_description = new QLineEdit(this);

    pushButton_Submit = new QPushButton("Submit", this);

    // Connect the submit button's clicked signal to the slot
    connect(pushButton_Submit, &QPushButton::clicked, this, &IncomeWidget::on_pushButton_Submit_clicked);

    // Create and set layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label_date);
    layout->addWidget(dateTimeEdit_date);
    layout->addWidget(label_title);
    layout->addWidget(lineEdit_title);
    layout->addWidget(label_amount);
    layout->addWidget(lineEdit_amount);
    layout->addWidget(label_description);
    layout->addWidget(lineEdit_description);
    layout->addWidget(pushButton_Submit);

    setLayout(layout); // Set the layout to the IncomeWidget
}

IncomeWidget::~IncomeWidget()
{
}

void IncomeWidget::on_pushButton_Submit_clicked()
{
    // Handle submit button click (e.g., retrieve input data)
    QString title = lineEdit_title->text();
    // Close the dialog and return QDialog::Accepted
    if (!title.isEmpty()) {
        // QMessageBox::information(this, "Popup Accepted", "The popup was accepted.");
        // QMessageBox msgBox;
        // msgBox.setText("The input was accepted.");
        // msgBox.exec();
        dateTimeEdit_date->setDateTime(QDateTime::currentDateTime());
        accept(); // Close the dialog and return QDialog::Accepted
    } else {
        QMessageBox::warning(this, "Input Error", "The title field cannot be empty.");
    }
}
