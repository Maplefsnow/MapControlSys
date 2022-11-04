#pragma once

#include <qthread.h>
#include <qdebug.h>
#include <qwidget.h>

class UpdateUI : public QThread {
	Q_OBJECT
public:
	UpdateUI(QWidget *);
	QWidget* panel;
	void stop();

private:
	bool is_runnable = true;

protected:
	void run();
};

