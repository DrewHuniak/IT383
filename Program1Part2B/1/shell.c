#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>


void clean_up_child_process(int signal_number)
{
    int status;
    waitpid(-1, NULL, WNOHANG);

  
}

int createNewProcess(char* args[4], int argCount, int bg_flag, int rd_flag)
{
    int pid = fork(); //Creating a new process
    if(pid < 0)//Process has failed
    {
        printf("error has occured");
        exit(1);
    }
    else if(pid == 0) //Child Process
    {
        int val = argCount;
        if(bg_flag)//If background process dont include & in the arguments
        {
            val--;
        }
        if(rd_flag)
        {
            val -= 2;
        }
        switch(val)
        {
            case 1:
                execlp(args[argCount-1], args[argCount-1],NULL);
                break;
            case 2:
                execlp(args[argCount-1], args[argCount-1],args[argCount-2],NULL);
                break;
            case 3:
                execlp(args[argCount-1], args[argCount-1],args[argCount-2],args[argCount-3],NULL);
                break;
            case 4:
                execlp(args[argCount-1], args[argCount-1],args[argCount-2],args[argCount-3],args[argCount-4],NULL);
                break;
        }
        exit(-1); //execlp failed, likely command did not exist
    }
    else //Parent Process
    {
        if(!bg_flag)
        {
            wait(NULL);
        }
        else{
            signal(SIGCHLD, clean_up_child_process);
            printf("[1]+ Running (Pid: %d) ", pid);
            for(int i = 0; i < argCount; i++)
            {
                printf("%s ", args[i]);
            }
            printf("\n");
        }
        return pid;
    }
}

void fileOutput(char* file)
{
    int fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

int sendToForeground(int pid)
{
    int status;
    waitpid(pid, &status, 0);
    return status;
}

int parse(char* args[4],char buffer[100])
{
    int argCount = 0;
    char* token = strtok(buffer, " \n\t$"); 
    while(token != NULL)
    {
        args[argCount++] = token;
        token = strtok(NULL, " \n\t$");
    }
    return argCount;
}

int main()
{
    char* arguments[4];
    char buffer[100];
    int argCount = 1;
    int bg_flag;
    int bg_process;
    
    int rd_flag;
    int fd_stdout;

    while(strcmp(arguments[argCount-1],"exit") != 0)
    {
        printf("dnhunia> ");
        fgets(buffer, 100, stdin);
    
        if(buffer[0] != '\n') //Dont allow empty strings to be accepted
        {
            rd_flag = 0;
            argCount = parse(arguments, buffer);

            bg_flag = *arguments[0] == '&' ? 1 : 0;//Determine if this is a background process

            if(strcmp(arguments[1], "<*") == 0) //If redirection is happening
            {
                if(argCount >= 3)
                {
                    fd_stdout = dup(STDOUT_FILENO); //Create copy for later so return is possible later
                    fileOutput(arguments[0]);
                    rd_flag = 1;
                }
            }

            if(strcmp(arguments[argCount-1],"fg") == 0) //foreground command 
            {
               // argCount == 2 ? sendToForeground(atoi(arguments[0])) : sendToForeground(bg_process);     
                sendToForeground(bg_process);
            }
            else if(strcmp(arguments[argCount-1],"exit") != 0) //Dont create a new process is exiting
            {
                int pid = createNewProcess(arguments, argCount, bg_flag, rd_flag);
                if(bg_flag)
                {
                    bg_process = pid;
                    
                }
            }

            if(rd_flag)//set output back
            {
                dup2(fd_stdout, STDOUT_FILENO);
            }
        }
    }
   


    return 0;
}
