#ifndef INCOMEWIDGET_H
#define INCOMEWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDateTimeEdit>
#include <QLabel>
#include <QList>
#include <QMessageBox>

class IncomeWidget : public QDialog
{
    Q_OBJECT
public:
    explicit IncomeWidget(QWidget *parent = nullptr);
    ~IncomeWidget();

private slots:
    void on_pushButton_Submit_clicked();

private:
    // Income(const QDate &date, const QString &title, double amount, const QString &description = "");
    QLabel *label_date;
    QDateTimeEdit *dateTimeEdit_date;

    QLabel *label_title;
    QLineEdit *lineEdit_title;

    QLabel *label_amount;
    QLineEdit *lineEdit_amount;

    QLabel *label_description;
    QLineEdit *lineEdit_description;

    QPushButton *pushButton_Submit;

signals:
};

#endif // INCOMEWIDGET_H
