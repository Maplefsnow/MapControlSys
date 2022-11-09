#pragma once

#include <qwidget.h>
#include "LaserSensor.h"
#include "UpdateLaserSensorPanelUI.h"

class LaserSensorPanel : public QWidget {
	Q_OBJECT

public:
	LaserSensorPanel(QWidget* parent);
	~LaserSensorPanel();
	
	LaserSensor* sensor;
	UpdateLaserSensorPanelUI* updateUIThread;

public:
	Q_INVOKABLE void updateUI();
};

