#pragma once

#include <Windows.h>
#include <qwidget.h>
#include <functional>
#include "Axis.h"
#include "AdvMotApi.h"
#include "AdvMotDrv.h"

class MotorPanel : public QWidget {
	Q_OBJECT

public:
	MotorPanel(QWidget* parent);
	~MotorPanel();

	DWORD deviceNum = 0;
	HAND deviceHand = 0;
	HAND axisHand = 0;
	Axis axis = Axis::Axis(HAND(0), USHORT(0));

public slots:
	void initAxis();
	void setMotorParams();
	void checkCard();
};

