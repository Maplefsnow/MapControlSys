#include "RelayPanel.h"
#include "MainWindow.h"
#include "qdebug.h"

RelayPanel::RelayPanel(QWidget* parent)
{
}

RelayPanel::~RelayPanel() {
	this->relay.closeCard();
}

void RelayPanel::openCard() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	int cardID = mainWindow->ui.comboBox_relayCards->currentIndex();
	try {
		this->relay.openCard(cardID);
		mainWindow->ui.checkBox_airValveSwitcher->setEnabled(true);
		mainWindow->ui.checkBox_axis0Switcher->setEnabled(true);
		mainWindow->ui.checkBox_laserSensorSwitcher->setEnabled(true);
	}
	catch (const QString errMsg) {
		mainWindow->ui.statusBar->showMessage(errMsg, 2000);
		mainWindow->ui.checkBox_airValveSwitcher->setEnabled(false);
		mainWindow->ui.checkBox_axis0Switcher->setEnabled(false);
		mainWindow->ui.checkBox_laserSensorSwitcher->setEnabled(false);
		return;
	}

	char str[20]; sprintf(str, "Open card %d success.", cardID);
	mainWindow->ui.statusBar->showMessage(str, 2000);
}

void RelayPanel::airValveSwitcher(int status) {
	if (status == 2) {
		this->relay.onPort(AIRVALVE_PORT);
	}
	else {
		this->relay.offPort(AIRVALVE_PORT);
	}
}

void RelayPanel::motorSwitcher(int status) {
	if (status == 2) {
		this->relay.onPort(AXIS_0_PORT);
	}
	else {
		this->relay.offPort(AXIS_0_PORT);
	}
}

void RelayPanel::laserSensorSwitcher(int status) {
	if (status == 2) {
		this->relay.onPort(LASERSENSOR_PORT);
	}
	else {
		this->relay.offPort(LASERSENSOR_PORT);
	}
}
