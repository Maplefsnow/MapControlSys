#pragma once

#include <qthread.h>
#include <qdebug.h>

class UpdateUI : public QThread {
	Q_OBJECT
public:
	UpdateUI() {}
protected:
	void run();
signals:
	void updateCmdPos(QString);
	void updateStatus(QString);
};

