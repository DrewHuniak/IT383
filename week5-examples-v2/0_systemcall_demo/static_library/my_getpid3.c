// new code: 1/23/2017
// source: www.digilife.be/quickreference/qrc/.... ***reference.pdf
#include <syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(void)
{
	long ID1, ID2;
	/* 
         * direct system call
         * SYS_getpid (func no. is 39 ) 
         */
	printf("SYS_getpid=%d\n", SYS_getpid);
	fflush(stdout);
	ID1 = syscall(SYS_getpid);
	printf("syscall(SYS_getpid)=%ld\n", ID1);
	fflush(stdout);

	/*
 	 * "libc wrapped system call
 	 *  SYS_getpid (Func No. is 39)
 	 */
	ID2 = getpid();
	printf("getpid()=%ld\n", ID2);
	fflush(stdout);

	return(0);

}
