#include "UpdateUI.h"

UpdateUI::UpdateUI(QWidget* panel) {
	this->panel = panel;
}

void UpdateUI::run() {
	while (this->is_runnable) {
		QMetaObject::invokeMethod(this->panel, "updateAxisCmdPos", Qt::AutoConnection);
		QMetaObject::invokeMethod(this->panel, "updateStatus", Qt::AutoConnection);
		QThread::msleep(1);
	}
}

void UpdateUI::stop() {
	this->is_runnable = false;
}
