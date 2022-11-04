#include "Axis.h"
#include <qdebug.h>

#define throwError(x) \
	{\
		ret = x;\
		if (ret != 0) {\
			char errorMsg[100];\
			Acm_GetErrorMessage(ret, errorMsg, 100);\
			ret = 0;\
			throw errorMsg;\
		}\
	}

ULONG ret = 0;

Axis::Axis(HAND devHand, USHORT num) {
	if(devHand == 0) return;

	throwError(Acm_AxOpen(devHand, num, &this->hand));
	throwError(Acm_SetU32Property(this->hand, CFG_AxPulseOutMode, 2));
	throwError(Acm_AxSetCmdPosition(this->hand, 0.0));
	throwError(Acm_AxSetActualPosition(this->hand, 0.0));

	this->axisID = num;
}

Axis::Axis() {
	this->hand = 0;
}

Axis::~Axis() {
}

void Axis::relMove(DOUBLE distance) {
	throwError(Acm_AxMoveRel(this->hand, distance));
}

void Axis::contiMove(USHORT dir) {
	throwError(Acm_AxMoveVel(this->hand, dir));
}

void Axis::returnCmdZero() {
	throwError(Acm_AxMoveAbs(this->hand, 0.0));
}

void Axis::stop() {
	throwError(Acm_AxStopDec(this->hand));
}

void Axis::setVelParams(DOUBLE i_initVel, DOUBLE i_runningVel, DOUBLE i_acc, DOUBLE i_dec, DOUBLE mode) {	
	throwError(Acm_SetF64Property(hand, PAR_AxVelLow, i_initVel));
	throwError(Acm_SetF64Property(hand, PAR_AxVelHigh, i_runningVel));
	throwError(Acm_SetF64Property(hand, PAR_AxAcc, i_acc));
	throwError(Acm_SetF64Property(hand, PAR_AxDec, i_dec));
	throwError(Acm_SetF64Property(hand, PAR_AxJerk, mode));

	this->initVel = i_initVel;
	this->runningVel = i_runningVel;
	this->acc = i_acc;
	this->dec = i_dec;
	this->velMode = mode;
}

void Axis::setPPU(ULONG i_PPU) {
	throwError(Acm_SetU32Property(this->hand, CFG_AxPPU, i_PPU));
	throwError(Acm_SetU32Property(this->hand, CFG_AxPPUDenominator, 1));
	this->PPU = i_PPU;
	this->PPUDenominator = 1;
}

void Axis::setPPU(ULONG i_PPU, ULONG denominator) {
	throwError(Acm_SetU32Property(this->hand, CFG_AxPPU, i_PPU));
	throwError(Acm_SetU32Property(this->hand, CFG_AxPPUDenominator, denominator));
	this->PPU = i_PPU;
	this->PPUDenominator = denominator;
}

void Axis::setCmdPos(DOUBLE pos) {
	throwError(Acm_AxSetCmdPosition(this->hand, pos));
	this->cmdPos = pos;
}

DOUBLE Axis::getPPU() {
	return PPU / PPUDenominator;
}

DOUBLE Axis::getCmdPos() {
	if(this->hand == 0) return 0.0;

	DOUBLE pos = 0.0;
	throwError(Acm_AxGetCmdPosition(this->hand, &pos));
	return pos;
}

U16 Axis::getAxisStatus() {
	if (this->hand == 0) return 0;

	U16 status = 0;
	throwError(Acm_AxGetState(this->hand, &status));
	return status;
}
