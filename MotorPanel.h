#pragma once

#include <Windows.h>
#include <qwidget.h>
#include <functional>
#include "Axis.h"
#include "AdvMotApi.h"
#include "AdvMotDrv.h"
#include "UpdateMotorPanelUI.h"
#include "FAIORelay.h"

class MotorPanel : public QWidget {
	Q_OBJECT

public:
	MotorPanel(QWidget* parent);
	~MotorPanel();

	DWORD deviceNum = 0;
	HAND deviceHand = 0;

	short axisID = 0;
	Axis axis[8];

	UpdateMotorPanelUI* updateUIThread;

public:
	Q_INVOKABLE void updateAxisCmdPos();
	Q_INVOKABLE void updateStatus();

public slots:
	void checkCard();

	void initAxis();
	void setAxisParams();
	void setAxisZero();

	void axisRunDis();
	void axisRun();
	void axisRunRev();
	void axisReturnCmdZero();
	void axisStop();

	void panelParamsUpdate(int axisID);
};

