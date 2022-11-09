#include "MotorPanel.h"
#include "MainWindow.h"
#include "FAIORelay.h"

MotorPanel::MotorPanel(QWidget* widget) : QWidget(widget) {
	this->updateUIThread = new UpdateMotorPanelUI(this);
	this->updateUIThread->start();
}

MotorPanel::~MotorPanel() {
	this->updateUIThread->stop();
	this->updateUIThread->wait();
	this->updateUIThread = nullptr;
}

Q_INVOKABLE void MotorPanel::updateAxisCmdPos() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if(mainWindow == nullptr) return;

	try {
		DOUBLE pos = this->axis[this->axisID].getCmdPos();
		mainWindow->ui.label_cmdPos->setText(QString::number(pos, 'f', 4));
	}
	catch (const char* errMsg) {
		mainWindow->ui.label_cmdPos->setText(errMsg);
		return;
	}
}

Q_INVOKABLE void MotorPanel::updateStatus() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (mainWindow == nullptr) return;

	U16 status = 0;

	try {
		status = this->axis[this->axisID].getAxisStatus();
	}
	catch (const char* errMsg) {
		mainWindow->ui.label_status->setText(errMsg);
		return;
	}

	QString statusStr = "";

	switch (status) {
		case 0: statusStr = "Disabled"; break;
		case 1: statusStr = "Ready"; break;
		case 2: statusStr = "Stopping..."; break;
		case 3: statusStr = "ERROR! Stopping..."; break;
		case 4: case 5: case 6: case 7: statusStr = "Running..."; break;
		default: break;
	}

	mainWindow->ui.label_status->setText(statusStr);
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
		this->axis[axisID] = Axis::Axis(this->deviceHand, axisID);
		this->axisID = axisID;
	}
	catch (const char *msg) {
		mainWindow->ui.statusBar->showMessage(msg, 2000);
		return;
	}
	
	char successMsg[100];
	sprintf(successMsg, "Axis %d init success!", axisID);
	mainWindow->ui.statusBar->showMessage(successMsg, 2000);
}

void MotorPanel::setAxisParams() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis[this->axisID].hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis[this->axisID].setPPU(mainWindow->ui.spinBox_PPU->value(), mainWindow->ui.spinBox_PPUDenominator->value());


		this->axis[this->axisID].setVelParams(mainWindow->ui.spinBox_initVel->value(),
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

void MotorPanel::setAxisZero() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis[this->axisID].hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis[this->axisID].setCmdPos(0.0);
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::axisRunDis() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if(this->axis[this->axisID].hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis[this->axisID].relMove(mainWindow->ui.doubleSpinBox_runDis->value());
	}
	catch (const char *errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::axisRun() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis[this->axisID].hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis[this->axisID].contiMove(0);
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::axisRunRev() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis[this->axisID].hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis[this->axisID].contiMove(1);
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::axisReturnCmdZero() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis[this->axisID].hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis[this->axisID].returnCmdZero();
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::axisStop() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (this->deviceHand == 0) {
		mainWindow->ui.statusBar->showMessage("No device card detected, please retry!", 2000);
		return;
	}
	if (this->axis[this->axisID].hand == 0) {
		mainWindow->ui.statusBar->showMessage("No axis selected, please select an axis!", 2000);
		return;
	}

	try {
		this->axis[this->axisID].stop();
	}
	catch (const char* errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
	}
}

void MotorPanel::panelParamsUpdate(int axisID) {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	this->axisID = axisID;

	mainWindow->ui.spinBox_PPU->setValue(this->axis[axisID].PPU);
	mainWindow->ui.spinBox_PPUDenominator->setValue(this->axis[axisID].PPUDenominator);
	mainWindow->ui.spinBox_acc->setValue(this->axis[axisID].acc);
	mainWindow->ui.spinBox_dec->setValue(this->axis[axisID].dec);
	mainWindow->ui.spinBox_initVel->setValue(this->axis[axisID].initVel);
	mainWindow->ui.spinBox_runningVel->setValue(this->axis[axisID].runningVel);
}
