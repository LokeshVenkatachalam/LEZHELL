#include "headers.h"

void jobs(char *flags_of_command[],struct jobs *background_Process_List, int no_of_flags_of_command)
{
	int Flag=0;
	int running=0;
	int stopped=0;
	int non_exit_process=0;
	int visited[1000];
	memset(visited,0,1000*sizeof(visited[0]));
	if(no_of_flags_of_command>1)
	{
		
		if(strcmp(flags_of_command[1],"-r")==0)
		{
			Flag=1;
		}
		else if(strcmp(flags_of_command[1],"-s")==0)
		{
			Flag=2;
		}
		else
		{
			printf("Wrong Flag\n");
		}
	}
//	printf("Flag done= %d",Flag);

	for(int i=1;i<=no_of_Process_Created[0];i++)
	{
		if(background_Process_List[i].exited==-1)
			continue;
		char  stat_file[500],status;
		memset(stat_file, 0, 500);
		pid_t pid=background_Process_List[i].pid;
        sprintf(stat_file, "/proc/%lld/stat",pid);
        FILE *file1;
        file1 = fopen(stat_file, "r");
        if(file1<0)
            perror("Error: no such process exists\n");
        else
        {
            fscanf(file1, "%*d %*s %c", &status);
            fclose(file1);
        }
        if(status=='T')
        {
            strcpy(background_Process_List[i].status,"Stopped");
            stopped++;
        }
        else 
        {
            strcpy(background_Process_List[i].status,"Running");
            running++;
        }
        non_exit_process++;
	}
	
	if(Flag==0)
	{
		for(int i=1;i<=non_exit_process;i++)
		{
			int lowest_id=0;
			for(int j=1;j<=no_of_Process_Created[0];j++)
			{
				if((visited[j]==0)&&(background_Process_List[j].exited==1))
				{
					if(lowest_id==0)
					{
						lowest_id=j;
					}
					else
					{
						if(strcmp(background_Process_List[lowest_id].name,background_Process_List[j].name)>0)
						{
							lowest_id=j;
						}
					}
				}
				//printf("%d %d %d\n",j,lowest_id,visited[j]);
			}

			printf("[%lld] %s %s [%lld]\n",lowest_id,background_Process_List[lowest_id].status,background_Process_List[lowest_id].name,background_Process_List[lowest_id].pid);
			fflush(stdout);
			visited[lowest_id]=1;
		}
	}
	else if(Flag==1)
	{
	//	printf("%s %d\n",flags_of_command[1],running);
		for(int i=1;i<=running;i++)
		{
			int lowest_id=0;
			for(int j=1;j<=no_of_Process_Created[0];j++)
			{
				if((visited[j]==0)&&(background_Process_List[j].exited==1)&&(strcmp(background_Process_List[j].status,"Running")==0))
				{
					if(lowest_id==0)
					{
						lowest_id=j;
					}
					else
					{
						if(strcmp(background_Process_List[lowest_id].name,background_Process_List[j].name)>0)
						{
							lowest_id=j;
						}
					}
				}
				//printf("%d %d %d\n",j,lowest_id,visited[j]);
			}

			printf("[%lld] %s %s [%lld]\n",lowest_id,background_Process_List[lowest_id].status,background_Process_List[lowest_id].name,background_Process_List[lowest_id].pid);
			fflush(stdout);
			visited[lowest_id]=1;
		}
	}
	else if(Flag==2)
	{
		for(int i=1;i<=stopped;i++)
		{
			int lowest_id=0;
			for(int j=1;j<=no_of_Process_Created[0];j++)
			{
				if((visited[j]==0)&&(background_Process_List[j].exited==1)&&(strcmp(background_Process_List[j].status,"Stopped")==0))
				{
					if(lowest_id==0)
					{
						lowest_id=j;
					}
					else
					{
						if(strcmp(background_Process_List[lowest_id].name,background_Process_List[j].name)>0)
						{
							lowest_id=j;
						}
					}
				}
				//printf("%d %d %d\n",j,lowest_id,visited[j]);
			}

			printf("[%lld] %s %s [%lld]\n",lowest_id,background_Process_List[lowest_id].status,background_Process_List[lowest_id].name,background_Process_List[lowest_id].pid);
			fflush(stdout);
			visited[lowest_id]=1;
		}
	}

}