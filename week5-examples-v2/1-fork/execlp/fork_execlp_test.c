#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* Be CAREFUL about buffering effect */
int main(int argc,char *argv[])
{

	pid_t pid;
	pid_t pid2;
	int status;
	char path_name[100];
	char *execFileName;
	int i=0;
	printf("argc=%d\n",argc);
	for (i=0; i < argc; i++)
		printf("argv[%d]=%s\n",i, argv[i]);

	pid = fork();

	if (pid < 0) { /* error occurred */
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	else if (pid == 0) {/* child process */
		fprintf(stderr,"--->Child begins...\n");
		fflush(stderr);
		//sleep(10);

		 //execlp("/bin/ls","ls","-l", "/", NULL);
		 //execlp("/bin/ls","heheheh ","-l", "/", NULL);

		 //execlp("/bin/ls","ls",NULL);
		 //execlp("sleep","my_sleep_cmd","60", NULL);
		 execlp("./my_program","heheheh","argument 1", NULL);
		 //execlp("./my_program","argument 0",NULL, NULL);
	//	 execlp(argv[1],argv[1],argv[2], NULL);
	//	 execlp("argv[1]","argument 0",argv[2], NULL);
		 //execlp(path_name,execFileName,NULL);
		
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
