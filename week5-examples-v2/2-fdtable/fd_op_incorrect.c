#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

main()
{
	int fd1 = open("./hosts", O_RDONLY);
	if (fd1 < 0) 
	{
		perror("opening for read error");
		exit(-1);
	}
	fprintf(stderr,"fd1=%d\n",fd1);

	int fd2 = open("./output.txt", O_WRONLY | O_CREAT, 0666);
	if (fd2 < 0)
	{
		perror("opening for read error");
		exit(-1);

	}
	fprintf(stderr,"fd2=%d\n",fd2);


	if (dup2(fd2, 1) == -1)
	{

		perror("dup2 failed");
		exit(-1);
	}
	close(fd2); // ---> incorrect!
	printf(" Hello11 \n");
	printf(" Hello22 \n");
	printf(" Hello33 \n");
	/*
	write(fd2, "Hello1",5);
	write(fd2, "Hello2",5);
	write(fd2, "Hello3",5);
	*/


	close(fd1);
	close(fd2);
}





