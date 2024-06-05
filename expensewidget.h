#ifndef EXPENSEWIDGET_H
#define EXPENSEWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDateTimeEdit>
#include <QLabel>
#include <QList>
#include <QMessageBox>
#include <QComboBox>

class ExpenseWidget : public QDialog
{
    Q_OBJECT
public:
    explicit ExpenseWidget(QWidget *parent = nullptr);
    ~ExpenseWidget();

private slots:
    void on_pushButton_Submit_clicked();

private:
    // Expense(const QString &category, const QDate &date, const QString &title, double amount, const QString &description = "");
    QLabel *label_category;
    QLineEdit *lineEdit_category;

    QLabel *label_date;
    QDateTimeEdit *dateTimeEdit_date;

    QLabel *label_title;
    QLineEdit *lineEdit_title;

    QLabel *label_amount;
    QLineEdit *lineEdit_amount;

    QLabel *label_description;
    QLineEdit *lineEdit_description;

    QPushButton *pushButton_Submit;

    QComboBox *comboBox_category;

signals:
};

#endif // EXPENSEWIDGET_H
