#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//
// how to run this program
// ./forktest4 hello

/* Be CAREFUL about buffering effect */
int main(int argc,char *argv[])
{

	pid_t pid;
	pid_t pid2;
	int status;
	char path_name[100];
	char *execFileName;

	if (argc < 2)
	{
		perror("Usage: forktest4 executable_file\n");
		exit(-1);
	}
	else 
	{
		sprintf(path_name,"./%s",argv[1]);
		execFileName = argv[1];	
	}


	pid = fork();

	if (pid < 0) { /* error occurred */
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	else if (pid == 0) {/* child process */
		fprintf(stderr,"--->Child begins...\n");
		fflush(stderr);
		//sleep(10);

		 //execlp("/bin/ls","ls",NULL);
		 execlp(path_name,execFileName,NULL);
		
		/*  this line will not be reached!!! */
		
	}
	else {/* pid > 0 */ /* parent process */
		/* parent will wait for the child to complete */
		fprintf(stderr,"--->Child's pid value=%d\n",pid);

		// wait(NULL);
	        //pid2 = wait(&status);
	        pid2 = waitpid(-1,&status,0);
		fprintf(stderr,"--->Child complete: pid=%d,status=%d, wexiststatus=%d\n",
                              pid2,status,WEXITSTATUS(status));
		fflush(stderr);

	}
	return 0;
}
