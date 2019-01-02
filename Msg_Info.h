#ifndef _MSG_INFO_H_
#define _MSG_INFO_H_

	#define MSG_LENGHT 42

	typedef struct _msgbuf{
		long mtype;
		
		int sender;
		int reciever;
		
		char *message;
	} msgbuf;

	#define MSG_SIZE   (sizeof(msgbuf) - sizeof(long))
	#define MSG_FLG    0
	#define NEW_CLIENT 1
	#define SERVER_ID  2
	#define BROADCAST  1

#endif
