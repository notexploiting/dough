#include "expensewidget.h"
#include "expense.h"
#include "databasemanager.h"

ExpenseWidget::ExpenseWidget(QWidget *parent)
    : QDialog{parent}
{
    // Set the popup size
    setFixedSize(400, 300);

    // Initialize and configure labels, input fields, and button(s)
    label_category = new QLabel("Category", this);
    comboBox_category = new QComboBox(this);
    QStringList categories = {"Food", "Transport", "Entertainment", "Utilities", "Others"};
    comboBox_category->addItems(categories);

    label_date = new QLabel("Date", this);
    dateTimeEdit_date = new QDateTimeEdit(this);
    dateTimeEdit_date->setDateTime(QDateTime::currentDateTime());

    label_title = new QLabel("Title", this);
    lineEdit_title = new QLineEdit(this);

    label_amount = new QLabel("Amount", this);
    lineEdit_amount = new QLineEdit(this);
    lineEdit_amount->setValidator(new QDoubleValidator(0, 1000000, 2, this)); // Add validator for amount

    label_description = new QLabel("Description", this);
    lineEdit_description = new QLineEdit(this);

    pushButton_Submit = new QPushButton("Submit", this);

    // Connect the submit button's clicked signal to the slot
    connect(pushButton_Submit, &QPushButton::clicked, this, &ExpenseWidget::on_pushButton_Submit_clicked);

    // Create and set layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label_category);
    layout->addWidget(comboBox_category);
    layout->addWidget(label_date);
    layout->addWidget(dateTimeEdit_date);
    layout->addWidget(label_title);
    layout->addWidget(lineEdit_title);
    layout->addWidget(label_amount);
    layout->addWidget(lineEdit_amount);
    layout->addWidget(label_description);
    layout->addWidget(lineEdit_description);
    layout->addWidget(pushButton_Submit);

    setLayout(layout); // Set the layout to the ExpenseWidget
}

ExpenseWidget::~ExpenseWidget()
{
}

void ExpenseWidget::on_pushButton_Submit_clicked()
{
    qDebug() << "Submit button clicked";

    // Handle submit button click (e.g., retrieve input data)
    // Close the dialog and return QDialog::Accepted
    // QMessageBox::information(this, "Popup Accepted", "The popup was accepted.");
    // QMessageBox msgBox;
    // msgBox.setText("The input was accepted.");
    // msgBox.exec();

    // dateTimeEdit_date->setDateTime(QDateTime::currentDateTime());

    //Expense(const QString &category, const QDate &date, const QString &title, double amount, const QString &description = "");
    QString category = comboBox_category->currentText();
    QDate date = dateTimeEdit_date->date();
    QString title = lineEdit_title->text();
    double amount = lineEdit_amount->text().toDouble();
    QString description = lineEdit_description->text();

    // Validate inputs
    if (title.isEmpty() || amount == 0.0 || !lineEdit_amount->hasAcceptableInput()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields with valid data.");
        return;
    }

    Expense expense = Expense(category, date, title, amount, description);

    // Get the database instance
    DatabaseManager& dbManager = DatabaseManager::getInstance();
    QSqlDatabase& db = dbManager.getDatabase();

    // Ensure the database is open
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database is not open. Please try again.");
        return;
    }

    // Add the expense to the database
    if (expense.addToDatabase(db)) {
        QMessageBox::information(this, "Success", "Expense added successfully.");
        accept(); // Close the dialog and return QDialog::Accepted
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to add expense to the database.");
    }
}
