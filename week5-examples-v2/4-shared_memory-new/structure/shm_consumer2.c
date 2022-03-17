#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>


#include "data.h"

int main()
{
	/* the size ( in bytes) of shared memory object */
	//const int SIZE=4096;
	int size;
	/* name of the shared memory object */
	//const char *name = "OS";
	const char *name = "kwsuh30_producer_consumer";
	/* shared memory file descriptor */
	int shm_fd;
	/* pointer to shared memory object */
	//void *ptr;
	common_t *ptr;

	/* open the shared memory object */
	shm_fd = shm_open(name, O_RDONLY, 0666);

	if (shm_fd < 0)
	{
		printf("shm_open failed");
		exit(-1);

	}
	
	/* memory map the shared memory object */
	//ptr = mmap(0,SIZE, PROT_READ,MAP_SHARED, shm_fd, 0);
	ptr = (common_t *)mmap(0,size, PROT_READ,MAP_SHARED, shm_fd, 0);


	/* read from the shared memory objec */
/*
	printf("%s",(char *) ptr);
*/
	printf("total number of elements:%d\n",ptr->count);
	for (int i=0; i < ptr->count;i++)
	{
		printf("%d\n", ptr->elements[i]);
	}

	/* remove the shared memory object */
	shm_unlink(name);

	return 0;
}

