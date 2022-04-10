#include "headers.h"

void bg(char *flags_of_command[],struct jobs *background_Process_List,int no_of_flags_of_command)
{
   
    if(no_of_flags_of_command>1)
    {
        ll job_id=atoi(flags_of_command[1]);
        ll ct=0;
        for(ll i=1; i<=no_of_Process_Created[0]; i++)
        {
            if((i==job_id)&&(background_Process_List[i].exited==1))
            {
                ct=1;
                kill(background_Process_List[i].pid,SIGTTIN);  
                kill(background_Process_List[i].pid,SIGCONT);
            }
        }
        if (ct == 0)
        {
            perror("Error: No job exists at id given\n");
        }
    }    
    else
    {
        perror("The job id was not entered");
    }
}