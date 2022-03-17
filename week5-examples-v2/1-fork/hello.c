#include <stdio.h>
#include <stdlib.h>

int main()
{
	int exitCode = 2;
	printf("Hello:...: my pid=%d\n",getpid());
	printf("Hello:...: my parent's pid=%d\n",getppid());
	// return exit code 5
	//exit(5);
	printf("Hello:....: my exit code is %d\n",exitCode);
	exit(exitCode);

}
