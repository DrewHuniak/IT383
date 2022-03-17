#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int i;
    int arr[10];
    int output = open("textfile.txt", O_RDWR | O_CREAT | O_TRUNC);
    if(output < 0)
    {
        printf("Error opening output file\n");
        return 1;
    }

    printf("Enter 10 Integers...\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(i = 9; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
        char itoc = '0' + arr[i];
        write(output, &itoc, sizeof(itoc));
    }
    close(output);


    return 0;
}