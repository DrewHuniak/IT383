#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int arr[10];
    FILE *file = fopen("textfile.txt", "w");

    printf("Enter 10 Integers...\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 9; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
        fprintf(file, "%c\n", '0' + arr[i]);
    }
    fclose(file);



    return 0;
}