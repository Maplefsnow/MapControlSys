#pragma once

#include <qthread.h>
#include <qwidget.h>
#include <GalaxyIncludes.h>
#include <opencv2/core.hpp>

class UpdateCamImage : public QThread, public ICaptureEventHandler {
	Q_OBJECT
public:
	UpdateCamImage(QWidget*);
	QWidget* panel;
	void stop();
	void DoOnImageCaptured(CImageDataPointer& imageData, void* pUserParam);

private:
	bool is_runnable = true;
	QImage image;

protected:
	void run();
};

