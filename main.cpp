#include "dough.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dough w;
    w.show();
    return a.exec();
}
