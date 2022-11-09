#pragma once

#include <qthread.h>
#include <qwidget.h>

class UpdateLaserSensorPanelUI : public QThread{
	Q_OBJECT
public:
	UpdateLaserSensorPanelUI(QWidget*);
	QWidget* panel;
	void stop();

private:
	bool is_runnable = true;

protected:
	void run();
};

