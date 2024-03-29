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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CameraPanel.h"
#include "LaserSensorPanel.h"
#include "MotorPanel.h"
#include "RelayPanel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen_Image;
    QAction *actionSave_Image;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_2;
    RelayPanel *relayWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_17;
    QComboBox *comboBox_relayCards;
    QPushButton *pushButton_openRelayCards;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_axis0Switcher;
    QCheckBox *checkBox_axis1Switcher;
    QCheckBox *checkBox_laserSensorSwitcher;
    QCheckBox *checkBox_airValveSwitcher;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    LaserSensorPanel *laserSensorWidget;
    QGridLayout *gridLayout_7;
    QLabel *label_laserSensorDis;
    QLabel *label_laserSensorVoltage;
    QLabel *label_13;
    QLabel *label_14;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    CameraPanel *cameraPanel;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QLabel *label_camSN;
    QPushButton *pushButton_detectCam;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_startGrab;
    QPushButton *pushButton_stopGrab;
    QLabel *label_cameraImage;
    QGroupBox *groupBox_Motor;
    QGridLayout *gridLayout_4;
    MotorPanel *motorWidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLabel *label_realPos;
    QFrame *line_3;
    QLabel *label_8;
    QLabel *label_cmdPos;
    QFrame *line_2;
    QLabel *label_7;
    QLabel *label_status;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *paramsSetButton;
    QSpinBox *spinBox_runningVel;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox_PPU;
    QSpinBox *spinBox_acc;
    QLabel *label_6;
    QSpinBox *spinBox_PPUDenominator;
    QSpinBox *spinBox_dec;
    QSpinBox *spinBox_initVel;
    QLabel *label_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLabel *label_cardID;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QComboBox *comboBox_axisID;
    QPushButton *pushButton_initAxis;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_runDis;
    QToolButton *button_runDis;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *toolButton_RevXCmove;
    QToolButton *toolButton_RevXmove;
    QToolButton *toolButton_stopMotor;
    QToolButton *toolButton_Xmove;
    QToolButton *toolButton_XCmove;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_setAxisZero;
    QPushButton *pushButton_axisReturnHome;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1068, 685);
        actionOpen_Image = new QAction(MainWindowClass);
        actionOpen_Image->setObjectName(QString::fromUtf8("actionOpen_Image"));
        actionSave_Image = new QAction(MainWindowClass);
        actionSave_Image->setObjectName(QString::fromUtf8("actionSave_Image"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        QFont font;
        font.setPointSize(11);
        groupBox_8->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_8);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        relayWidget = new RelayPanel(groupBox_8);
        relayWidget->setObjectName(QString::fromUtf8("relayWidget"));
        verticalLayout = new QVBoxLayout(relayWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_17 = new QLabel(relayWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_7->addWidget(label_17);

        comboBox_relayCards = new QComboBox(relayWidget);
        comboBox_relayCards->addItem(QString());
        comboBox_relayCards->addItem(QString());
        comboBox_relayCards->addItem(QString());
        comboBox_relayCards->addItem(QString());
        comboBox_relayCards->addItem(QString());
        comboBox_relayCards->setObjectName(QString::fromUtf8("comboBox_relayCards"));

        horizontalLayout_7->addWidget(comboBox_relayCards);

        pushButton_openRelayCards = new QPushButton(relayWidget);
        pushButton_openRelayCards->setObjectName(QString::fromUtf8("pushButton_openRelayCards"));

        horizontalLayout_7->addWidget(pushButton_openRelayCards);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        checkBox_axis0Switcher = new QCheckBox(relayWidget);
        checkBox_axis0Switcher->setObjectName(QString::fromUtf8("checkBox_axis0Switcher"));
        checkBox_axis0Switcher->setEnabled(false);
        checkBox_axis0Switcher->setIconSize(QSize(16, 16));
        checkBox_axis0Switcher->setCheckable(true);
        checkBox_axis0Switcher->setAutoRepeat(false);
        checkBox_axis0Switcher->setTristate(false);

        horizontalLayout_6->addWidget(checkBox_axis0Switcher);

        checkBox_axis1Switcher = new QCheckBox(relayWidget);
        checkBox_axis1Switcher->setObjectName(QString::fromUtf8("checkBox_axis1Switcher"));
        checkBox_axis1Switcher->setEnabled(false);

        horizontalLayout_6->addWidget(checkBox_axis1Switcher);

        checkBox_laserSensorSwitcher = new QCheckBox(relayWidget);
        checkBox_laserSensorSwitcher->setObjectName(QString::fromUtf8("checkBox_laserSensorSwitcher"));
        checkBox_laserSensorSwitcher->setEnabled(false);
        checkBox_laserSensorSwitcher->setIconSize(QSize(16, 16));
        checkBox_laserSensorSwitcher->setAutoRepeat(false);
        checkBox_laserSensorSwitcher->setTristate(false);

        horizontalLayout_6->addWidget(checkBox_laserSensorSwitcher);

        checkBox_airValveSwitcher = new QCheckBox(relayWidget);
        checkBox_airValveSwitcher->setObjectName(QString::fromUtf8("checkBox_airValveSwitcher"));
        checkBox_airValveSwitcher->setEnabled(false);
        checkBox_airValveSwitcher->setIconSize(QSize(16, 16));
        checkBox_airValveSwitcher->setAutoRepeat(false);
        checkBox_airValveSwitcher->setTristate(false);

        horizontalLayout_6->addWidget(checkBox_airValveSwitcher);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(relayWidget);


        gridLayout_3->addWidget(groupBox_8, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setFont(font);
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        laserSensorWidget = new LaserSensorPanel(groupBox_6);
        laserSensorWidget->setObjectName(QString::fromUtf8("laserSensorWidget"));
        gridLayout_7 = new QGridLayout(laserSensorWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_laserSensorDis = new QLabel(laserSensorWidget);
        label_laserSensorDis->setObjectName(QString::fromUtf8("label_laserSensorDis"));

        gridLayout_7->addWidget(label_laserSensorDis, 1, 1, 1, 1);

        label_laserSensorVoltage = new QLabel(laserSensorWidget);
        label_laserSensorVoltage->setObjectName(QString::fromUtf8("label_laserSensorVoltage"));

        gridLayout_7->addWidget(label_laserSensorVoltage, 0, 1, 1, 1);

        label_13 = new QLabel(laserSensorWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_7->addWidget(label_13, 0, 0, 1, 1);

        label_14 = new QLabel(laserSensorWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_7->addWidget(label_14, 1, 0, 1, 1);


        gridLayout_6->addWidget(laserSensorWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_6, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font);
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cameraPanel = new CameraPanel(groupBox_4);
        cameraPanel->setObjectName(QString::fromUtf8("cameraPanel"));
        verticalLayout_5 = new QVBoxLayout(cameraPanel);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_15 = new QLabel(cameraPanel);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_9->addWidget(label_15);

        label_camSN = new QLabel(cameraPanel);
        label_camSN->setObjectName(QString::fromUtf8("label_camSN"));

        horizontalLayout_9->addWidget(label_camSN);

        pushButton_detectCam = new QPushButton(cameraPanel);
        pushButton_detectCam->setObjectName(QString::fromUtf8("pushButton_detectCam"));

        horizontalLayout_9->addWidget(pushButton_detectCam);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_startGrab = new QPushButton(cameraPanel);
        pushButton_startGrab->setObjectName(QString::fromUtf8("pushButton_startGrab"));

        horizontalLayout_10->addWidget(pushButton_startGrab);

        pushButton_stopGrab = new QPushButton(cameraPanel);
        pushButton_stopGrab->setObjectName(QString::fromUtf8("pushButton_stopGrab"));

        horizontalLayout_10->addWidget(pushButton_stopGrab);


        verticalLayout_5->addLayout(horizontalLayout_10);

        label_cameraImage = new QLabel(cameraPanel);
        label_cameraImage->setObjectName(QString::fromUtf8("label_cameraImage"));
        label_cameraImage->setMinimumSize(QSize(400, 400));

        verticalLayout_5->addWidget(label_cameraImage);


        gridLayout->addWidget(cameraPanel, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 0, 2, 2, 1);

        groupBox_Motor = new QGroupBox(centralWidget);
        groupBox_Motor->setObjectName(QString::fromUtf8("groupBox_Motor"));
        groupBox_Motor->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_Motor);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        motorWidget = new MotorPanel(groupBox_Motor);
        motorWidget->setObjectName(QString::fromUtf8("motorWidget"));
        gridLayout_5 = new QGridLayout(motorWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_2 = new QGroupBox(motorWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font1.setPointSize(11);
        font1.setBold(false);
        groupBox_2->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font2.setPointSize(11);
        font2.setBold(false);
        label_11->setFont(font2);

        horizontalLayout_2->addWidget(label_11);

        label_realPos = new QLabel(groupBox_2);
        label_realPos->setObjectName(QString::fromUtf8("label_realPos"));
        label_realPos->setFont(font2);

        horizontalLayout_2->addWidget(label_realPos);

        line_3 = new QFrame(groupBox_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFont(font2);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        horizontalLayout_2->addWidget(label_8);

        label_cmdPos = new QLabel(groupBox_2);
        label_cmdPos->setObjectName(QString::fromUtf8("label_cmdPos"));
        label_cmdPos->setFont(font2);

        horizontalLayout_2->addWidget(label_cmdPos);

        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFont(font2);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        horizontalLayout_2->addWidget(label_7);

        label_status = new QLabel(groupBox_2);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setFont(font2);

        horizontalLayout_2->addWidget(label_status);


        gridLayout_5->addWidget(groupBox_2, 2, 0, 1, 2);

        groupBox = new QGroupBox(motorWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        groupBox->setFont(font3);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(false);
        label->setFont(font4);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        paramsSetButton = new QPushButton(groupBox);
        paramsSetButton->setObjectName(QString::fromUtf8("paramsSetButton"));
        paramsSetButton->setFont(font3);
        paramsSetButton->setAutoDefault(false);
        paramsSetButton->setFlat(false);

        gridLayout_2->addWidget(paramsSetButton, 6, 0, 1, 3);

        spinBox_runningVel = new QSpinBox(groupBox);
        spinBox_runningVel->setObjectName(QString::fromUtf8("spinBox_runningVel"));
        spinBox_runningVel->setMinimumSize(QSize(110, 22));
        spinBox_runningVel->setFont(font4);
        spinBox_runningVel->setMouseTracking(false);
        spinBox_runningVel->setTabletTracking(false);
        spinBox_runningVel->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_runningVel->setMinimum(0);
        spinBox_runningVel->setMaximum(10000000);
        spinBox_runningVel->setValue(10);

        gridLayout_2->addWidget(spinBox_runningVel, 4, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font4);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font4);

        gridLayout_2->addWidget(label_3, 5, 0, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font4);

        gridLayout_2->addWidget(label_4, 4, 0, 1, 2);

        spinBox_PPU = new QSpinBox(groupBox);
        spinBox_PPU->setObjectName(QString::fromUtf8("spinBox_PPU"));
        spinBox_PPU->setMinimumSize(QSize(110, 22));
        spinBox_PPU->setFont(font4);
        spinBox_PPU->setMouseTracking(false);
        spinBox_PPU->setTabletTracking(false);
        spinBox_PPU->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_PPU->setMinimum(0);
        spinBox_PPU->setMaximum(10000000);
        spinBox_PPU->setValue(10);

        gridLayout_2->addWidget(spinBox_PPU, 0, 2, 1, 1);

        spinBox_acc = new QSpinBox(groupBox);
        spinBox_acc->setObjectName(QString::fromUtf8("spinBox_acc"));
        spinBox_acc->setMinimumSize(QSize(110, 22));
        spinBox_acc->setFont(font4);
        spinBox_acc->setMouseTracking(false);
        spinBox_acc->setTabletTracking(false);
        spinBox_acc->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_acc->setMinimum(0);
        spinBox_acc->setMaximum(10000000);
        spinBox_acc->setValue(10);

        gridLayout_2->addWidget(spinBox_acc, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font4);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 2);

        spinBox_PPUDenominator = new QSpinBox(groupBox);
        spinBox_PPUDenominator->setObjectName(QString::fromUtf8("spinBox_PPUDenominator"));
        spinBox_PPUDenominator->setMinimumSize(QSize(110, 22));
        spinBox_PPUDenominator->setFont(font4);
        spinBox_PPUDenominator->setMouseTracking(false);
        spinBox_PPUDenominator->setTabletTracking(false);
        spinBox_PPUDenominator->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_PPUDenominator->setMinimum(0);
        spinBox_PPUDenominator->setMaximum(10000000);
        spinBox_PPUDenominator->setValue(1);

        gridLayout_2->addWidget(spinBox_PPUDenominator, 1, 2, 1, 1);

        spinBox_dec = new QSpinBox(groupBox);
        spinBox_dec->setObjectName(QString::fromUtf8("spinBox_dec"));
        spinBox_dec->setMinimumSize(QSize(110, 22));
        spinBox_dec->setSizeIncrement(QSize(1, 1111));
        spinBox_dec->setFont(font4);
        spinBox_dec->setMouseTracking(false);
        spinBox_dec->setTabletTracking(false);
        spinBox_dec->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_dec->setMinimum(0);
        spinBox_dec->setMaximum(10000000);
        spinBox_dec->setValue(10);

        gridLayout_2->addWidget(spinBox_dec, 3, 2, 1, 1);

        spinBox_initVel = new QSpinBox(groupBox);
        spinBox_initVel->setObjectName(QString::fromUtf8("spinBox_initVel"));
        spinBox_initVel->setMinimumSize(QSize(110, 22));
        spinBox_initVel->setFont(font4);
        spinBox_initVel->setMouseTracking(false);
        spinBox_initVel->setTabletTracking(false);
        spinBox_initVel->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox_initVel->setMinimum(0);
        spinBox_initVel->setMaximum(10000000);
        spinBox_initVel->setValue(10);

        gridLayout_2->addWidget(spinBox_initVel, 5, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font4);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 2);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(motorWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        horizontalLayout->addWidget(label_10);

        label_cardID = new QLabel(groupBox_5);
        label_cardID->setObjectName(QString::fromUtf8("label_cardID"));
        label_cardID->setFont(font);

        horizontalLayout->addWidget(label_cardID);

        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        horizontalLayout_3->addWidget(label_12);

        comboBox_axisID = new QComboBox(groupBox_5);
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->addItem(QString());
        comboBox_axisID->setObjectName(QString::fromUtf8("comboBox_axisID"));
        comboBox_axisID->setFont(font);

        horizontalLayout_3->addWidget(comboBox_axisID);


        verticalLayout_3->addLayout(horizontalLayout_3);

        pushButton_initAxis = new QPushButton(groupBox_5);
        pushButton_initAxis->setObjectName(QString::fromUtf8("pushButton_initAxis"));
        pushButton_initAxis->setFont(font);

        verticalLayout_3->addWidget(pushButton_initAxis);


        gridLayout_5->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(motorWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font1);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        horizontalLayout_5->addWidget(label_9);

        doubleSpinBox_runDis = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_runDis->setObjectName(QString::fromUtf8("doubleSpinBox_runDis"));
        doubleSpinBox_runDis->setDecimals(4);
        doubleSpinBox_runDis->setMinimum(-10000000.000000000000000);
        doubleSpinBox_runDis->setMaximum(10000000.000000000000000);
        doubleSpinBox_runDis->setSingleStep(0.100000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_runDis);

        button_runDis = new QToolButton(groupBox_3);
        button_runDis->setObjectName(QString::fromUtf8("button_runDis"));
        button_runDis->setFont(font1);

        horizontalLayout_5->addWidget(button_runDis);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        toolButton_RevXCmove = new QToolButton(groupBox_3);
        toolButton_RevXCmove->setObjectName(QString::fromUtf8("toolButton_RevXCmove"));
        toolButton_RevXCmove->setFont(font1);

        horizontalLayout_8->addWidget(toolButton_RevXCmove);

        toolButton_RevXmove = new QToolButton(groupBox_3);
        toolButton_RevXmove->setObjectName(QString::fromUtf8("toolButton_RevXmove"));
        toolButton_RevXmove->setFont(font1);

        horizontalLayout_8->addWidget(toolButton_RevXmove);

        toolButton_stopMotor = new QToolButton(groupBox_3);
        toolButton_stopMotor->setObjectName(QString::fromUtf8("toolButton_stopMotor"));
        toolButton_stopMotor->setFont(font1);

        horizontalLayout_8->addWidget(toolButton_stopMotor);

        toolButton_Xmove = new QToolButton(groupBox_3);
        toolButton_Xmove->setObjectName(QString::fromUtf8("toolButton_Xmove"));
        toolButton_Xmove->setFont(font1);

        horizontalLayout_8->addWidget(toolButton_Xmove);

        toolButton_XCmove = new QToolButton(groupBox_3);
        toolButton_XCmove->setObjectName(QString::fromUtf8("toolButton_XCmove"));
        toolButton_XCmove->setFont(font1);

        horizontalLayout_8->addWidget(toolButton_XCmove);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_setAxisZero = new QPushButton(groupBox_3);
        pushButton_setAxisZero->setObjectName(QString::fromUtf8("pushButton_setAxisZero"));

        horizontalLayout_4->addWidget(pushButton_setAxisZero);

        pushButton_axisReturnHome = new QPushButton(groupBox_3);
        pushButton_axisReturnHome->setObjectName(QString::fromUtf8("pushButton_axisReturnHome"));

        horizontalLayout_4->addWidget(pushButton_axisReturnHome);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout_5->addWidget(groupBox_3, 0, 1, 2, 1);


        gridLayout_4->addWidget(motorWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_Motor, 1, 0, 1, 2);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1068, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        QWidget::setTabOrder(comboBox_relayCards, pushButton_openRelayCards);
        QWidget::setTabOrder(pushButton_openRelayCards, checkBox_axis0Switcher);
        QWidget::setTabOrder(checkBox_axis0Switcher, checkBox_axis1Switcher);
        QWidget::setTabOrder(checkBox_axis1Switcher, checkBox_laserSensorSwitcher);
        QWidget::setTabOrder(checkBox_laserSensorSwitcher, checkBox_airValveSwitcher);
        QWidget::setTabOrder(checkBox_airValveSwitcher, pushButton);
        QWidget::setTabOrder(pushButton, comboBox_axisID);
        QWidget::setTabOrder(comboBox_axisID, pushButton_initAxis);
        QWidget::setTabOrder(pushButton_initAxis, spinBox_PPU);
        QWidget::setTabOrder(spinBox_PPU, spinBox_PPUDenominator);
        QWidget::setTabOrder(spinBox_PPUDenominator, spinBox_acc);
        QWidget::setTabOrder(spinBox_acc, spinBox_dec);
        QWidget::setTabOrder(spinBox_dec, spinBox_runningVel);
        QWidget::setTabOrder(spinBox_runningVel, spinBox_initVel);
        QWidget::setTabOrder(spinBox_initVel, paramsSetButton);
        QWidget::setTabOrder(paramsSetButton, doubleSpinBox_runDis);
        QWidget::setTabOrder(doubleSpinBox_runDis, button_runDis);
        QWidget::setTabOrder(button_runDis, toolButton_RevXCmove);
        QWidget::setTabOrder(toolButton_RevXCmove, toolButton_RevXmove);
        QWidget::setTabOrder(toolButton_RevXmove, toolButton_stopMotor);
        QWidget::setTabOrder(toolButton_stopMotor, toolButton_Xmove);
        QWidget::setTabOrder(toolButton_Xmove, toolButton_XCmove);
        QWidget::setTabOrder(toolButton_XCmove, pushButton_setAxisZero);
        QWidget::setTabOrder(pushButton_setAxisZero, pushButton_axisReturnHome);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionOpen_Image);
        menuMenu->addAction(actionSave_Image);

        retranslateUi(MainWindowClass);
        QObject::connect(paramsSetButton, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::setAxisParams));
        QObject::connect(pushButton, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::checkCard));
        QObject::connect(pushButton_initAxis, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::initAxis));
        QObject::connect(button_runDis, &QToolButton::clicked, motorWidget, qOverload<>(&MotorPanel::axisRunDis));
        QObject::connect(pushButton_setAxisZero, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::setAxisZero));
        QObject::connect(pushButton_axisReturnHome, &QPushButton::clicked, motorWidget, qOverload<>(&MotorPanel::axisReturnCmdZero));
        QObject::connect(pushButton_openRelayCards, &QPushButton::clicked, relayWidget, qOverload<>(&RelayPanel::openCard));
        QObject::connect(checkBox_laserSensorSwitcher, SIGNAL(stateChanged(int)), relayWidget, SLOT(laserSensorSwitcher(int)));
        QObject::connect(checkBox_airValveSwitcher, SIGNAL(stateChanged(int)), relayWidget, SLOT(airValveSwitcher(int)));
        QObject::connect(comboBox_axisID, SIGNAL(currentIndexChanged(int)), motorWidget, SLOT(panelParamsUpdate(int)));
        QObject::connect(checkBox_axis0Switcher, SIGNAL(stateChanged(int)), relayWidget, SLOT(axis0Switcher(int)));
        QObject::connect(checkBox_axis1Switcher, SIGNAL(stateChanged(int)), relayWidget, SLOT(axis1Switcher(int)));
        QObject::connect(toolButton_stopMotor, &QToolButton::clicked, motorWidget, qOverload<>(&MotorPanel::axisStop));
        QObject::connect(toolButton_Xmove, &QToolButton::pressed, motorWidget, qOverload<>(&MotorPanel::axisRun));
        QObject::connect(toolButton_Xmove, &QToolButton::released, motorWidget, qOverload<>(&MotorPanel::axisStop));
        QObject::connect(toolButton_RevXmove, &QToolButton::pressed, motorWidget, qOverload<>(&MotorPanel::axisRunRev));
        QObject::connect(toolButton_RevXmove, &QToolButton::released, motorWidget, qOverload<>(&MotorPanel::axisStop));
        QObject::connect(toolButton_RevXCmove, &QToolButton::clicked, motorWidget, qOverload<>(&MotorPanel::axisRunRev));
        QObject::connect(toolButton_XCmove, &QToolButton::clicked, motorWidget, qOverload<>(&MotorPanel::axisRun));
        QObject::connect(pushButton_detectCam, &QPushButton::clicked, cameraPanel, qOverload<>(&CameraPanel::initCam));
        QObject::connect(pushButton_startGrab, &QPushButton::clicked, cameraPanel, qOverload<>(&CameraPanel::startGrab));
        QObject::connect(pushButton_stopGrab, &QPushButton::clicked, cameraPanel, qOverload<>(&CameraPanel::stopGrab));

        paramsSetButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MapContorlSys - \346\236\253\346\216\247", nullptr));
        actionOpen_Image->setText(QCoreApplication::translate("MainWindowClass", "Open Image...", nullptr));
        actionSave_Image->setText(QCoreApplication::translate("MainWindowClass", "Save Image", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindowClass", "\347\273\247\347\224\265\345\231\250\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindowClass", "\346\235\277\345\215\241\345\217\267\357\274\232", nullptr));
        comboBox_relayCards->setItemText(0, QCoreApplication::translate("MainWindowClass", "0", nullptr));
        comboBox_relayCards->setItemText(1, QCoreApplication::translate("MainWindowClass", "1", nullptr));
        comboBox_relayCards->setItemText(2, QCoreApplication::translate("MainWindowClass", "2", nullptr));
        comboBox_relayCards->setItemText(3, QCoreApplication::translate("MainWindowClass", "3", nullptr));
        comboBox_relayCards->setItemText(4, QCoreApplication::translate("MainWindowClass", "4", nullptr));

        pushButton_openRelayCards->setText(QCoreApplication::translate("MainWindowClass", "\346\211\223\345\274\200\346\235\277\345\215\241", nullptr));
        checkBox_axis0Switcher->setText(QCoreApplication::translate("MainWindowClass", "\347\224\265\346\234\272\350\275\2640", nullptr));
        checkBox_axis1Switcher->setText(QCoreApplication::translate("MainWindowClass", "\347\224\265\346\234\272\350\275\2641", nullptr));
        checkBox_laserSensorSwitcher->setText(QCoreApplication::translate("MainWindowClass", "\346\277\200\345\205\211\344\274\240\346\204\237\345\231\250", nullptr));
        checkBox_airValveSwitcher->setText(QCoreApplication::translate("MainWindowClass", "\346\260\224\351\230\200", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindowClass", "\346\277\200\345\205\211\344\274\240\346\204\237\345\231\250\351\235\242\346\235\277", nullptr));
        label_laserSensorDis->setText(QCoreApplication::translate("MainWindowClass", "0", nullptr));
        label_laserSensorVoltage->setText(QCoreApplication::translate("MainWindowClass", "0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindowClass", "\347\224\265\345\216\213\345\200\274 (V)\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindowClass", "\350\267\235\347\246\273 (\316\274m)\357\274\232", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindowClass", "\346\221\204\345\203\217\346\234\272\351\235\242\346\235\277", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindowClass", "\350\256\276\345\244\207SN\357\274\232", nullptr));
        label_camSN->setText(QCoreApplication::translate("MainWindowClass", "\346\234\252\346\243\200\346\265\213", nullptr));
        pushButton_detectCam->setText(QCoreApplication::translate("MainWindowClass", "\346\243\200\346\265\213", nullptr));
        pushButton_startGrab->setText(QCoreApplication::translate("MainWindowClass", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pushButton_stopGrab->setText(QCoreApplication::translate("MainWindowClass", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        label_cameraImage->setText(QCoreApplication::translate("MainWindowClass", "Image", nullptr));
        groupBox_Motor->setTitle(QCoreApplication::translate("MainWindowClass", "\347\224\265\346\234\272\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindowClass", "\350\275\264\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindowClass", "\347\273\235\345\257\271\344\275\215\347\275\256\357\274\232", nullptr));
        label_realPos->setText(QCoreApplication::translate("MainWindowClass", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindowClass", "\345\221\275\344\273\244\344\275\215\347\275\256\357\274\232", nullptr));
        label_cmdPos->setText(QCoreApplication::translate("MainWindowClass", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindowClass", "\350\277\220\350\241\214\347\212\266\346\200\201\357\274\232", nullptr));
        label_status->setText(QCoreApplication::translate("MainWindowClass", "Not opened", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindowClass", "\350\275\264\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindowClass", "PPU", nullptr));
        paramsSetButton->setText(QCoreApplication::translate("MainWindowClass", "\350\256\276\347\275\256\345\217\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowClass", "PPU Denominator", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowClass", "\345\210\235\351\200\237\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowClass", "\350\277\220\350\241\214\351\200\237\345\272\246", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindowClass", "\345\207\217\351\200\237\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindowClass", "\345\212\240\351\200\237\345\272\246", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindowClass", "\350\275\264\345\210\235\345\247\213\345\214\226", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindowClass", "\346\235\277\345\215\241ID\357\274\232", nullptr));
        label_cardID->setText(QCoreApplication::translate("MainWindowClass", "\346\234\252\346\243\200\346\265\213", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowClass", "\346\243\200\346\265\213", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowClass", "\350\275\264\357\274\232", nullptr));
        comboBox_axisID->setItemText(0, QCoreApplication::translate("MainWindowClass", "0", nullptr));
        comboBox_axisID->setItemText(1, QCoreApplication::translate("MainWindowClass", "1", nullptr));
        comboBox_axisID->setItemText(2, QCoreApplication::translate("MainWindowClass", "2", nullptr));
        comboBox_axisID->setItemText(3, QCoreApplication::translate("MainWindowClass", "3", nullptr));
        comboBox_axisID->setItemText(4, QCoreApplication::translate("MainWindowClass", "4", nullptr));
        comboBox_axisID->setItemText(5, QCoreApplication::translate("MainWindowClass", "5", nullptr));

        pushButton_initAxis->setText(QCoreApplication::translate("MainWindowClass", "\345\210\235\345\247\213\345\214\226\350\275\264", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindowClass", "\346\223\215\344\275\234\351\235\242\346\235\277", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindowClass", "\350\277\220\350\241\214\350\267\235\347\246\273 (PPU)", nullptr));
        button_runDis->setText(QCoreApplication::translate("MainWindowClass", "GO", nullptr));
        toolButton_RevXCmove->setText(QCoreApplication::translate("MainWindowClass", "<<", nullptr));
        toolButton_RevXmove->setText(QCoreApplication::translate("MainWindowClass", "<", nullptr));
        toolButton_stopMotor->setText(QCoreApplication::translate("MainWindowClass", "STOP", nullptr));
        toolButton_Xmove->setText(QCoreApplication::translate("MainWindowClass", ">", nullptr));
        toolButton_XCmove->setText(QCoreApplication::translate("MainWindowClass", ">>", nullptr));
        pushButton_setAxisZero->setText(QCoreApplication::translate("MainWindowClass", "\350\256\276\347\275\256\351\233\266\344\275\215", nullptr));
        pushButton_axisReturnHome->setText(QCoreApplication::translate("MainWindowClass", "\350\277\224\345\233\236\351\233\266\344\275\215", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindowClass", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
