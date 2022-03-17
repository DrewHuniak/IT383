#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

main()
{


	int fd[10];
	char buffer[100];

	fd[0] = open("/etc/hosts", O_RDONLY);
	printf("f]d=%d\n", fd[0]);

	close(fd[0]); /// *********

	fd[0] = open("/etc/hosts", O_RDONLY);
	printf("f]d=%d\n", fd[0]);
	fd[1] = open("/etc/passwd", O_RDONLY);
	printf("fd=%d\n", fd[1]);
	fd[2] = open("/etc/hosts", O_RDONLY);
	printf("fd=%d\n", fd[2]);
	fd[3] = open("/etc/passwd", O_RDONLY);
	printf("fd=%d\n", fd[3]);

	write(1, "hello ", 5);

}
