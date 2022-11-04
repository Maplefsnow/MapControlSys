/*//////////////////////////////////////////////////////////////////////////
*���ܣ�FAIO�忨API����
*���ߣ�gcnhiexn
*ʱ�䣺2015-2-22 20:38:25
*�汾��3.17.1122.1450
*���û�����֧��Unicode;֧�ֶ��̲߳���;֧��win x64��x86����ϵͳ;֧��VB,VB.net,VC,C#�ĵ���(�������);

*ʱ�䣺2017-3-3 14:37:11
*�汾��5.17.3.314
*���£� 1���Ż������ٶ�
		2���������巢������4������iob_board_pulser_xxxxx

*ʱ�䣺2017-8-27 14:10:28
*�汾��5.17.8.2714
*���£� 1���޸�bitnoԽ�����⡣
		2������iob_board_waitportevent����������֧�ֲ����㴴���¼��ı������(��:Labview)�ĵ���.
		
*ʱ�䣺2017-11-29 15:50:29
*�汾��6.17.11.2915
*���£� 1�����������ٶ�.
		2���޸�����˵ĵ�ƽ����(��������źţ�����õ�������״̬��0).
		3����������������ϴ�״ֵ̬�����ӷ���õ�FAIO�˿ڵı仯.

*ʱ�䣺2019-12-29 18:00:00
*�汾��6.17.11.2916
*���£�1�����Ӻ궨��

*ʱ�䣺2020-5-10 10:15:19
*�汾��6.17.11.2930
*���£�1����ȡ��ǰframeno�ĺ���iob_board_getcurframeno�����ϵ�ʱframeno��Ϊ0������ʱ��Ϊ��0��
//////////////////////////////////////////////////////////////////////////*/

#ifndef _FAIO_H_6CEA209B_4818_4363_AD9B_94C27359BA41_
#define _FAIO_H_6CEA209B_4818_4363_AD9B_94C27359BA41_


#ifndef Q_OS_WIN // for QT
    #ifndef _FAIO_API_
    #define FAIO_API _declspec(dllexport)
    #else
    #define FAIO_API _declspec(dllimport)
    #endif
#else
    #define FAIO_API
#endif


//////////////////////////////////////////////////////////////////////////
#ifndef _NO_USE_FAIO_BIT_MACO_	//�������ĺ��뵱ǰ��Ŀ�еĺ��г�ͻʱ������ʹ��#define _NO_USE_FAIO_BIT_MACO_ ������
//ISIOBITCHG_021:ָ���˿�״̬�����ı䣬���Ǵ�0��1��
//ISIOBITCHG_120:ָ���˿�״̬�����ı䣬���Ǵ�1��0��
//ISIOBITCHG:ָ���˿�״̬�����ı䡣
#define ISIOBITCHG_021(status,status_last,bit)	(0x01 & ((unsigned int)(status & (status^status_last))>>bit))
#define ISIOBITCHG_120(status,status_last,bit)	(0x01 & ((unsigned int)(status_last & (status^status_last))>>bit))
#define ISIOBITCHG(status,status_last,bit)		(0x01 & ((unsigned int)(status^status_last)>>bit))
#define GETIOBITVAL(status,bit)					(0x01 & ((unsigned int)(status)>>bit))
#define SETIOBITVAL(status,bit,bVal)			(bVal ? ((unsigned int)(status)|(1U<<bit)):((unsigned int)(status) & (~(1U << bit))))
#define ISIOPORTCHG(status,status_last)			(status != status_last)
#endif

//////////////////////////////////////////////////////////////////////////


//�ص�������ʽ
typedef void (__stdcall *FA_IO_CALLBACK)(void* p, 
										 unsigned short comno, 
										 unsigned char inputstatus, 
										 unsigned char outputstatus,
										 unsigned char framenum);//Ϊ�˼���5.0�����µİ汾��ʹ��6.0�����ϵİ汾��ʹ������Ļص�����

