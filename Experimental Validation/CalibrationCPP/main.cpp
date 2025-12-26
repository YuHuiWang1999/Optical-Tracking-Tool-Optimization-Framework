#include "CalibrationApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalibrationApp w;
    w.show();
    return a.exec();
}
