#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;
    int cid;
    int count = 0;
    cid = fork();
    count++;
    if (cid > 0)
    {
        printf("count1 = %d\n", count);
    }
    else if (cid == 0)
    {
        printf("count2 = %d\n", count);
    }
    else
    {
            return -1;
    }

    printf("count3 = %d\n", count);
    return 0;
}
