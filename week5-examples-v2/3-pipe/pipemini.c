/*
 * Figure 3.23 ordinary pipes in Unix 
 */

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
	char write_msg[BUFFER_SIZE] =  "Greetings";
	char read_msg[BUFFER_SIZE];
	int fd[2];
	pid_t pid;

	{
//		int myfd;

//		myfd = open("/etc/passwd");


	}


	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	// debugging purpose
	fprintf(stderr,"fd[0]=%d,fd[1]=%d\n",fd[0],fd[1]);




	/* write to the pipe */
	write(fd[WRITE_END], write_msg, strlen(write_msg)+1);

	/* read from the pipe */
	read(fd[READ_END],read_msg, BUFFER_SIZE);
	printf("read:------ %s -----\n",read_msg);

	close(fd[READ_END]);
	close(fd[WRITE_END]);

	return 0;
}
