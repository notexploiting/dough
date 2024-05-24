#include "dough.h"
#include "./ui_dough.h"
#include <QDebug>

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


