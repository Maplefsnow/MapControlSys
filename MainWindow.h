#pragma once

#include <QtWidgets/QMainWindow>
#include "Axis.h"
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindowClass ui;

public slots:
};
