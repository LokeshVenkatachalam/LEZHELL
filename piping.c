#include "headers.h"
bool pipe_Checking(char *command_1)
{
	bool piping_Flag=false;
	ll length_1=strlen(command_1);
	for(ll i=0;i<length_1;i++)
	{
		if(command_1[i]=='|')
		{
			piping_Flag=true;
		}
	}
	return piping_Flag;
}

bool check_Redirection(char *command_1)
{
	bool redirection_Flag=false;
	char *commands[100000];
	int no_of_flags=0;
    commands[0]= strtok(command_1," \t\n");
    while(commands[no_of_flags] != NULL)
    {
    	no_of_flags++;
    	commands[no_of_flags]=strtok(NULL," \t\n");
   	}
   	for(int i=0;i<no_of_flags;i++)
   	{
   		for(int j=0;j<strlen(commands[i]);j++)
   		{
   			if((commands[i][j]=='<')||(commands[i][j]=='>'))
   			{
   				redirection_Flag=true;
   			}
   		}
   	}
   	return redirection_Flag;
}

/*
void piping(char *command_2)
{
	char *commands_1[100000];
	int no_of_flags_1=0;
    commands_1[0]=strtok(commands_2,"|");
    while(commands_1[no_of_flags_1] != NULL)
    {
    	no_of_flags_1++;
    	commands_1[no_of_flags_1]=strtok(NULL,"|");
   	}
   	for(int i=0;i<no_of_flags_1;i++)
   	{
   		
   		int pipefd[100000][2];
        pid_t cpid;
        int z = pipe(pipefd);
        if (z < 0)
        {
            perror("Error: pipe could not be created\n");
        }
   		cpid = fork();
   		if (cpid == -1) 
   		{
            perror("fork");
            exit(EXIT_FAILURE);
        }
   		else if(cpid==0)
   		{
   			if(i==0)
   			{
   				dup2(pipefd[i][1], 1); 
                close(pipefd[i][0]);   
                strcpy(temp, commands[i]);
   			}
   			else if(i==(no_of_flags_1-1))
   			{
   				dup2(pipefd[i][0],0);
   			}
   			else
   			{
   				dup2(pipes[0], 0);

	  // replace grep's stdout with write end of 2nd pipe

	  			dup2(pipes[3], 1);

	  // close all ends of pipes

	  			close(pipes[0]);
	  close(pipes[1]);
	  close(pipes[2]);
	  close(pipes[3]);
   			}

   		}
   		run1(command_1[i]);
   	}
}
*/