#include "LaserSensor.h"

float64 data[110];

int32 CVICALLBACK EveryNCallback(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void* callbackData);

LaserSensor::LaserSensor(short aiCom, int32 aquisitionMode) {
	char taskStr[20], channelStr[20];
	sprintf(taskStr, "Laser_%d", aiCom);
	sprintf(channelStr, "Dev1/ai%d", aiCom);

	DAQmxCreateTask(taskStr, &this->taskHandler);
	DAQmxCreateAIVoltageChan(this->taskHandler, channelStr, "", DAQmx_Val_Cfg_Default, -10.0, 10.0, DAQmx_Val_Volts, NULL);
	DAQmxCfgSampClkTiming(this->taskHandler, NULL, 10000.0, DAQmx_Val_Rising, DAQmx_Val_ContSamps, 1000);
	DAQmxSetAITermCfg(this->taskHandler, "", aquisitionMode);

	this->com = aiCom;
}

LaserSensor::~LaserSensor() {
}

float64 LaserSensor::getVoltage() {
	float64 res = 0;

	for (int i = 0; i < 100; i++) {
		res += data[i];
	}

	return res / 100.0;
}

float64 LaserSensor::getDis() {
	float64 mid = 2.5;  // flexible
	return (this->getVoltage() - mid) * 2000;
}

void LaserSensor::sensorInit() {
	DAQmxRegisterEveryNSamplesEvent(this->taskHandler, DAQmx_Val_Acquired_Into_Buffer, 100, 0, EveryNCallback, NULL);
	DAQmxStartTask(this->taskHandler);
}

int32 CVICALLBACK EveryNCallback(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void* callbackData) {
	int32 read = 0;

	DAQmxReadAnalogF64(taskHandle, 100, 10.0, DAQmx_Val_GroupByScanNumber, data, 100, &read, NULL);

	return 0;
}
