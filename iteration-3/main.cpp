//Varun Dalal A04743047
#include <QApplication>

#include "mainwindow.h"
#include "globj.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Q_INIT_RESOURCE(dockwidgets);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
#include <QApplication>

#include "mainwindow.h"

