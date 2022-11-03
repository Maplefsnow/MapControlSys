#include "UpdateUI.h"
#include "MotorPanel.h"
#include "Axis.h"

void UpdateUI::run() {
	
	//QMetaObject::invokeMethod();
	
	while (1) {
		QString motorStatus, motorCmdPos;



		emit updateCmdPos(motorCmdPos);
		emit updateStatus(motorStatus);

		qDebug() << "qwq!";
		QThread::sleep(1);  // msleep
	}
}
