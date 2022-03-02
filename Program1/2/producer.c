#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096;
    const char *name = "OS_dnhunia";
    const char *message_0 = "Hello";
    const char *message_1 = "World!";

    int fd;
    char *ptr;
    int returned;

    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if(fd < 0)
    {
        printf("cannot open output file\n");
        exit(-1);
    }




    printf("The value of shm_open: %d\n", fd);

    printf("The value of tfruncate(): %d\n",ftruncate(fd, SIZE));
    

    ptr = (char *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED , fd, 0);
    printf("The value of mmap(): %s\n", (char*) ptr);
    if(ptr == MAP_FAILED)
	{
		fprintf(stderr, "mmap() failed!\n");
		return -1; 
	}

    printf("The value of sprintf: %d\n", sprintf(ptr, "%s", message_0));
    ptr += strlen(message_0);
    printf("The value of sprintf: %d\n", sprintf(ptr, "%s", message_1));
    ptr+= strlen(message_1);



    return 0;
}