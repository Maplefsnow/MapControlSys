#include "LaserSensorPanel.h"
#include "MainWindow.h"
#include "qdebug.h"

LaserSensorPanel::LaserSensorPanel(QWidget* widget) : QWidget(widget) {
	this->relay = new FAIORelay(1);
}

LaserSensorPanel::~LaserSensorPanel() {
	this->relay->closeCard();
}

Q_INVOKABLE void LaserSensorPanel::updateUI() {
	
}

void LaserSensorPanel::sensorSwitch(int switchStatus) {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if (switchStatus == 0) {
		this->relay->offPort(RELAY_LASERSENSOR_PORT);
	}
	else {
		this->relay->onPort(RELAY_LASERSENSOR_PORT);
	}
}
