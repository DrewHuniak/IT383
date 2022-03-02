#include "filesharing.h"

int main()
{
    const int SIZE = 52428800;
    int shm_fd;

    //Open Shared memory object
    shm_fd = shm_open(NAME, O_RDONLY, 0666);
    if(shm_fd == -1) //IF shm fails
    {
        printf("There are no files in shared memory\n");
        return 1;
    }
    struct filesharing_struct *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED,shm_fd, 0);
    if(ptr == MAP_FAILED) //IF map fails
    {
        fprintf(stderr, "mmap() failed\n");
        return -1;
    }
    if(ptr->flag == 'f') //If no uploaded files
    {
        printf("There are no files uploaded\n");
        return 1;
    }
    
    //Create new file for the download
    FILE* file = fopen("copiedfiled.txt", "wb");

    //Write to file 1024 bytes at a time.
    int count = 0;
    int maxWrite = 1024;
    int size_w = 0;
    while(size_w < ptr->size)
    {
        size_w += fwrite(ptr->content + count, sizeof(char), maxWrite, file);
        count += maxWrite;
        if((ptr->size - size_w) < maxWrite) //update the max size write if the amount left to write is less than 1024
        {
            maxWrite = ptr->size - size_w;
        }
    }
    
    fclose(file);

    //Remove shared memory object
    shm_unlink(NAME);

    return 0;
}