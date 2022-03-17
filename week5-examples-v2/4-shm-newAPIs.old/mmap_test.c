#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
	int fd = open("/etc/hosts",  O_RDONLY);

	/* memory map the shared memory object */
	char *ptr = mmap(0, 2000, PROT_READ, MAP_SHARED, fd, 0);

	printf("%s\n", ptr);
	close(fd);


}
