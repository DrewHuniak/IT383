#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* Be CAREFUL about buffering effect */
int main()
{

	pid_t pid;
	pid_t pid2;
	int status;

	pid = fork();

	if (pid < 0) { /* error occurred */
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	else if (pid == 0) {/* child process */
		fprintf(stderr,"--->Child begins...\n");
		fflush(stderr);
		sleep(10);
		 execlp("/bin/ls","ls",NULL);
		
		/*  this line will not be reached!!! */
		
	}
	else {/* pid > 0 */ /* parent process */
		/* parent will wait for the child to complete */
		fprintf(stderr,"--->Child's pid value=%d\n",pid);

		// wait(NULL);
		sleep(20);
	        pid2 = wait(&status);
		fprintf(stderr,"--->Child complete: pid=%d,status=%d\n",
                              pid2,status);
		fflush(stderr);

	}
	return 0;
}
