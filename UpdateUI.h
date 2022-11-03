#pragma once

#include <qthread.h>
#include <qdebug.h>
#include <qwidget.h>
#include "MotorPanel.h"

class UpdateUI : public QThread {
	Q_OBJECT
public:
	UpdateUI(QWidget *);
	QWidget* panel;
protected:
	void run();
};

