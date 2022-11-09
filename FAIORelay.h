#pragma once

#include <FAIO.h>
#include <qstring.h>

#ifndef _WIN64
#pragma comment(lib, "FAIO.lib")
#else
#pragma comment(lib, "FAIO_x64.lib")
#endif

class FAIORelay {
public:
	FAIORelay();
	FAIORelay(short);
	~FAIORelay();

	void openCard(short com);
	void onPort(short port);
	void offPort(short port);
	void closeCard();

	int getPortStatus(short port);

	QString getErrorMsg(IOBERROR err);
	
private:
	short com = -1;
};

