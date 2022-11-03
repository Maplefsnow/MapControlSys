/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "MotorPanel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen_Image;
    QAction *actionSave_Image;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    MotorPanel *motorWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_5;
    QSpinBox *spinBox_initVel;
    QSpinBox *spinBox_runningVel;
    QLabel *label_2;
    QSpinBox *spinBox_PPUDenominator;
    QLabel *label_4;
    QSpinBox *spinBox_PPU;
    QLabel *label;
    QSpinBox *spinBox_dec;
    QSpinBox *spinBox_acc;
    QPushButton *paramsSetButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QSpinBox *spinBox_runDis;
    QToolButton *button_runDis;
    QLabel *label_9;
    QFrame *line;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QLabel *label_cardID;
    QPushButton *pushButton;
    QLabel *label_12;
    QComboBox *comboBox_axisID;
    QPushButton *pushButton_initAxis;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLineEdit *lineEdit_runningStatus;
    QLabel *label_8;
    QLineEdit *lineEdit_nowPos;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(805, 360);
        actionOpen_Image = new QAction(MainWindowClass);
        actionOpen_Image->setObjectName(QString::fromUtf8("actionOpen_Image"));
        actionSave_Image = new QAction(MainWindowClass);
        actionSave_Image->setObjectName(QString::fromUtf8("actionSave_Image"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        motorWidget = new MotorPanel(centralWidget);
        motorWidget->setObjectName(QString::fromUtf8("motorWidget"));
        gridLayout_3 = new QGridLayout(motorWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(motorWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\230\277\351\207\214\345\267\264\345\267\264\346\231\256\346\203\240\344\275\223 2.0 55 Regular")});
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\230\277\351\207\214\345\267\264\345\267\264\346\231\256\346\203\240\344\275\223 2.0 55 Regular")});
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 5, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        spinBox_initVel = new QSpinBox(groupBox);
        spinBox_initVel->setObjectName(QString::fromUtf8("spinBox_initVel"));
        spinBox_initVel->setMinimumSize(QSize(110, 22));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\230\277\351\207\214\345\267\264\345\267\264\346\231\256\346\203\240\344\275\223 2.0 55 Regular")});
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setKerning(true);
        spinBox_initVel->setFont(font2);
        spinBox_initVel->setMouseTracking(false);
        spinBox_initVel->setTabletTracking(false);
        spinBox_initVel->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_initVel->setMinimum(0);
        spinBox_initVel->setMaximum(10000000);
        spinBox_initVel->setValue(10);

        gridLayout_2->addWidget(spinBox_initVel, 5, 1, 1, 1);

        spinBox_runningVel = new QSpinBox(groupBox);
        spinBox_runningVel->setObjectName(QString::fromUtf8("spinBox_runningVel"));
        spinBox_runningVel->setMinimumSize(QSize(110, 22));
        spinBox_runningVel->setFont(font2);
        spinBox_runningVel->setMouseTracking(false);
        spinBox_runningVel->setTabletTracking(false);
        spinBox_runningVel->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_runningVel->setMinimum(0);
        spinBox_runningVel->setMaximum(10000000);
        spinBox_runningVel->setValue(10);

        gridLayout_2->addWidget(spinBox_runningVel, 4, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        spinBox_PPUDenominator = new QSpinBox(groupBox);
        spinBox_PPUDenominator->setObjectName(QString::fromUtf8("spinBox_PPUDenominator"));
        spinBox_PPUDenominator->setMinimumSize(QSize(110, 22));
        spinBox_PPUDenominator->setFont(font2);
        spinBox_PPUDenominator->setMouseTracking(false);
        spinBox_PPUDenominator->setTabletTracking(false);
        spinBox_PPUDenominator->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_PPUDenominator->setMinimum(0);
        spinBox_PPUDenominator->setMaximum(10000000);
        spinBox_PPUDenominator->setValue(1);

        gridLayout_2->addWidget(spinBox_PPUDenominator, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        spinBox_PPU = new QSpinBox(groupBox);
        spinBox_PPU->setObjectName(QString::fromUtf8("spinBox_PPU"));
        spinBox_PPU->setMinimumSize(QSize(110, 22));
        spinBox_PPU->setFont(font2);
        spinBox_PPU->setMouseTracking(false);
        spinBox_PPU->setTabletTracking(false);
        spinBox_PPU->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_PPU->setMinimum(0);
        spinBox_PPU->setMaximum(10000000);
        spinBox_PPU->setValue(10);

        gridLayout_2->addWidget(spinBox_PPU, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        spinBox_dec = new QSpinBox(groupBox);
        spinBox_dec->setObjectName(QString::fromUtf8("spinBox_dec"));
        spinBox_dec->setMinimumSize(QSize(110, 22));
        spinBox_dec->setSizeIncrement(QSize(1, 1111));
        spinBox_dec->setFont(font2);
        spinBox_dec->setMouseTracking(false);
        spinBox_dec->setTabletTracking(false);
        spinBox_dec->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_dec->setMinimum(0);
        spinBox_dec->setMaximum(10000000);
        spinBox_dec->setValue(10);

        gridLayout_2->addWidget(spinBox_dec, 3, 1, 1, 1);

        spinBox_acc = new QSpinBox(groupBox);
        spinBox_acc->setObjectName(QString::fromUtf8("spinBox_acc"));
        spinBox_acc->setMinimumSize(QSize(110, 22));
        spinBox_acc->setFont(font2);
        spinBox_acc->setMouseTracking(false);
        spinBox_acc->setTabletTracking(false);
        spinBox_acc->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_acc->setMinimum(0);
        spinBox_acc->setMaximum(10000000);
        spinBox_acc->setValue(10);

        gridLayout_2->addWidget(spinBox_acc, 2, 1, 1, 1);

        paramsSetButton = new QPushButton(groupBox);
        paramsSetButton->setObjectName(QString::fromUtf8("paramsSetButton"));
        paramsSetButton->setAutoDefault(false);
        paramsSetButton->setFlat(false);

        gridLayout_2->addWidget(paramsSetButton, 6, 0, 1, 2);


        gridLayout_3->addWidget(groupBox, 0, 0, 2, 1);

        groupBox_3 = new QGroupBox(motorWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\230\277\351\207\214\345\267\264\345\267\264\346\231\256\346\203\240\344\275\223 2.0 55 Regular")});
        font3.setPointSize(11);
        font3.setBold(false);
        groupBox_3->setFont(font3);
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        spinBox_runDis = new QSpinBox(groupBox_3);
        spinBox_runDis->setObjectName(QString::fromUtf8("spinBox_runDis"));
        spinBox_runDis->setMinimum(-10000000);
        spinBox_runDis->setMaximum(10000000);
        spinBox_runDis->setValue(1);

        gridLayout_4->addWidget(spinBox_runDis, 1, 1, 1, 1);

        button_runDis = new QToolButton(groupBox_3);
        button_runDis->setObjectName(QString::fromUtf8("button_runDis"));

        gridLayout_4->addWidget(button_runDis, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 0, 1, 1);

        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 2, 0, 1, 3);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_3 = new QToolButton(groupBox_4);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(groupBox_4);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(groupBox_4);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));

        horizontalLayout->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(groupBox_4);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));

        horizontalLayout->addWidget(toolButton_6);


        gridLayout_4->addWidget(groupBox_4, 3, 0, 1, 3);


        gridLayout_3->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(motorWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        label_cardID = new QLabel(groupBox_5);
        label_cardID->setObjectName(QString::fromUtf8("label_cardID"));

        gridLayout->addWidget(label_cardID, 0, 1, 1, 1);

        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 1, 0, 1, 1);

        comboBox_axisID = new QComboBox(groupBox_5);
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->setObjectName(QString::fromUtf8("comboBox_axisID"));

        gridLayout->addWidget(comboBox_axisID, 1, 1, 1, 1);

        pushButton_initAxis = new QPushButton(groupBox_5);
        pushButton_initAxis->setObjectName(QString::fromUtf8("pushButton_initAxis"));

        gridLayout->addWidget(pushButton_initAxis, 2, 0, 1, 3);


        gridLayout_3->addWidget(groupBox_5, 0, 2, 2, 1);

        groupBox_2 = new QGroupBox(motorWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font3);
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        lineEdit_runningStatus = new QLineEdit(groupBox_2);
        lineEdit_runningStatus->setObjectName(QString::fromUtf8("lineEdit_runningStatus"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_runningStatus);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        lineEdit_nowPos = new QLineEdit(groupBox_2);
        lineEdit_nowPos->setObjectName(QString::fromUtf8("lineEdit_nowPos"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_nowPos);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 1);


        gridLayout_5->addWidget(motorWidget, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 805, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionOpen_Image);
        menuMenu->addAction(actionSave_Image);

        retranslateUi(MainWindowClass);
        QObject::connect(paramsSetButton, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::setMotorParams));
        QObject::connect(pushButton, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::checkCard));
        QObject::connect(pushButton_initAxis, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::initAxis));

        paramsSetButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        actionOpen_Image->setText(QCoreApplication::translate("MainWindowClass", "Open Image...", nullptr));
        actionSave_Image->setText(QCoreApplication::translate("MainWindowClass", "Save Image", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindowClass", "\347\224\265\346\234\272\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowClass", "\345\210\235\351\200\237\345\272\246", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindowClass", "\345\207\217\351\200\237\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindowClass", "\345\212\240\351\200\237\345\272\246", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowClass", "PPU Denominator", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowClass", "\350\277\220\350\241\214\351\200\237\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("MainWindowClass", "PPU", nullptr));
        paramsSetButton->setText(QCoreApplication::translate("MainWindowClass", "\350\256\276\347\275\256\345\217\202\346\225\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindowClass", "\346\223\215\344\275\234\351\235\242\346\235\277", nullptr));
        button_runDis->setText(QCoreApplication::translate("MainWindowClass", "GO", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindowClass", "\350\277\220\350\241\214\350\267\235\347\246\273 (PPU)", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindowClass", "\345\276\256\350\260\203", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindowClass", "<<", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindowClass", "<", nullptr));
        toolButton_5->setText(QCoreApplication::translate("MainWindowClass", ">", nullptr));
        toolButton_6->setText(QCoreApplication::translate("MainWindowClass", ">>", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindowClass", "\347\224\265\346\234\272\345\210\235\345\247\213\345\214\226", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindowClass", "\346\235\277\345\215\241ID\357\274\232", nullptr));
        label_cardID->setText(QCoreApplication::translate("MainWindowClass", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowClass", "\346\243\200\346\265\213", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowClass", "\350\275\264\357\274\232", nullptr));
        comboBox_axisID->setItemText(0, QCoreApplication::translate("MainWindowClass", "0", nullptr));
        comboBox_axisID->setItemText(1, QCoreApplication::translate("MainWindowClass", "1", nullptr));
        comboBox_axisID->setItemText(2, QCoreApplication::translate("MainWindowClass", "2", nullptr));
        comboBox_axisID->setItemText(3, QCoreApplication::translate("MainWindowClass", "3", nullptr));
        comboBox_axisID->setItemText(4, QCoreApplication::translate("MainWindowClass", "4", nullptr));
        comboBox_axisID->setItemText(5, QCoreApplication::translate("MainWindowClass", "5", nullptr));

        pushButton_initAxis->setText(QCoreApplication::translate("MainWindowClass", "\345\210\235\345\247\213\345\214\226\350\275\264", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindowClass", "\347\224\265\346\234\272\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindowClass", "\350\277\220\350\241\214\347\212\266\346\200\201", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindowClass", "\345\275\223\345\211\215\344\275\215\347\275\256", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindowClass", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
