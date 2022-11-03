#include "MotorPanel.h"
#include "MainWindow.h"
#include "UpdateUI.h"

MotorPanel::MotorPanel(QWidget* widget) : QWidget(widget) {
	
}

MotorPanel::~MotorPanel() {
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

	UpdateUI *thread = new UpdateUI(); thread->start();
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
		return;
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
	if (this->axis.hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis.setPPU(mainWindow->ui.spinBox_PPU->value(), mainWindow->ui.spinBox_PPUDenominator->value());


		this->axis.setVelParams(mainWindow->ui.spinBox_initVel->value(),
			mainWindow->ui.spinBox_runningVel->value(),
			mainWindow->ui.spinBox_acc->value(),
			mainWindow->ui.spinBox_dec->value());
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
		return;
	}
	
	mainWindow->ui.statusBar->showMessage("Params set success!", 2000);
}

void MotorPanel::motorRunDis() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if(this->axis.hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis.relMove(mainWindow->ui.spinBox_runDis->value());
	}
	catch (const char *errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::motorRun() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis.hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis.contiMove(0);
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::motorRunRev() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis.hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis.contiMove(1);
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::motorStop() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis.hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis.stop();
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::handleUpdateCmdPos(QString str) {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	mainWindow->ui.label_cmdPos->setText(str);
}