typedef void (__stdcall *FA_IO_CALLBACK2)(void* p, 
										 unsigned short comno, 
										 unsigned char inputstatus, 
										 unsigned char outputstatus,
										 unsigned char inputstatus_last, 
										 unsigned char outputstatus_last,
										 unsigned char framenum);


typedef enum faioSECONDEEVERY_ENUM
{
	FAIO_delayOff_0_1    = 0x12,	//0.1s  //iob_set_delayOff  secondevery
	FAIO_delayOff_0_5    = 0x13,	//0.5s  //iob_set_delayOff  secondevery
	FAIO_delayOff_1_0    = 0x14,	//1.0s  //iob_set_delayOff  secondevery
}SECONDEEVERY;


typedef enum faioERRORS_ENUM
{
	FAIO_ERROR_SUCCESS				= 0,  // �ɹ�
	FAIO_ERROR_OVERMAXBORADNUM		= -1, // comno ��ֵ�������board�� 0��comno��15
	FAIO_ERROR_INITFAILED			= -2, // board��ʧ�� //���ڲ�����
	FAIO_ERROR_WRONGBOARD			= -3, // board��ʧ�� //�忨�쳣:��Ʒ�����߷Ǹ����ר�ÿ�
	FAIO_ERROR_BOARDNOTINIT			= -4, // boardû�г�ʼ��,��û�е���iob_board_init����
	FAIO_ERROR_BOARDDISCONNECT		= -5, // boardû�����ӻ����Ѿ��Ͽ�����
	FAIO_ERROR_WRONGPARAM_DELAYOFF  = -6, // iob_set_delayOff() �е�secondevery ��������ȷ
	FAIO_ERROR_READTIMEOUT			= -7, // iob_read_ ��������ʱ
	FAIO_ERROR_INVALIDHANDLE		= -8, // iob_board_setportevent�е�hPortEvent Ϊ��Ч���
	
	FAIO_ERROR_WAITCOMMEVENT        = -9,  // COM�˵�WaitCommEvent ����
	FAIO_ERROR_RECEIVE				= -10, // COM�˵�Receive ����
	FAIO_ERROR_WRONGRECVBYTESIZE	= -11, // COM�˵�WrongRecvByteSize ����
	FAIO_ERROR_WRITE				= -12, // COM�˵�WriteERROR ����

	FAIO_ERROR_PULSERCREATEFAIL		= -13, // ���巢��������ʧ��
	FAIO_ERROR_PULSERINVALID		= -14, // ���巢����δ����

	FAIO_ERROR_WAITTIMEOUT			= -15, // iob_board_waitportevent ������ʱ
	FAIO_ERROR_OVERMAXBITNUM		= -16, // bitno ��ֵ�������bitno�� 0��bitno��8
	FAIO_ERROR_BITNUMVALUEWRONG		= -17, // bitno ��ֵ����ȷ����iob_read_inbit��iob_read_outbit��iob_write_outbit�е�bitno ���ܵ���0
}IOBERROR;



