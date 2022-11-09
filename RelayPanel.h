#pragma once

#include <qwidget.h>
#include "FAIORelay.h"

#define AIRVALVE_PORT 1
#define AXIS_0_PORT 3
#define AXIS_1_PORT 4
#define LASERSENSOR_PORT 2

class RelayPanel : public QWidget {
	Q_OBJECT

public:
	RelayPanel(QWidget* parent);
	~RelayPanel();

private:
	FAIORelay relay;
	short cardNum = 0;

public slots:
	void openCard();
	void airValveSwitcher(int status);
	void axis0Switcher(int status);
	void axis1Switcher(int status);
	void laserSensorSwitcher(int status);
};

