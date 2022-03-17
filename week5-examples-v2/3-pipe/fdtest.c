#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main()
{

	int fd,fd2;

	close(1);
	fd = open("data.txt", O_CREAT|O_WRONLY,0666);
	fprintf(stderr,"fd=%d\n",fd);

	printf("Hello, IT383 students....\n");
	fflush(stdout);
	close(fd);
/*
	fd2 = open("data2.txt", O_CREAT|O_WRONLY,0666);
	printf("fd2=%d\n",fd2);



	close(fd2);
*/
}


