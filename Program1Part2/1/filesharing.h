#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>

const char *NAME = "17491262_filesharing";

struct filesharing_struct
{
    char flag;
    int size;
    char name[50];
    char content[52428800];
};



