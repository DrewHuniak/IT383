#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    int returnValue;
    if((returnValue = pipe(fd)) == -1)
    {
        fprintf(stderr, "Pipe failed");
        return 1;
    }
    printf("pipe: %d\n", returnValue);

    pid = fork();
    printf("pid: %d\n", pid);

  

    if(pid < 0)
    {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    if(pid > 0)
    {
        close(fd[READ_END]);

        returnValue = write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
        printf("Child Write: %d\n", returnValue);

        close(fd[WRITE_END]);
    }
    else
    {
        close(fd[WRITE_END]);

        returnValue = read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Parent read: %d\n", returnValue);
        printf("read %s\n", read_msg);

        close(fd[READ_END]);
    }


}