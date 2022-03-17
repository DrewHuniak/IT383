#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
main()
{
	char *msg = "my data\n";
	int fd = open("foo",O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);


	if (fd < 0)
	{
		perror("open failed\n");
		exit(-1);
	}
	write(fd, msg, strlen(msg));

	close(fd);


}
