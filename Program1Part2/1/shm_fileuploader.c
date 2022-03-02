#include "filesharing.h"

int main()
{
    const int SIZE = 53477376;
  
    struct filesharing_struct *fs = (struct filesharing_struct*) malloc(sizeof(struct filesharing_struct));
    fs->flag = 'f';
    fs->size = 0;

    //Created Shared Memory Object
    int shm_fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
    if(shm_fd < 0)
    {
        printf("Shm error cannot not open output file\n");
        return -1;
    }
    if(ftruncate(shm_fd, SIZE) < 0)   //Set size of shared memory object
    {
        printf("Error with ftruncate\n");
        return -1;
    }
    struct filesharing_struct *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED) //Validate that it worked
    {
        fprintf(stderr, "mmap() failed\n");
        return -1;
    }


    //Take in User input
    printf("Please type in the name of the file you want shared.\n");
    scanf("%s", fs->name);

    //Open User's file
    FILE *file = fopen(fs->name, "rb");
    if(file == NULL)
    {
        printf("%s could not be opened\n", fs->name);
        return -1;
    }

    //Read File;
    size_t size_r;
    char buffer[1024];
    size_t count = 0;
    while((size_r = fread(buffer, sizeof(char), 1024, file)) > 0)
    {
        memcpy(fs->content + count, buffer, size_r);
        count += size_r;   
    }
    fs->flag = 't';

    //Place content into memory map
    memcpy(ptr->content, fs->content, sizeof(fs->content));
    ptr->flag = fs->flag;
    memcpy(ptr->name, fs->name, sizeof(fs->name));

    //Find file size
    fseek(file, 0, SEEK_END);
    fs->size = (int)ftell(file);
    fseek(file,0,SEEK_SET);
    ptr->size = fs->size;
    
    fclose(file);

    return 0;
}