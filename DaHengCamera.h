#pragma once

#include <opencv2/core.hpp>
#include <GalaxyIncludes.h>

class DaHengCamera {
private:
	CGXDevicePointer device;
	CGXFeatureControlPointer camFeatures;
	CGXStreamPointer camStream;

public:
	DaHengCamera(){};
	DaHengCamera(gxstring camSN);
	~DaHengCamera();

	void initDeviceParams();
	void startGrab();
	void stopGrab();

	CImageDataPointer getImage(uint32_t time);

	CGXDevicePointer getDevice();
	CGXFeatureControlPointer getCamFeatures();
	CGXStreamPointer getCamStream();
};

