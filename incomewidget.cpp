#include "incomewidget.h"
#include "income.h"
#include "databasemanager.h"

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
    qDebug() << "Submit button clicked";
    
    // Handle submit button click (e.g., retrieve input data)
    // Close the dialog and return QDialog::Accepted
    QDate date = dateTimeEdit_date->date();
    QString title = lineEdit_title->text();
    double amount = lineEdit_amount->text().toDouble();
    QString description = lineEdit_description->text();

    Income income = Income(date, title, amount, description);

    // Get the database instance
    DatabaseManager& dbManager = DatabaseManager::getInstance();
    QSqlDatabase& db = dbManager.getDatabase();

    // Ensure the database is open
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database is not open. Please try again.");
        return;
    }

    // Add the expense to the database
    if (income.addToDatabase(db)) {
        QMessageBox::information(this, "Success", "Income added successfully.");
        accept(); // Close the dialog and return QDialog::Accepted
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to add income to the database.");
    }
}
