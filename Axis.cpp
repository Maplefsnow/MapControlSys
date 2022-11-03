#include "Axis.h"
#include <qdebug.h>

Axis::Axis(HAND devHand, USHORT num) {
	if(devHand == 0) return;

	ULONG ret = 0;

	ret = Acm_AxOpen(devHand, num, &hand);
	if(ret != 0) throw "Open device FAILED!";
	ret = Acm_SetU32Property(hand, CFG_AxPulseOutMode, 2);
	if(ret != 0) throw "Set Pulse_Out_Mode FAILED!";

	this->axisID = num;
}

Axis::~Axis() {
	if(hand == 0) return;
	Acm_AxClose(&hand);
}

void Axis::relMove(DOUBLE distance) {
	Acm_AxMoveRel(hand, distance);
}

void Axis::setVelParams(DOUBLE i_initVel, DOUBLE i_runningVel, DOUBLE i_acc, DOUBLE i_dec, DOUBLE mode) {
	Acm_SetF64Property(hand, PAR_AxVelLow, i_initVel);
	Acm_SetF64Property(hand, PAR_AxVelHigh, i_runningVel);
	Acm_SetF64Property(hand, PAR_AxAcc, i_acc);
	Acm_SetF64Property(hand, PAR_AxDec, i_dec);
	Acm_SetF64Property(hand, PAR_AxJerk, mode);

	initVel = i_initVel;
	runningVel = i_runningVel;
	acc = i_acc;
	dec = i_dec;
	velMode = mode;
}

void Axis::setPPU(ULONG i_PPU) {
	Acm_SetU32Property(hand, CFG_AxPPU, i_PPU);
	Acm_SetU32Property(hand, CFG_AxPPUDenominator, 1);
	PPU = i_PPU;
	PPUDenominator = 1;
}

void Axis::setPPU(ULONG i_PPU, ULONG denominator) {
	Acm_SetU32Property(hand, CFG_AxPPU, i_PPU);
	Acm_SetU32Property(hand, CFG_AxPPUDenominator, denominator);
	PPU = i_PPU;
	PPUDenominator = denominator;
}

double Axis::getPPU() {
	return PPU / PPUDenominator;
}
