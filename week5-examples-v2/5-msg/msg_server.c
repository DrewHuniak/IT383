#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>

#include "msg.h"

#define MKEY1 0x1234
#define PERMS 0666
int main()
{
	int readid;
	int stat;

	/*
	 * Create the message queues, if required
	 */

	if ((readid = msgget(MKEY1, PERMS | IPC_CREAT)) < 0) {
		perror("server: can't get message queue 1 ");
	}

	printf("readid=%d\n",readid);
	
	while (1)
	{
		stat = msgrcv(readid, &msgp, sizeof(msgp), 0, 0);

		printf("message from client: %s\n",msgp.message);
	}
	exit(0);
}
