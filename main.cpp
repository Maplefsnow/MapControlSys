#include "MainWindow.h"
#include <QtWidgets/QApplication>

#pragma comment(lib, "ADVMOT.lib")

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
