#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();
    printf("fork() returns: %d\n", pid);
    int returnValue;

    if(pid < 0) //Error occurred
    {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if(pid == 0) //Child Process
    {
        returnValue = execlp("/bin/ls", "ls", NULL);
        printf("execlp() returns: %d\n",returnValue);
    }
    else //Parent process
    {
        returnValue = wait(NULL);
        printf("wait() returns: %d\n", returnValue);
        printf("Child Complete\n");
    }



    return 0;
}