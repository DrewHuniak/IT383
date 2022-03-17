#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
/* Be CAREFUL about buffering effect */
int main()
{

	pid_t pid;
	pid_t pid2;

	fprintf(stderr,"Before calling fork()..\n");
	fflush(stderr);

	pid = fork();
	fprintf(stderr,"after calling fork()..\n");
	fflush(stderr);

	if (pid < 0) { /* error occurred */
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	else if (pid == 0) {/* child process */
		fprintf(stderr,"--->Child begins...\n");
		fflush(stderr);
		sleep(5);
		//execlp("/bin/ls","ls",NULL);
		//execlp("/bin/ls","ls",NULL);
		//execlp("/bin/ls","whatever",NULL);
		execlp("ls","whatever","-l", "/", NULL);   // % ls -l /
		//execlp("ls","whatever","-l", "/", "/etc", NULL);   // % ls -l / /etc
		
	}
	else {/* pid > 0 */ /* parent process */
		/* parent will wait for the child to complete */
		fprintf(stderr,"--->Child's pid value=%d\n",pid);

//		wait(NULL);
		fprintf(stderr,"--->Child complete\n");
		fflush(stderr);

	}
	return 0;
}
