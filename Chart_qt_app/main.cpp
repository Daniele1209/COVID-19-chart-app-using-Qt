#include "Chart_qt_app.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chart_qt_app w;
    w.show();
    return a.exec();
}
