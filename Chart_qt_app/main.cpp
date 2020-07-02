#include "Chart_qt_app.h"
#include <QtWidgets/QApplication>
#include "Repository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo r("WHO-situation-reports.csv");
    Chart_qt_app w(r);
    w.show();
    return a.exec();
}
