#include <stdlib.h>
#include <stdio.h>

#include <string.h>

int main()
{
    printf("Please provide the name of the file.\n");
    char filename[100];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("%s could not be opened\n", filename);
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    char* t1;
    while(1)
    {
        char buffer[80];
        fgets(buffer, 80, file);

        if(feof(file))
        {
            break;
        }
        for(t1 = strtok(buffer, " "); t1 != NULL; t1 = strtok(NULL, " "))
        {
            wordCount++;
        }
        lineCount++;

    }

    printf("The total amount of words: %d\nThe total amount of lines: %d\n", wordCount, lineCount);


    fclose(file);
    return 0;
}