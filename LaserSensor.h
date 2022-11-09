#pragma once

#include <stdio.h>
#include <NIDAQmx.h>

#pragma comment(lib,"NIDAQmx.lib")

class LaserSensor {
public:
	LaserSensor(short aiCom, int32 aquisitionMode);
	~LaserSensor();
	
	void sensorInit();
	float64 getVoltage();
	float64 getDis();

private:
	TaskHandle taskHandler;
	short com = -1;

};

