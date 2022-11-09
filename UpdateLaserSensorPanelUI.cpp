#include "UpdateLaserSensorPanelUI.h"

UpdateLaserSensorPanelUI::UpdateLaserSensorPanelUI(QWidget* panel) {
	this->panel = panel;
}

void UpdateLaserSensorPanelUI::run() {
	while (this->is_runnable) {
		QMetaObject::invokeMethod(this->panel, "updateUI", Qt::AutoConnection);
		QThread::msleep(1);
	}
}

void UpdateLaserSensorPanelUI::stop() {
	this->is_runnable = false;
}