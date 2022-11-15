#include "UpdateCamImage.h"

UpdateCamImage::UpdateCamImage(QWidget* panel) {
	this->panel = panel;
}

void UpdateCamImage::run() {
    while (this->is_runnable) {
        
    }
}

void UpdateCamImage::stop() {
	this->is_runnable = false;
}

void UpdateCamImage::DoOnImageCaptured(CImageDataPointer& imageData, void* pUserParam) {
    cv::Mat matImage;

    int imageHeight = imageData->GetHeight();
    int imageWidth = imageData->GetWidth();

    if (imageData->GetStatus() == GX_FRAME_STATUS_SUCCESS) {
        qDebug() << imageWidth << "  " << imageHeight;

        matImage.create(imageHeight, imageWidth, CV_8UC3);
        void* pRGB24Buffer = NULL;
        pRGB24Buffer = imageData->ConvertToRGB24(GX_BIT_0_7, GX_RAW2RGB_NEIGHBOUR, true);

        memcpy(matImage.data, pRGB24Buffer, static_cast<size_t>(imageHeight) * imageWidth * 3);

        cv::flip(matImage, matImage, 0);

        this->image = QImage((const uchar*)(matImage.data),
            matImage.cols, matImage.rows,
            QImage::Format_RGB888);
    }
}
