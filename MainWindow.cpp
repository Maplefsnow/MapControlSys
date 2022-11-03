#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

}

MainWindow::~MainWindow()
{}


//void MainWindow::onMenuOpen() {
//    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("(*.jpg)\n(*.bmp)\n(*.png)"));
//    QImage image = QImage(filename);
//
//    if (!image.isNull()) {
//        ui.statusBar->showMessage(tr("Open Image Success!"), 3000);
//        ui.imageLabel->setPixmap(QPixmap::fromImage(image).scaled(ui.imageLabel->size()));
//    }
//    else {
//        ui.statusBar->showMessage(tr("Save Image Failed!"), 3000);
//        return;
//    }
//}
//
//void MainWindow::onMenuSave() {
//    QPixmap image = ui.imageLabel->pixmap();
//    QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), QDir::homePath(), tr("(*.jpg)\n(*.png)\n(*.bmp)"));
//    if (image.save(filename, Q_NULLPTR, 100)) {
//        ui.statusBar->showMessage(tr("Save Image Success!"), 3000);
//    }
//    else {
//        ui.statusBar->showMessage(tr("Save Image Failed!"), 3000);
//    }
//}
