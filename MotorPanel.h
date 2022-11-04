#pragma once

#include <Windows.h>
#include <qwidget.h>
#include <functional>
#include "Axis.h"
#include "AdvMotApi.h"
#include "AdvMotDrv.h"
#include "UpdateMotorPanelUI.h"
#include "FAIORelay.h"

#define RELAY_MOTOR_PORT 2

class MotorPanel : public QWidget {
	Q_OBJECT

public:
	MotorPanel(QWidget* parent);
	~MotorPanel();

	DWORD deviceNum = 0;
	HAND deviceHand = 0;

	short axisID = 0;
	Axis axis;

	UpdateMotorPanelUI* updateUIThread;
	FAIORelay* relay;

public:
	Q_INVOKABLE void updateAxisCmdPos();
	Q_INVOKABLE void updateStatus();

public slots:
	void checkCard();

	void initAxis();
	void setAxisParams();

	void axisRunDis();
	void axisRun();
	void axisRunRev();
	void axisReturnCmdZero();
	void axisStop();

	void setAxisZero();
};

