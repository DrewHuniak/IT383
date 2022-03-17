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
	struct stat statbuf;

	char data[] ="ABCDEFGHIJKLMNOP";


//	int fd = open("./my_output.txt",  O_CREAT | O_RDWR|O_TRUNC,0666);
	int fd = open("./my_output.txt",   O_RDWR);

	printf("fd=%d\n",fd);
	if (fd < 0)
	{
		printf("cannot open output file\n");
		exit(-1);
	}

	if (fstat(fd,&statbuf) < 0)
	{
		fprintf(stderr,"fstat error\n");
		return -1;
	}
/*
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
	write(fd,data,strlen(data));
*/


	/* memory map the shared memory object */
	//char *ptr = (char *)mmap(0, 100, PROT_WRITE, MAP_SHARED, fd, 0);
	//char *ptr = (char *)mmap(NULL, 100, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
	//char *ptr = (char *)mmap(NULL, 100, PROT_READ, MAP_SHARED, fd, 0);
 	printf("statbuf.st_size=%d\n", statbuf.st_size);
	char *ptr = (char *)mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	assert(ptr != MAP_FAILED);
	printf("ptr address is %p\n", ptr);
	
	close(fd);

	//sprintf(ptr,"Hey IT383 class, wake up!!\n");

	exit(0);
	munmap(ptr,100);


}
