#include "LaserSensorPanel.h"
#include "MainWindow.h"
#include "qdebug.h"

LaserSensorPanel::LaserSensorPanel(QWidget* widget) : QWidget(widget) {
	this->sensor = new LaserSensor(0, DAQmx_Val_RSE);
	this->sensor->sensorInit();

	this->updateUIThread = new UpdateLaserSensorPanelUI(this);
	this->updateUIThread->start();
}

LaserSensorPanel::~LaserSensorPanel() {
	this->updateUIThread->stop();
	this->updateUIThread->wait();
	this->updateUIThread = nullptr;
}

Q_INVOKABLE void LaserSensorPanel::updateUI() {
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

	if(mainWindow == nullptr) return;

	mainWindow->ui.label_laserSensorVoltage->setText(QString::number(this->sensor->getVoltage()));
	mainWindow->ui.label_laserSensorDis->setText(QString::number(this->sensor->getDis()));
}
