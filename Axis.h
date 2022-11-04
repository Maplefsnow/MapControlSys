#pragma once

#include <Windows.h>
#include "AdvMotApi.h"
#include "AdvMotDrv.h"
#include "AdvMotPropID.h"

class Axis {
public:
	Axis(HAND devHand, USHORT num);
	Axis();
	~Axis();

	void relMove(DOUBLE distance);
	void contiMove(USHORT dir);
	void returnCmdZero();
	void stop();

	void setVelParams(DOUBLE i_initVel, DOUBLE i_runningVel, DOUBLE i_acc, DOUBLE i_dec, DOUBLE mode = 0.0);
	void setPPU(ULONG i_PPU, ULONG denominator);
	void setPPU(ULONG i_PPU);
	void setCmdPos(DOUBLE);

	DOUBLE getPPU();
	DOUBLE getCmdPos();
	U16 getAxisStatus();
	
public:
	HAND hand = 0;
	USHORT axisID = 0;
	ULONG PPU = 1, PPUDenominator = 1;
	DOUBLE initVel = 0, runningVel = 0, acc = 0, dec = 0, velMode = 0;
	DOUBLE cmdPos = 0.0;
};

