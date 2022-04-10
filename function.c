#include "headers.h"


void handler(int sig)
{
	int status;
	pid_t pid = waitpid(-1, &status, WNOHANG);
	if(pid>0)
	{
		if(WIFEXITED(status))
		{ 
		 	printf("pid %d exited normally",pid);
		}
		else
		{
			printf("pid %d exited abnormally",pid);	
		}
		exitting(pid);
		

	}
}
void functions(char **flags_of_command,int no_of_flags_of_command,struct jobs *background_Process_List)
{
	//printf("entered functions()\n");
	
	int FLAG_1=0,status;
	char in_string[10000];
	memset(in_string,0,10000);
	strcpy(in_string,"");
	for(ll i=0;i<no_of_flags_of_command;i++)
	{
		if(strcmp(flags_of_command[i],"&")==0)
		{
			FLAG_1=1;
			flags_of_command[i]=NULL;
			//in_string[i-1]=NULL;
			break;
		}
		else
		{
			strcat(in_string,flags_of_command[i]);
			strcat(in_string," ");	
		}
	}
	//printf("%s\n",in_string);
	
	if(FLAG_1==0)
	{
		pid_t pid = fork();
		if(pid<0)
		{
			perror("Error: Fork Failed\n");
		}
		else if (pid == 0)
		{
			//printf("entered pid=0\n");
			
			int ct=execvp(flags_of_command[0],flags_of_command);
			
			if(ct<0)
			{
				printf("Error: execvp of %s error\n",flags_of_command[0]);
			}
			
		}
		else
		{
			waitpid(pid,&status,WUNTRACED);
			

		}
	}
	else
	{
		signal(SIGCHLD, handler);


		no_of_Process_Created[0]++;
		strcpy(background_Process_List[no_of_Process_Created[0]].name,in_string);
		background_Process_List[no_of_Process_Created[0]].exited=1;
		

		pid_t pid = fork();
		background_Process_List[no_of_Process_Created[0]].pid=pid;	
		
		pid_t p;
		
		if(pid<0)
		{
			perror("Error: Fork Failed\n");
		}
		else if (pid == 0)
		{
			p = getpid();
			printf("%d\n",p);
			int ct=-1;
			ct=execvp(flags_of_command[0],flags_of_command);
			if(ct<0)
			{
				printf("Error: execvp of %s error\n",flags_of_command[0]);
				exitting(pid);
			}
		}
		else
		{
			
				
				
				
		}	

	}
		
}