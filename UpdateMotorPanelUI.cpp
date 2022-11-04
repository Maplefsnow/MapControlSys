#include "UpdateMotorPanelUI.h"

UpdateMotorPanelUI::UpdateMotorPanelUI(QWidget* panel) {
	this->panel = panel;
}

void UpdateMotorPanelUI::run() {
	while (this->is_runnable) {
		QMetaObject::invokeMethod(this->panel, "updateAxisCmdPos", Qt::AutoConnection);
		QMetaObject::invokeMethod(this->panel, "updateStatus", Qt::AutoConnection);
		QThread::msleep(1);
	}
}

void UpdateMotorPanelUI::stop() {
	this->is_runnable = false;
}
