#ifndef DOUGH_H
#define DOUGH_H

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

private:
    Ui::dough *ui;
};

#endif // DOUGH_H
