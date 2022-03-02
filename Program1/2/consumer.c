 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <sys/shm.h>
 #include <sys/stat.h>
 #include <sys/mman.h>

int main()
{
    const int SIZE = 4096;
    const char *name = "OS_dnhunia";
    int fd;
    char *ptr;

    fd = shm_open(name, O_RDONLY, 0666);
    printf("The value of fd: %d\n", fd);
    if(fd < 0)
    {
        printf("cannot open file\n");
        exit(-1);
    }


    ptr = (char *) mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
    printf("The value of mmap(): %s\n", (char* ) ptr);
    if(ptr == MAP_FAILED)
    {
        fprintf(stderr, "mmap() failed!\n");
        return -1;
    }

    printf("%s\n", (char*)ptr);
    printf("The value of shm_unlink(): %d\n", shm_unlink(name));


    return 0;
}