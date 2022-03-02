#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argv, char** argc)
{
    if(argv != 4)
    {
        printf("Usage ./my_copy file1 file2 source_file\n");
        return 1;
    }

    FILE *file1 = fopen(argc[1], "w");
    FILE *file2 = fopen(argc[2], "w");
    FILE *file3 = fopen(argc[3], "r");

    if(file1 == NULL || file2 == NULL || file3 == NULL)
    {
        printf("Error opening a file\n");
        return 1;
    }

    char buffer[512];
    int size_r;
    int size_w;
    int size_w2;
    while(!feof(file3))
    {    
        size_r = fread(buffer, sizeof(char), 512, file3);
        
        size_w = fwrite(buffer, size_r, 512, file1);
        printf("size_w = %d\n", size_w);
        size_w2 = fwrite(buffer, size_r, 1, file2);
        printf("%d\n", size_r);

        if(size_r != size_w || size_w2 != size_r)
        {
            printf("Write size does not equal read size\n");
            return 1;
        }
    }


    fclose(file1);
    fclose(file2);
    fclose(file3);


    return 0;
}