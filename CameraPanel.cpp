#include "CameraPanel.h"
#include "MainWindow.h"
#include "qdebug.h"

void initCamParams(DaHengCamera* cam);
cv::Mat matImage;

CameraPanel::CameraPanel(QWidget* parent) : QWidget(parent) {
    IGXFactory::GetInstance().Init();
}

CameraPanel::~CameraPanel() {
    if (!(this->camera.getDevice() == nullptr)) this->camera.getDevice()->Close();

    IGXFactory::GetInstance().Uninit();
}

void CameraPanel::DoOnImageCaptured(CImageDataPointer& imageData, void* pUserParam) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

    // int labelHeight = mainWindow->ui.label_cameraImage->height();
    // int labelWidth = mainWindow->ui.label_cameraImage->width();
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

        mainWindow->ui.label_cameraImage->setPixmap(QPixmap::fromImage(this->image));
    }
}

Q_INVOKABLE void CameraPanel::updateImage() {
    
    return Q_INVOKABLE void();
}

void CameraPanel::initCam() {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(this->topLevelWidget());

    gxdeviceinfo_vector deviceInfoVector;
    IGXFactory::GetInstance().UpdateDeviceList(0, deviceInfoVector);

    if (deviceInfoVector.size() == 0) {
        mainWindow->ui.statusBar->showMessage("No camera found!", 2000);
        return;
    }

    gxstring camSN = deviceInfoVector[0].GetSN();
    mainWindow->ui.label_camSN->setText(QString::fromStdString(std::string(camSN)));

    this->camera = DaHengCamera(camSN);

    this->camera.initDeviceParams();
}

void CameraPanel::startGrab() {
    this->camera.getCamStream()->RegisterCaptureCallback(this, NULL);
    this->camera.getCamStream()->StartGrab();
    this->camera.getCamFeatures()->GetCommandFeature("AcquisitionStart")->Execute();
}

void CameraPanel::stopGrab() {
    this->camera.getCamFeatures()->GetCommandFeature("AcquisitionStop")->Execute();
    this->camera.getCamStream()->StopGrab();
    this->camera.getCamStream()->UnregisterCaptureCallback();
}
