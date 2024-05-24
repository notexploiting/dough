#include "dough.h"

#include <QApplication>

#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager dbManager;
    if (dbManager.openDatabase("dough.db"))
    {
        dbManager.createTables();
    }

    dough w;
    w.show();

    return a.exec();
}
