#include <stdio.h>

main()
{

//	sleep(60); // sleep for 60 seconds
	int pid = getpid();
	int ppid = getppid();

	printf("my PID is %d\n", pid);
	printf("my Parent PID is %d\n", ppid);

}
