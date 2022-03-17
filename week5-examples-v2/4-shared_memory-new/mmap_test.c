#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <assert.h>

int main()
{
	int fd = open("/etc/hosts",  O_RDONLY);

	/* memory map the shared memory object */
	//char *ptr = mmap(0, 2000, PROT_READ, MAP_SHARED, fd, 0);
	char *ptr = mmap(0, 2000, PROT_READ, MAP_PRIVATE, fd, 0);
	assert(ptr !=MAP_FAILED);
	printf("%s\n", ptr);

	if (ptr == MAP_FAILED)
	{
		fprintf(stderr,"mmap() failed!\n");		
		return -1;

	}

	close(fd);



	putchar(*ptr);
	printf("\n");
	putchar(ptr[0]);
	putchar(ptr[1]);
	printf("\n");
	munmap(ptr,2000);

}
