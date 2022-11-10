//---------------------------------------------------------------
/**
\file           IGxImageFormatConvert.h
\brief        Definition of the IGxImageFormatConvert interface
\Date       2022-04-12
\Version    1.1.2204.9121

<p>Copyright (c) 2011-2021 China Daheng Group, Inc. Beijing Image
Vision Technology Branch and all right reserved.</p>
*/
//---------------------------------------------------------------

#pragma once
#include "GXIAPIBase.h"
#include "GXSmartPtr.h"
#include "IImageData.h"


//--------------------------------------------
/**
\brief    Image format conversion class
*/
//---------------------------------------------
class GXIAPICPP_API IGXImageFormatConvert
{

public:

    //---------------------------------------------------------
    /**
    \brief Destructor
    */
    //---------------------------------------------------------
    virtual ~IGXImageFormatConvert(){};

    //----------------------------------------------------------------------------------
	/**
	\brief       Sets the pixel format of the image you want to convert
	\param    emPixelFormat[in]       Image pixel format expected to be converted£¨Default : GX_PIXEL_FORMAT_UNDEFINED£©
	\return    void
	*/
	//----------------------------------------------------------------------------------
    virtual void SetDstFormat(GX_PIXEL_FORMAT_ENTRY emDstFormat) = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief      Get the pixel format of the image you want to convert
	\return   Image pixel format expected to be converted
	*/
	//----------------------------------------------------------------------------------
    virtual GX_PIXEL_FORMAT_ENTRY GetDstFormat() = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief        Set conversion algorithm
	\param     emConvertType[in]       Algorithm used in conversion£¨Default : GX_RAW2RGB_NEIGHBOUR£©
	\return     void
	*/
	//----------------------------------------------------------------------------------
    virtual void    SetInterpolationType(GX_BAYER_CONVERT_TYPE_LIST emInterpolationType) = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief        Get conversion algorithm
	\return      Algorithm used in conversion
	*/
	//----------------------------------------------------------------------------------
    virtual GX_BAYER_CONVERT_TYPE_LIST GetInterpolationType() = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief        Sets the alpha value of an image with an alpha channel
	\param     ui64AlphaValue[in]       Alpha channel value£¨Range : 0-255  Default : 255 £©
	\return     void
	*/
	//----------------------------------------------------------------------------------
    virtual void SetAlphaValue(uint64_t ui64AlphaValue) = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief        Gets the alpha value of an image with an alpha channel
	\return     Alpha channel value
	*/
	//----------------------------------------------------------------------------------
    virtual uint64_t GetAlphaValue() = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief       Obtain the converted image buffer size according to the image data(Unit : byte)
	\param    pObjSrcImageData[in]       Source image pointer
	\return    Buffer length of converted image
	*/
	//----------------------------------------------------------------------------------
    virtual uint64_t GetBufferSizeForConversion(CImageDataPointer pObjSrcImageData) = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief       Obtain the converted image buffer size according to the image data(Unit : byte)
	\param    ui64SrcWidth[in]        Source image width
	\param    ui64SrcHeight[in]       Source image height
	\param    emSrcFormat[in]        Source image pixel format
	\return    Buffer length of converted image
	*/
	//----------------------------------------------------------------------------------
    virtual uint64_t GetBufferSizeForConversion(uint64_t ui64SrcWidth, uint64_t ui64SrcHeight, 
        GX_PIXEL_FORMAT_ENTRY emSrcFormat) = 0;

    //----------------------------------------------------------------------------------
	/**
	\brief        Perform conversion

    Supported image format conversion include£º

    1.Bayer conversion
    a. input image format   GX_PIXEL_FORMAT_BAYER_GR8¡¢GX_PIXEL_FORMAT_BAYER_RG8¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB8¡¢GX_PIXEL_FORMAT_BAYER_BG8
    output image format    GX_PIXEL_FORMAT_MONO8¡¢GX_PIXEL_FORMAT_RGB8¡¢ 
                                        GX_PIXEL_FORMAT_RGBA8¡¢GX_PIXEL_FORMAT_BGRA8¡¢
                                        GX_PIXEL_FORMAT_ARGB8¡¢GX_PIXEL_FORMAT_ABGR8¡¢
                                        GX_PIXEL_FORMAT_RGB8_PLANAR

    b. input image format  GX_PIXEL_FORMAT_BAYER_GR10¡¢GX_PIXEL_FORMAT_BAYER_RG10¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB10¡¢GX_PIXEL_FORMAT_BAYER_BG10¡¢
                                        GX_PIXEL_FORMAT_BAYER_GR12¡¢GX_PIXEL_FORMAT_BAYER_RG12¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB12¡¢GX_PIXEL_FORMAT_BAYER_BG12¡¢
                                        GX_PIXEL_FORMAT_BAYER_GR16¡¢GX_PIXEL_FORMAT_BAYER_RG16¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB16¡¢GX_PIXEL_FORMAT_BAYER_BG16
    output image format    GX_PIXEL_FORMAT_MONO16¡¢GX_PIXEL_FORMAT_RGB16¡¢ 
                                        GX_PIXEL_FORMAT_RGBA16¡¢GX_PIXEL_FORMAT_BGRA16¡¢
                                        GX_PIXEL_FORMAT_ARGB16¡¢GX_PIXEL_FORMAT_ABGR16¡¢
                                        GX_PIXEL_FORMAT_RGB16_PLANAR

    2.RGB conversion
    a. input image format   GX_PIXEL_FORMAT_RGB8¡¢GX_PIXEL_FORMAT_BGR8
      output image format  GX_PIXEL_FORMAT_YUV444_8¡¢GX_PIXEL_FORMAT_YUV422_8¡¢
                                        GX_PIXEL_FORMAT_YUV411_8¡¢GX_PIXEL_FORMAT_YUV420_8_PLANAR¡¢
                                        GX_PIXEL_FORMAT_YCBCR444_8¡¢GX_PIXEL_FORMAT_YCBCR422_8¡¢
                                        GX_PIXEL_FORMAT_YCBCR411_8¡¢GX_PIXEL_FORMAT_MONO8

    b. input image format   GX_PIXEL_FORMAT_RGB16¡¢GX_PIXEL_FORMAT_BGR16
    output image format    GX_PIXEL_FORMAT_MONO16

	\param    pObjSrcImageData[in]             Source image pointer
	\param    pDstBuffer[in|out]                   Output converted image buffer data
	\param    nDstBufferSize[in]                    Input pDstBuffer size
	\param    bFlip[in]                                   Is the image mirrored
	\return    void
	*/
	//----------------------------------------------------------------------------------
    virtual void Convert(CImageDataPointer pObjSrcImageData, void* pDstBuffer, size_t nDstBufferSize, bool bFlip) = 0;
    
