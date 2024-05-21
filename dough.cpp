#include "dough.h"
#include "./ui_dough.h"

dough::dough(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dough)
{
    ui->setupUi(this);
}

dough::~dough()
{
    delete ui;
}
