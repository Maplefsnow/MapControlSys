#pragma once

#include <qthread.h>
#include <qdebug.h>
#include <qwidget.h>

class UpdateMotorPanelUI : public QThread {
	Q_OBJECT
public:
	UpdateMotorPanelUI(QWidget *);
	QWidget* panel;
	void stop();

private:
	bool is_runnable = true;

protected:
	void run();
};

