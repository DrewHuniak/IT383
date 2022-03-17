#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

  //	int pid;
  	int cid;


//	pid = fork();
	cid = fork();

//	if (pid ==0)
	if (cid ==0)
	{
		// child
		// (1)
		//while (1);
		// (2)
		printf(" Hello, I am a child process!\n");
	//	sleep(60);
		 execlp("/bin/ls","ls",NULL);
		 //execlp("/bin/sleep","sleep","20",NULL);
		printf(" YOU will never see my message !!!!");
                /*  this line will not be reached!!! */
	
	}
	printf("Hello, I am parent process\n");
	// parent
	//sleep(60);
}
