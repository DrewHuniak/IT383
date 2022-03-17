#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

//Fix short background timers messing up the shell.
// add foreground feature

int main()
{
    char* arguments[4];
    char buffer[100];
    char* token;
    int argCount = 1;
    pid_t pid;
    int bg_flag;
    int fg_flag;
    int status;

    while(strcmp(arguments[argCount-1],"exit") != 0)
    {

       // waitpid(getpid(), &status, WNOHANG);
        printf("dnhunia> ");
        fgets(buffer, 100, stdin);
    
        if(buffer[0] != '\n') //Dont allow empty strings to be accepted
        {
            //parsing arguments and command
            bg_flag = 0;
            fg_flag = 0;
            argCount = 0;
            token = strtok(buffer, " \n\t$"); 
            while(token != NULL)
            {
                arguments[argCount++] = token;
                token = strtok(NULL, " \n\t$");
            }

            if(*arguments[0] == '&')//If & set to a background process
            {
                bg_flag = 1;
            }
            if(strcmp(arguments[argCount-1],"fg") == 0) //foreground command 
            {
                if(argCount != 2)
                {
                    printf("fg: usage: fg [job_spec]\n");
                }
                else
                {
                     pid_t pidNum = atoi(arguments[argCount-2]);
                    // tcsetpgrp(0, getpgid(pidNum));
                    // waitpid(getpgid(pidNum), NULL, WUNTRACED);
                    // tcsetpgrp(0, getpgid(getpid()));
                    setpgid(pidNum, pidNum);
                    tcsetpgrp(0, pidNum);
                }
                fg_flag = 1;
            }

            if(strcmp(arguments[argCount-1],"exit") != 0 && !fg_flag) //Dont create a new process is exiting
            {
                pid = fork(); //Creating a new process
                if(pid < 0)//Process has failed
                {
                    printf("error has occured");
                    exit(1);
                }
                else if(pid == 0) //Child Process
                {

                    int result = 0;
                    int val = argCount;
                    if(bg_flag)//If background process dont include & in the arguments
                    {
                        val--;
                        setpgid(0,0);
                       // tcsetpgrp(0, getpgrp());
                        tcsetpgrp(0, 0);
                    }
                    switch(val)
                    {
                        case 1:
                            result = execlp(arguments[argCount-1], arguments[argCount-1],NULL);
                            break;
                        case 2:
                            result = execlp(arguments[argCount-1], arguments[argCount-1],arguments[argCount-2],NULL);
                            break;
                        case 3:
                            result = execlp(arguments[argCount-1], arguments[argCount-1],arguments[argCount-2],arguments[argCount-3],NULL);
                            break;
                        case 4:
                            result = execlp(arguments[argCount-1], arguments[argCount-1],arguments[argCount-2],arguments[argCount-3],arguments[argCount-4],NULL);
                            break;
                    }
                    if (result == -1)//Command did not exist
                    {
                        exit(-1);
                    }
                }
                else //Parent Process
                {
                    // printf("parent pid: %d\n", getpid());
                    // printf("pid: %d\n", pid);
                    if(!bg_flag)
                    {
                        wait(NULL);
                    }
                    else{
                       // waitpid(getpid(), &status, WNOHANG);
                        printf("[1]+ Running (Pid: %d) ", pid);
                        for(int i = 0; i < argCount; i++)
                        {
                            printf("%s ", arguments[i]);
                        }
                        printf("\n");
                    }
                }
                printf("end of process\n");
            }
            printf("End of loop\n");
        }
    }
   


    return 0;
}
