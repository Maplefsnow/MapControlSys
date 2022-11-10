#pragma once

#include <qwidget.h>
#include <GalaxyIncludes.h>
#include <opencv2/opencv.hpp>
#include "DaHengCamera.h"

class CameraPanel : public QWidget, public ICaptureEventHandler {
	Q_OBJECT

private:
	DaHengCamera camera;
	QImage image;

public:
	CameraPanel(QWidget* parent);
	~CameraPanel();

public:
	void DoOnImageCaptured(CImageDataPointer& imageData, void* pUserParam);
	Q_INVOKABLE void updateImage();

public slots:
	void initCam();
	void startGrab();
	void stopGrab();
};