    //----------------------------------------------------------------------------------
	/**
	\brief        Perform conversion

    Supported image format conversion include£º

    1.Bayer conversion
    a. input image format   GX_PIXEL_FORMAT_BAYER_GR8¡¢GX_PIXEL_FORMAT_BAYER_RG8¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB8¡¢GX_PIXEL_FORMAT_BAYER_BG8
    output image format    GX_PIXEL_FORMAT_MONO8¡¢GX_PIXEL_FORMAT_RGB8¡¢ 
                                        GX_PIXEL_FORMAT_RGBA8¡¢GX_PIXEL_FORMAT_BGRA8¡¢
                                        GX_PIXEL_FORMAT_ARGB8¡¢GX_PIXEL_FORMAT_ABGR8¡¢
                                        GX_PIXEL_FORMAT_RGB8_PLANAR

    b. input image format  GX_PIXEL_FORMAT_BAYER_GR10¡¢GX_PIXEL_FORMAT_BAYER_RG10¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB10¡¢GX_PIXEL_FORMAT_BAYER_BG10¡¢
                                        GX_PIXEL_FORMAT_BAYER_GR12¡¢GX_PIXEL_FORMAT_BAYER_RG12¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB12¡¢GX_PIXEL_FORMAT_BAYER_BG12¡¢
                                        GX_PIXEL_FORMAT_BAYER_GR16¡¢GX_PIXEL_FORMAT_BAYER_RG16¡¢
                                        GX_PIXEL_FORMAT_BAYER_GB16¡¢GX_PIXEL_FORMAT_BAYER_BG16
    output image format    GX_PIXEL_FORMAT_MONO16¡¢GX_PIXEL_FORMAT_RGB16¡¢ 
                                        GX_PIXEL_FORMAT_RGBA16¡¢GX_PIXEL_FORMAT_BGRA16¡¢
                                        GX_PIXEL_FORMAT_ARGB16¡¢GX_PIXEL_FORMAT_ABGR16¡¢
                                        GX_PIXEL_FORMAT_RGB16_PLANAR

    2.RGB conversion
    a. input image format   GX_PIXEL_FORMAT_RGB8¡¢GX_PIXEL_FORMAT_BGR8
    output image format    GX_PIXEL_FORMAT_YUV444_8¡¢GX_PIXEL_FORMAT_YUV422_8¡¢
                                        GX_PIXEL_FORMAT_YUV411_8¡¢GX_PIXEL_FORMAT_YUV420_8_PLANAR¡¢
                                        GX_PIXEL_FORMAT_YCBCR444_8¡¢GX_PIXEL_FORMAT_YCBCR422_8¡¢
                                        GX_PIXEL_FORMAT_YCBCR411_8¡¢GX_PIXEL_FORMAT_MONO8

    b. input image format   GX_PIXEL_FORMAT_RGB16¡¢GX_PIXEL_FORMAT_BGR16
    output image format    GX_PIXEL_FORMAT_MONO16

    \param    pSrcBuffer[in]                 Source image Buffer
    \param    ui64SrcWidth[in]            Source image width
    \param    ui64SrcHeight[in]           Source image Height
    \param    emSrcFormat[in]            Source image pixel format
	\param    pDstBuffer[in|out]         Output converted image buffer data
	\param    nDstBufferSize[in]         Input pDstBuffer size
	\param    bFlip[in]                         Is the image mirrored
	\return    void
	*/
	//----------------------------------------------------------------------------------
    virtual void Convert(void* pSrcBuffer, uint64_t ui64SrcWidth, uint64_t ui64SrcHeight, 
        GX_PIXEL_FORMAT_ENTRY emSrcFormat, void* pDstBuffer, size_t nDstBufferSize, bool bFlip) = 0;

};

template class GXIAPICPP_API  GXSmartPtr<IGXImageFormatConvert>;
typedef GXSmartPtr<IGXImageFormatConvert>            CGXImageFormatConvertPointer;

