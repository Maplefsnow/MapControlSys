#pragma once

#include <qwidget.h>
#include "FAIORelay.h"

#define RELAY_LASERSENSOR_PORT 2

class LaserSensorPanel : public QWidget {
	Q_OBJECT

public:
	LaserSensorPanel(QWidget* parent);
	~LaserSensorPanel();
	

public:
	Q_INVOKABLE void updateUI();

private:
	FAIORelay* relay;

public slots:
	void sensorSwitch(int);
};

