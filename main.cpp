#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("Vestax");
    QApplication::setApplicationName("ProgramSettings");
    MainWindow w;
    w.show();

    return a.exec();
}
