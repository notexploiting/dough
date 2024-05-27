#ifndef DOUGH_H
#define DOUGH_H

#include "qpushbutton.h"
#include <QWidget>
#include <QDate>
#include <QString>
#include <vector>

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

private:
    Ui::dough *ui;
    QPushButton *pustButton_expense;
};

#endif // DOUGH_H
