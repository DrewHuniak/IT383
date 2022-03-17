// as of Jan/23/2017, this code does not work on IT Linux servers
// check the new version: my_getpid3.c instead

#include <stdio.h>

int pid;
main()
{

//	sleep(60);
	__asm__(
		"movl $20, %eax \n"
		"call *%gs:0x10	\n" /* offset 0x10 is not fixed across the systems */
		"movl %eax, pid	\n"
	);

	printf("my PID is %d\n", pid);

}
