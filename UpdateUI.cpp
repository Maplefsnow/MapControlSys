#include "UpdateUI.h"
#include "MotorPanel.h"
#include "Axis.h"

UpdateUI::UpdateUI(QWidget* panel) {
	this->panel = panel;
}

void UpdateUI::run() {
	while (1) {
		QMetaObject::invokeMethod(this->panel, "updateAxisCmdPos", Qt::DirectConnection);
		QThread::sleep(1);
	}
}
