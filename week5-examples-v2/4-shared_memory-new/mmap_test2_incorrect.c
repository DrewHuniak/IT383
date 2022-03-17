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
	int size=0;



//	int fd = open("./my_output.txt",  O_CREAT | O_RDWR|O_TRUNC,0666);
//	int fd = open("./my_output.txt",   O_RDWR); // ==> correct
	int fd = open("./my_output.txt",   O_WRONLY);  // ==> incorrect (you need to have both read and write persmission for MAP_SHARED

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

 	printf("statbuf.st_size=%ld\n", statbuf.st_size);
	size = statbuf.st_size;
	// If you want to use MAP_SHARED, you will need to have O_RDWR option when you open a file for the mmap() call!

//	char *ptr = (char *)mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd, 0); // ==> incorect
	char *ptr = (char *)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); // ---> correct
//	assert(ptr != MAP_FAILED);

	if (ptr == MAP_FAILED)
	{
		fprintf(stderr,"mmap() failed!!\n");
		return -1;

	}
	printf("ptr address is %p\n", ptr);
	
	close(fd);


	// write intot the file
	sprintf(ptr,"Hey IT383 class, wake up!!\n");

	exit(0);
	munmap(ptr,size);


}
