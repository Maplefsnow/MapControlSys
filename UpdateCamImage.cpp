#include "UpdateCamImage.h"

UpdateCamImage::UpdateCamImage(QWidget* panel) {
	this->panel = panel;
}

void UpdateCamImage::run() {
	
}

void UpdateCamImage::stop() {
	this->is_runnable = false;
}

void UpdateCamImage::DoOnImageCaptured(CImageDataPointer& imageData, void* pUserParam) {
	
}
