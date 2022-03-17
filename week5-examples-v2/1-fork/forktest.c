#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
/* Be CAREFUL about buffering effect */
int main()
{

	pid_t cid;
	pid_t pid2;

	cid = fork();

	if (cid < 0) { /* error occurred */
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	else if (cid == 0) {/* child process */
		fprintf(stderr,"[child]--->Child begins...pid=%d\n",getpid());
		fprintf(stderr,"[child]--->Child begins...ppid=%d\n",getppid());
		fflush(stderr);
		sleep(5); //<================
		//execlp("/bin/ls","ls",NULL);
		execlp("/bin/ls","ls", NULL);
		//execlp("ls","ls", NULL);
		//execlp("ls","whatever-doyoucarellycareaboutme...", NULL);
		/*  this line will not be reached!!! */
		
	}
	else {/* pid > 0 */ /* parent process */
		/* parent will wait for the child to complete */
		fprintf(stderr,"[parent]--->Child's pid value=%d\n",cid);
		fprintf(stderr,"[parent]--->before calling wait(NULL)",cid);

		int childpid = wait(NULL);
		fprintf(stderr,"[parent]--->after calling wait(NULL): my_id = %d",cid);
		fprintf(stderr,"[parent]--->after calling wait(NULL):my child id=%d",childpid);
		fprintf(stderr,"[parent]--->Child complete\n");
		fflush(stderr);

	}
	return 0;
	// exit(0);
}
