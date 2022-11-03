#include "MotorPanel.h"
#include "MainWindow.h"

MotorPanel::MotorPanel(QWidget* widget) : QWidget(widget) {
	
}

MotorPanel::~MotorPanel() {
	if(this->deviceHand == 0) return;

	Acm_DevClose(&this->deviceHand);
}

void MotorPanel::checkCard() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	DEVLIST devList[5]; ULONG devNum;
	Acm_GetAvailableDevs(devList, 2, &devNum);
	DWORD deviceNum = devList[0].dwDeviceNum;
	this->deviceNum = deviceNum;

	char deviceNumStr[10];
	sprintf(deviceNumStr, "0x%x", deviceNum);

	mainWindow->ui.label_cardID->setText(QString::fromStdString(deviceNumStr));
}

void MotorPanel::initAxis() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceNum == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}

	Acm_DevOpen(this->deviceNum, &this->deviceHand);

	USHORT axisID = mainWindow->ui.comboBox_axisID->currentIndex();
	try {
		this->axis = Axis::Axis(this->deviceHand, axisID);
	}
	catch (const char *msg) {
		mainWindow->ui.statusBar->showMessage(msg, 2000);
	}
	
	char successMsg[100];
	sprintf(successMsg, "Axis %d init success!", axisID);
	mainWindow->ui.statusBar->showMessage(successMsg, 2000);
}

void MotorPanel::setMotorParams() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}

	this->axis.setPPU(mainWindow->ui.spinBox_PPU->value(), mainWindow->ui.spinBox_PPUDenominator->value());
	this->axis.setVelParams(mainWindow->ui.spinBox_initVel->value(),
							mainWindow->ui.spinBox_runningVel->value(),
							mainWindow->ui.spinBox_acc->value(),
							mainWindow->ui.spinBox_dec->value());

	mainWindow->ui.statusBar->showMessage("Params set success!", 2000);
}


