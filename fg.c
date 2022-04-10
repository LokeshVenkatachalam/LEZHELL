#include "headers.h"

void fg(char *flags_of_command[],struct jobs *background_Process_List,int no_of_flags_of_command)
{
    if(no_of_flags_of_command>1)
    {
    	ll job_id = atoi(flags_of_command[1]);
    	ll flag = 0;
    	for (ll i = 1; i <=no_of_Process_Created[0]; i++)
    	{
        	if ((job_id==i)&&(background_Process_List[i].exited==1))
        	{
            	int status;

				signal (SIGINT, SIG_IGN);
      			signal (SIGQUIT, SIG_IGN);
     			signal (SIGTSTP, SIG_IGN);
      			signal (SIGTTIN, SIG_IGN);
      			signal (SIGTTOU, SIG_IGN);
      			signal (SIGCHLD, SIG_IGN);  

      			tcsetpgrp(STDIN_FILENO,background_Process_List[i].pid);
            	
            	flag = 1;
            	
            	
            	kill(background_Process_List[i].pid, SIGCONT);
            	background_Process_List[i].exited=-1;  
            	
            	waitpid(-1, NULL, WUNTRACED);   
            	
            	tcsetpgrp(STDIN_FILENO,getpgrp());
            	
            	signal (SIGINT,SIG_DFL);
      			signal (SIGQUIT,SIG_DFL);
     			signal (SIGTSTP,SIG_DFL);
      			signal (SIGTTIN,SIG_DFL);
      			signal (SIGTTOU,SIG_DFL);
      			signal (SIGCHLD,SIG_DFL); 

        	}
    	}
    	if (flag == 0)
        	perror("Error: No job exists at id given\n");
    	}
    else
    {
    	perror("The job id was not entered");
    }
    
    
}