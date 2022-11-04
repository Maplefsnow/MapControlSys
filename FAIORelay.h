#pragma once

#include <FAIO.h>
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

	void onPort(short);
	void offPort(short);
	void closeCard();

	int getPortStatus(short);

private:
	short com = 0;

};

