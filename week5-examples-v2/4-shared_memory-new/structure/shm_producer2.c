#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>


#include "data.h"

int main()
{
	/* the size (in bytes) of shared memory object */
	//const int SIZE=4096;
	int size;
	/* name of the shraed memory object */
	// const char *name = "OS"; ==> DO NOT use this name!!
	const char *name = "kwsuh30_producer_consumer";
	/* strings written to shared memory */
	const char *message_0 = "Hey";
	const char *message_1 = "wakeup IT383 class!!";

	/* shared memroy file descriptor */
	int shm_fd;
	/* pointer to shared memory object */
	//void *ptr;
	common_t *ptr;
	
	/* create the shared memory object */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	if (shm_fd < 0)
	{
		printf("shm_open failed: return code=%d\n",shm_fd);
		exit(-1);

	}

	
	/* configure the size of the shared memory object */
	size = sizeof(common_t);
	ftruncate(shm_fd, size);

	/* memory map the shared memory object */
	//ptr = mmap(0,SIZE,PROT_WRITE, MAP_SHARED, shm_fd, 0);
	ptr = (common_t *)mmap(0,size,PROT_WRITE, MAP_SHARED, shm_fd, 0);

	/* write to the shared memory object */
/*
	sprintf(ptr, "%s", message_0);
	ptr += strlen(message_0);
	sprintf(ptr, "%s", message_1);
	ptr += strlen(message_1);
*/
	ptr->count = 2;
	ptr->elements[0] = 99;
	ptr->elements[1] = 100;
	return 0;
}


	
	
