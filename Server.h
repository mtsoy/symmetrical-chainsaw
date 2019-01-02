#ifndef _SERVER_H_
#define _SERVER_H_

	#include "Msg_Info.h"
	
	int CreateQueue();
	int ResendMessage(const int queue, msgbuf msg_deposit, int* client_number);

#endif
