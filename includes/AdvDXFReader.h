//
// Copyright (c) Advantech Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Advantech end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//

#if !defined(ADVDXFREADER__INCLUDED_)
#define ADVDXFREADER__INCLUDED_

#ifdef __cplusplus
extern "C"
{
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
#define ADVDXFREADERAPI      __stdcall
#endif
/////////////////////////////////////////////////////////////////////////////


#define CLOSE         1
#define NOT_CLOSE     0

#ifndef SUCCESS
#define SUCCESS     0
#endif
//#define PI 3.1415926535897931 
// DXF  ������
#define AtEmptyPathErr		0x01         //·��Ϊ�մ���
#define AtFileTypeErr		0x02         //�ļ����ʹ���
#define AtEmptyFileErr   	0x03         //�ļ�Ϊ�մ���
//#define AtSerialNumErr  	0x04         //ͼ�����кų�����Χ����
#define AtSampleTypeErr  	0x05         //ͼ�����ʹ���
#define AtDataLoseErr    	0x06         //���ݶ�ʧ����
#define AtCreatSpaceErr    	0x07         //�������ݿռ�ʧ�ܣ�mallocʧ�ܣ�
#define AtInputLocusNumErr  0x08         //����켣��Ŀ����
#define AtLocusPtrErr       0x09         //�켣�������
#define AtInputSampleNumErr 0x0a         //����ͼԪ��Ŀ����
#define AtSamplePtrErr      0x0b         //ͼԪ�������
#define AtInputPataErr      0x0c         //�����������OpenDxf�����ľ��Ȳ�����



#define CW             0
#define CCW            1


LRESULT ADVDXFREADERAPI AtOpenDXF(char *dxfFilePath,             //�ļ�·��
			               double Proportion,             //CAD��ʵ��ͼ�ͻ����е�ͼ�ı���
							DWORD  Ellipse_Cut_Min_Angel,  //�ָ�鲹��Բ����С�Ƕ�
							DWORD  Spline_Cut_Step         //һ������Ҫ��Ϊ����ֱ�߶�
							);   //������ϵ
LRESULT ADVDXFREADERAPI AtGetType(DWORD * Type,
		                   DWORD   Direction,
			               DWORD   Locus_Num,
			               DWORD   Sample_Num);

LRESULT ADVDXFREADERAPI AtGetArc(double * Center_x,    //Բ��Բ�������xֵ
			        double * Center_y,    //Բ��Բ�������yֵ
			        double * Center_z,    //Բ��Բ�������zֵ
		            double * r,           //Բ���İ뾶
			        double * Start_X,     //Բ������ʼ���X����
                    double * Start_Y,     //Բ������ʼ���Y����Ƕ�
                    double * Start_Z,     //Բ������ʼ���z����Ƕ�
			        double * End_X,       //Բ������ֹ���X����
                    double * End_Y,       //Բ������ֹ���Y����
                    double * End_Z,       //Բ������ֹ���Y����
                    DWORD  * MoveDirection, //�˶�����
					double * Start_Angle, //Բ������ʼ�Ƕ�
		            double * End_Angle,   //Բ������ֹ�Ƕ�
		            DWORD 	* Plane,   //Բ������ƽ��
					DWORD    Direction,  //�켣�ķ���
			        DWORD    Locus_Num,   //�켣�����к�
				    DWORD    Sample_Num); //ͼԪ�����к�

LRESULT ADVDXFREADERAPI AtGetLine(double *Start_x,    //ֱ����ʼ�������xֵ
			                                 	  double *Start_y,    //ֱ����ʼ�������yֵ
			                                 	  double *Start_z,    //ֱ����ʼ�������zֵ
			                                	  double *End_x,      //ֱ����ֹ�������xֵ
			                                	  double *End_y,      //ֱ����ֹ�������yֵ
			                                	  double *End_z,      //ֱ����ֹ�������zֵ
												  double *k,          //ֱ�ߵ�б��
												  DWORD   Direction,  //�켣�ķ���
												  DWORD   Locus_Num,  //�켣�����к�
				                                  DWORD   Sample_Num);//ͼԪ�����к�

LRESULT ADVDXFREADERAPI AtGetPoint(double *Point_x,//Point's x value
								   double *Point_y,//Point's y value
								   double *Point_z,//Point's z value
								   DWORD   Direction,  //�켣�ķ���
								   DWORD   Locus_Num,  //�켣�����к�
								   DWORD   Sample_Num);//ͼԪ�����к�


LRESULT ADVDXFREADERAPI AtGetMostValue( double * Min_x,    //�����ļ�����С���X����
				                                        double * Min_y,    //�����ļ�����С���y����
				                                        double * Min_z,    //�����ļ�����С���z����
			                                      	    double * Max_x,    //�����ļ��������X����
				                                        double * Max_y,    //�����ļ��������y����
				                                        double * Max_z     //�����ļ��������z����
				                                        );
	
LRESULT ADVDXFREADERAPI AtGetLocusCount( DWORD * Count);   //��ȡ�켣����Ŀ
LRESULT ADVDXFREADERAPI AtGetSampleCount(DWORD * Count,    //��Locus_Num���켣��ͼԪ�ĸ���
			                                             DWORD Locus_Num);  //�ڼ����켣
LRESULT ADVDXFREADERAPI AtCloseDXF();


#ifdef __cplusplus
}
#endif

#endif
