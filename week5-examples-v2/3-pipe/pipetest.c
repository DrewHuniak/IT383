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

	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	// debugging purpose
	fprintf(stderr,"fd[0]=%d,fd[1]=%d\n",fd[0],fd[1]);



	/* fork a child process */
	pid = fork();


	if (pid < 0) {/* error occurred */
		fprintf(stderr,"Fork failed");
		return 1;
	}
	else {
		// debugging purpose
		fprintf(stderr,"pid=%d\n",pid);
		fflush(stderr);
	}

	if (pid >0) { /* parent process */
		/* close the unused end of the pipe */
		close(fd[READ_END]);

		printf("parent: before writing data into pipe\n");
	//sleep(3600);
		/* write to the pipe */
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		printf("parent: after writing data into pipe\n");
		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	else { /*pid == 0 --> child process */
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);
	
		printf("child: before reading data from pipe\n");
		fflush(stdout);
		/* read from the pipe */
		read(fd[READ_END],read_msg, BUFFER_SIZE);
		printf("child: ***read****:------ %s -----\n",read_msg);
		// fflush(stdin);

		/* close the write end of the pipe */
		close(fd[READ_END]);
	}

	return 0;
}
