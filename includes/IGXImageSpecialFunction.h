//---------------------------------------------------------------
/**
\file           GXImageSpecialFunction.h
\brief        IGXImageSpecialFunction Image special interface class
\Date       2022-04-12
\Version    1.1.2204.9121

<p>Copyright (c) 2011-2021 China Daheng Group, Inc. Beijing Image
Vision Technology Branch and all right reserved.</p>
*/
//---------------------------------------------------------------
#pragma once

#include "GXIAPIBase.h"
#include "GXSmartPtr.h"
#include "GXStringCPP.h"

//--------------------------------------------
/**
\brief    Image special interface class
*/
//---------------------------------------------
class GXIAPICPP_API IGXImageSpecialFunction
{
public:

    //---------------------------------------------------------
    /**
    \structure
    */
    //---------------------------------------------------------
    IGXImageSpecialFunction(void){};
    
    //---------------------------------------------------------
    /**
    \brief Destructor
    */
    //---------------------------------------------------------
    virtual ~IGXImageSpecialFunction(void){};
    
    //----------------------------------------------------------------------------------
	/**
	\brief     calculating lookup table of camera
    \param  nContrastParam      [in]            contrast param,range[-50~100]
    \param  dGamma                 [in]            gamma param,range[0.1~10]
    \param  nLightness               [in]            lightness param,range[-150~150]
    \param  pLut                        [in&out]    lookup table
    \param  pLutLength             [in&out]    lookup table length(unit:byte)
	\return    void
	*/
	//----------------------------------------------------------------------------------
	virtual void CalculaLut(int32_t nContrastParam, double dGamma, int32_t nLightness, 
	    void* pLut, uint32_t* pnLutLength) = 0;
	
    //--------------------------------------------------
    /**
    \brief  read lut file
    \param  pchLutFilePath  [in]     Lut file path. Lut file(xxx.lut) can be obtained from Lut 
    Create Tool Plugin,which can be get by select Plugin->Lut 
    Create Tool Plugin from the menu bar in GalaxyView.
    \param  pLut                [in&out] Lookup table. Users need to apply for memory in advance.The 
                                        memory size is also lookup table length(nLutLength),should be 
                                        obtained through the interface 
                                        GetRegisterFeature(¡°LUTValueAll¡±)->GetLength(),e.g.                          
    \param  pnLutLength   [in] Lookup table length(unit:byte),which should be obtained through
                                       the interface GetRegisterFeature(¡°LUTValueAll¡±)->GetLength(), e.g. 

    \return void
    */
    //--------------------------------------------------
    virtual void ReadLutFile(const GxIAPICPP::gxstring&  strLutFilePath, void *pLut, uint32_t *pnLutLength) = 0;
	
    //The extended adjustment parameters are added below and cannot be added to existing functions
    //...
    
};

template class GXIAPICPP_API  GXSmartPtr<IGXImageSpecialFunction>;
typedef GXSmartPtr<IGXImageSpecialFunction>            CGXImageSpecialFunctionPointer;
