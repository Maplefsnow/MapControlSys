#include "FAIORelay.h"
#include "qdebug.h"

#define throwError(x) \
	er = x;\
	if(er != FAIO_ERROR_SUCCESS){\
		throw er;\
		er = FAIO_ERROR_SUCCESS;\
		return;\
	}

IOBERROR er = FAIO_ERROR_SUCCESS;

FAIORelay::FAIORelay() {
}

FAIORelay::FAIORelay(short com) {
	this->com = com;
	iob_board_init(com, 0x00);
}

FAIORelay::~FAIORelay() {
}

void FAIORelay::onPort(short port) {
	throwError(iob_write_outbit(this->com, port, true));
}

void FAIORelay::offPort(short port) {
	throwError(iob_write_outbit(this->com, port, false));
}

void FAIORelay::closeCard() {
	throwError(iob_board_close(this->com, false));
}

int FAIORelay::getPortStatus(short port) {
	int status = iob_read_inbit(this->com, port);
	if (status >= 0) return status;
	else {
		throw status;
		return -1;
	}
}


