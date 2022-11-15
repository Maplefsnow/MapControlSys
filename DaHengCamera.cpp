#include "DaHengCamera.h"

DaHengCamera::DaHengCamera(gxstring camSN) {
    device = IGXFactory::GetInstance().OpenDeviceBySN(camSN, GX_ACCESS_EXCLUSIVE);
    camFeatures = device->GetRemoteFeatureControl();
    camStream = device->OpenStream(0);
}

DaHengCamera::~DaHengCamera() {
}

void DaHengCamera::initDeviceParams() {
	//camFeatures->GetIntFeature("DecimationHorizontal")->SetValue(2);
	//camFeatures->GetIntFeature("DecimationVertical")->SetValue(2);
	camFeatures->GetEnumFeature("GainSelector")->SetValue("All");
	camFeatures->GetFloatFeature("Gain")->SetValue(10.0000);
	camFeatures->GetFloatFeature("ExposureTime")->SetValue(10000.00);
	camFeatures->GetFloatFeature("AutoExposureTimeMax")->SetValue(200000.00);
	camFeatures->GetEnumFeature("GainAuto")->SetValue("Continuous");
	camFeatures->GetEnumFeature("ExposureAuto")->SetValue("Continuous");
	camFeatures->GetEnumFeature("BalanceWhiteAuto")->SetValue("Continuous");
}

void DaHengCamera::startGrab() {
	this->camStream->StartGrab();
	this->camFeatures->GetCommandFeature("AcquisitionStart")->Execute();
}

void DaHengCamera::stopGrab() {
	this->camFeatures->GetCommandFeature("AcquisitionStop")->Execute();
	this->camStream->StopGrab();
}

CImageDataPointer DaHengCamera::getImage(uint32_t time = 200) {
	return this->camStream->GetImage(time);
}

CGXDevicePointer DaHengCamera::getDevice() {
    return this->device;
}

CGXFeatureControlPointer DaHengCamera::getCamFeatures() {
    return this->camFeatures;
}

CGXStreamPointer DaHengCamera::getCamStream() {
    return this->camStream;
}