#ifdef __cplusplus
extern "C" {
#endif
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// ����˵�1����ON(�պ�),����˵�1�������ź�							//
// COM�ڱ�������Ϊ16 ��0��comno��15									//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
///////////////////////////��ʼ������/////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_read_getlasterror(unsigned short comno);

FAIO_API IOBERROR __stdcall iob_board_init(unsigned short comno, unsigned char outputstatus);
FAIO_API IOBERROR __stdcall iob_board_close(unsigned short comno, bool bOutputKeep);

///////////////////////////��������///////////////////////////////////////
// ���������е�bitno��������Ϊ8 ��0��bitno��8	 ��bitno = 0ʱ�᷵�ش������FAIO_ERROR_BITNUMVALUEWRONG��
FAIO_API int __stdcall iob_read_inport(unsigned short comno);	// ���������״ֵ̬
FAIO_API int __stdcall iob_read_outport(unsigned short comno);	// ���������״ֵ̬
FAIO_API int __stdcall iob_read_inport_last(unsigned short comno);	// ���������״̬��һ�ε�ֵ
FAIO_API int __stdcall iob_read_outport_last(unsigned short comno);	// ���������״̬��һ�ε�ֵ
FAIO_API IOBERROR __stdcall iob_write_outport(unsigned short comno, unsigned char outputstatus);

FAIO_API int __stdcall iob_read_inbit(unsigned short comno, unsigned char bitno);	// bitno = 0ʱ�᷵�ش������FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API int __stdcall iob_read_outbit(unsigned short comno, unsigned char bitno);	// bitno = 0ʱ�᷵�ش������FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API int __stdcall iob_read_inbit_last(unsigned short comno, unsigned char bitno);	// ���������ĳһλ״̬��һ�ε�ֵ bitno = 0ʱ�᷵�ش������FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API int __stdcall iob_read_outbit_last(unsigned short comno, unsigned char bitno);	// ���������ĳһλ״̬��һ�ε�ֵ bitno = 0ʱ�᷵�ش������FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API IOBERROR __stdcall iob_write_outbit(unsigned short comno, unsigned char bitno, bool bOn); // bitno = 0ʱ�᷵�ش������FAIO_ERROR_BITNUMVALUEWRONG

FAIO_API IOBERROR __stdcall iob_write_delayOff(unsigned short comno, SECONDEEVERY secondevery, unsigned char secondmulty);

///////////////////////////���ú���///////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_board_setcallback(void* p, unsigned short comno, FA_IO_CALLBACK callbackfunstatus);// typedef void far *LPVOID;
FAIO_API IOBERROR __stdcall iob_board_setcallback2(unsigned short comno, FA_IO_CALLBACK2 callbackfun2status, void* p);// typedef void far *LPVOID;
FAIO_API IOBERROR __stdcall iob_board_setoutport(unsigned short comno, bool bAllOn);
FAIO_API IOBERROR __stdcall iob_board_setportevent(unsigned short comno, void* hPortEvent);// typedef void *HANDLE; // hPortEvent = NULLʱ����ϵͳĬ�ϵ�hPortEvent

///////////////////////////�ȴ�����///////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_board_waitportevent(unsigned short comno, unsigned int dwWaitTime);// typedef void *HANDLE;// hPortEvent = NULLʱ�ȴ�ϵͳĬ�ϵ�hPortEvent   dwWaitTime ��λms

////////////////////////////��ȡ����Ϣ////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_board_getboardinfo(unsigned short comno, unsigned char* version, unsigned char* cardtype);
FAIO_API IOBERROR __stdcall iob_board_getcurframeno(unsigned short comno, unsigned char* frameno);

////////////////////////////���巢����//////////////////////////////////////////////
// ���巢������bitno��������Ϊ8 ��0��bitno��8	 ��bitno = 0 ����bit��
FAIO_API IOBERROR __stdcall iob_board_pulser_create(unsigned short comno, unsigned char bitno);
FAIO_API IOBERROR __stdcall iob_board_pulser_destory(unsigned short comno, unsigned char bitno);
FAIO_API IOBERROR __stdcall iob_board_pulser_terminate(unsigned short comno, unsigned char bitno);
FAIO_API IOBERROR __stdcall iob_board_pulser_pulse(unsigned short comno, 
												   unsigned char bitno,			
												   bool bPositive,					// true:�������塣 false:��������
												   unsigned int dwCount,			// �������   //intΪINT32
												   unsigned int dwTimePositive,		// �����Եĳ���ʱ��(����ĵ�)
												   unsigned int dwTimeNegative,		// �����Եĳ���ʱ��(����ĵ�)
												   unsigned int dwTimeFirst);		// ��һ�������ǰ��ʱ��(����ĵ�)



//////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif


#endif//end _FAIO_H_6CEA209B_4818_4363_AD9B_94C27359BA41_
