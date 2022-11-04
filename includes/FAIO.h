/*//////////////////////////////////////////////////////////////////////////
*功能：FAIO板卡API函数
*作者：gcnhiexn
*时间：2015-2-22 20:38:25
*版本：3.17.1122.1450
*适用环境：支持Unicode;支持多线程操作;支持win x64和x86操作系统;支持VB,VB.net,VC,C#的调用(详见例程);

*时间：2017-3-3 14:37:11
*版本：5.17.3.314
*更新： 1，优化处理速度
		2，增加脉冲发生器的4个函数iob_board_pulser_xxxxx

*时间：2017-8-27 14:10:28
*版本：5.17.8.2714
*更新： 1，修复bitno越界问题。
		2，增加iob_board_waitportevent函数，用于支持不方便创建事件的编程语言(如:Labview)的调用.
		
*时间：2017-11-29 15:50:29
*版本：6.17.11.2915
*更新： 1，提升处理速度.
		2，修复输入端的电平错误(输入端有信号，软件得到的输入状态是0).
		3，增加输入输出端上次状态值，更加方便得到FAIO端口的变化.

*时间：2019-12-29 18:00:00
*版本：6.17.11.2916
*更新：1，增加宏定义

*时间：2020-5-10 10:15:19
*版本：6.17.11.2930
*更新：1，获取当前frameno的函数iob_board_getcurframeno。当上电时frameno恒为0，其他时候为非0。
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
#ifndef _NO_USE_FAIO_BIT_MACO_	//如果下面的宏与当前项目中的宏有冲突时，可以使用#define _NO_USE_FAIO_BIT_MACO_ 来禁用
//ISIOBITCHG_021:指定端口状态发生改变，且是从0变1。
//ISIOBITCHG_120:指定端口状态发生改变，且是从1变0。
//ISIOBITCHG:指定端口状态发生改变。
#define ISIOBITCHG_021(status,status_last,bit)	(0x01 & ((unsigned int)(status & (status^status_last))>>bit))
#define ISIOBITCHG_120(status,status_last,bit)	(0x01 & ((unsigned int)(status_last & (status^status_last))>>bit))
#define ISIOBITCHG(status,status_last,bit)		(0x01 & ((unsigned int)(status^status_last)>>bit))
#define GETIOBITVAL(status,bit)					(0x01 & ((unsigned int)(status)>>bit))
#define SETIOBITVAL(status,bit,bVal)			(bVal ? ((unsigned int)(status)|(1U<<bit)):((unsigned int)(status) & (~(1U << bit))))
#define ISIOPORTCHG(status,status_last)			(status != status_last)
#endif

//////////////////////////////////////////////////////////////////////////


//回调函数格式
typedef void (__stdcall *FA_IO_CALLBACK)(void* p, 
										 unsigned short comno, 
										 unsigned char inputstatus, 
										 unsigned char outputstatus,
										 unsigned char framenum);//为了兼容5.0及以下的版本，使用6.0及以上的版本请使用下面的回调函数

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
	FAIO_ERROR_SUCCESS				= 0,  // 成功
	FAIO_ERROR_OVERMAXBORADNUM		= -1, // comno 的值超出最大board数 0≤comno≤15
	FAIO_ERROR_INITFAILED			= -2, // board打开失败 //串口不存在
	FAIO_ERROR_WRONGBOARD			= -3, // board打开失败 //板卡异常:次品卡或者非该软件专用卡
	FAIO_ERROR_BOARDNOTINIT			= -4, // board没有初始化,即没有调用iob_board_init函数
	FAIO_ERROR_BOARDDISCONNECT		= -5, // board没有连接或者已经断开连接
	FAIO_ERROR_WRONGPARAM_DELAYOFF  = -6, // iob_set_delayOff() 中的secondevery 参数不正确
	FAIO_ERROR_READTIMEOUT			= -7, // iob_read_ 读操作超时
	FAIO_ERROR_INVALIDHANDLE		= -8, // iob_board_setportevent中的hPortEvent 为无效句柄
	
	FAIO_ERROR_WAITCOMMEVENT        = -9,  // COM端的WaitCommEvent 错误
	FAIO_ERROR_RECEIVE				= -10, // COM端的Receive 错误
	FAIO_ERROR_WRONGRECVBYTESIZE	= -11, // COM端的WrongRecvByteSize 错误
	FAIO_ERROR_WRITE				= -12, // COM端的WriteERROR 错误

	FAIO_ERROR_PULSERCREATEFAIL		= -13, // 脉冲发生器创建失败
	FAIO_ERROR_PULSERINVALID		= -14, // 脉冲发生器未创建

	FAIO_ERROR_WAITTIMEOUT			= -15, // iob_board_waitportevent 操作超时
	FAIO_ERROR_OVERMAXBITNUM		= -16, // bitno 的值超出最大bitno数 0≤bitno≤8
	FAIO_ERROR_BITNUMVALUEWRONG		= -17, // bitno 的值不正确，即iob_read_inbit，iob_read_outbit，iob_write_outbit中的bitno 不能等于0
}IOBERROR;



#ifdef __cplusplus
extern "C" {
#endif
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 输出端的1代表ON(闭合),输入端的1代表有信号							//
// COM口编号数最大为16 即0≤comno≤15									//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
///////////////////////////初始化函数/////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_read_getlasterror(unsigned short comno);

FAIO_API IOBERROR __stdcall iob_board_init(unsigned short comno, unsigned char outputstatus);
FAIO_API IOBERROR __stdcall iob_board_close(unsigned short comno, bool bOutputKeep);

///////////////////////////操作函数///////////////////////////////////////
// 操作函数中的bitno编号数最大为8 即0＜bitno≤8	 （bitno = 0时会返回错误代码FAIO_ERROR_BITNUMVALUEWRONG）
FAIO_API int __stdcall iob_read_inport(unsigned short comno);	// 返回输入端状态值
FAIO_API int __stdcall iob_read_outport(unsigned short comno);	// 返回输出端状态值
FAIO_API int __stdcall iob_read_inport_last(unsigned short comno);	// 返回输入端状态上一次的值
FAIO_API int __stdcall iob_read_outport_last(unsigned short comno);	// 返回输出端状态上一次的值
FAIO_API IOBERROR __stdcall iob_write_outport(unsigned short comno, unsigned char outputstatus);

FAIO_API int __stdcall iob_read_inbit(unsigned short comno, unsigned char bitno);	// bitno = 0时会返回错误代码FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API int __stdcall iob_read_outbit(unsigned short comno, unsigned char bitno);	// bitno = 0时会返回错误代码FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API int __stdcall iob_read_inbit_last(unsigned short comno, unsigned char bitno);	// 返回输入端某一位状态上一次的值 bitno = 0时会返回错误代码FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API int __stdcall iob_read_outbit_last(unsigned short comno, unsigned char bitno);	// 返回输出端某一位状态上一次的值 bitno = 0时会返回错误代码FAIO_ERROR_BITNUMVALUEWRONG
FAIO_API IOBERROR __stdcall iob_write_outbit(unsigned short comno, unsigned char bitno, bool bOn); // bitno = 0时会返回错误代码FAIO_ERROR_BITNUMVALUEWRONG

FAIO_API IOBERROR __stdcall iob_write_delayOff(unsigned short comno, SECONDEEVERY secondevery, unsigned char secondmulty);

///////////////////////////设置函数///////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_board_setcallback(void* p, unsigned short comno, FA_IO_CALLBACK callbackfunstatus);// typedef void far *LPVOID;
FAIO_API IOBERROR __stdcall iob_board_setcallback2(unsigned short comno, FA_IO_CALLBACK2 callbackfun2status, void* p);// typedef void far *LPVOID;
FAIO_API IOBERROR __stdcall iob_board_setoutport(unsigned short comno, bool bAllOn);
FAIO_API IOBERROR __stdcall iob_board_setportevent(unsigned short comno, void* hPortEvent);// typedef void *HANDLE; // hPortEvent = NULL时设置系统默认的hPortEvent

///////////////////////////等待函数///////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_board_waitportevent(unsigned short comno, unsigned int dwWaitTime);// typedef void *HANDLE;// hPortEvent = NULL时等待系统默认的hPortEvent   dwWaitTime 单位ms

////////////////////////////获取卡信息////////////////////////////////////
FAIO_API IOBERROR __stdcall iob_board_getboardinfo(unsigned short comno, unsigned char* version, unsigned char* cardtype);
FAIO_API IOBERROR __stdcall iob_board_getcurframeno(unsigned short comno, unsigned char* frameno);

////////////////////////////脉冲发生器//////////////////////////////////////////////
// 脉冲发生器中bitno编号数最大为8 即0≤bitno≤8	 （bitno = 0 所有bit）
FAIO_API IOBERROR __stdcall iob_board_pulser_create(unsigned short comno, unsigned char bitno);
FAIO_API IOBERROR __stdcall iob_board_pulser_destory(unsigned short comno, unsigned char bitno);
FAIO_API IOBERROR __stdcall iob_board_pulser_terminate(unsigned short comno, unsigned char bitno);
FAIO_API IOBERROR __stdcall iob_board_pulser_pulse(unsigned short comno, 
												   unsigned char bitno,			
												   bool bPositive,					// true:正向脉冲。 false:负向脉冲
												   unsigned int dwCount,			// 脉冲个数   //int为INT32
												   unsigned int dwTimePositive,		// 正极性的持续时间(详见文档)
												   unsigned int dwTimeNegative,		// 负极性的持续时间(详见文档)
												   unsigned int dwTimeFirst);		// 第一个脉冲的前奏时间(详见文档)



//////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif


#endif//end _FAIO_H_6CEA209B_4818_4363_AD9B_94C27359BA41_
