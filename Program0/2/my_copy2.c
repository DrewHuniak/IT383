#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argv, char** argc)
{
    if(argv != 4)
    {
        printf("Usage ./my_copy file1 file2 source_file\n");
        return 1;
    }


    int input = open(argc[3], O_RDONLY);
    int output1 = open(argc[1], O_RDWR | O_TRUNC | O_CREAT, 0666);
    int output2 = open(argc[2], O_RDWR | O_TRUNC | O_CREAT, 0666);

    if(input == -1 || output1 == -1 || output2 == -1)
    {
        printf("Error occured when opening a file\n");
        return 1;
    }

    int ret_in, ret_out1, ret_out2;
    char buffer[1024];
    while((ret_in = read(input, buffer, sizeof(buffer))) > 0)
    {
        ret_out1 = write(output1, buffer, ret_in);
        ret_out2 = write(output2, buffer, ret_in);
        if(ret_out1 != ret_in || ret_out2 != ret_in)
        {
            printf("Read does not match write\n");
            return 1;
        }
        
    }

    close(input);
    close(output1);
    close(output2);

    return 0;
}