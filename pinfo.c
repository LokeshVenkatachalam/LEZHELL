#include "headers.h"

char * get_Relative_Path_1(char *path_1,char *home_Directory_Path)
{
	char buffer_1[102060];
	char buffer_2[102060];
	strcpy(buffer_1,"");

	ll j=0;
	ll Flag_1=0;

	ll string_length_1=strlen(path_1);
	ll string_length_2=strlen(home_Directory_Path);
	for(ll i=0; i<string_length_1; i++)
	{
		if(i > string_length_2)
		{
			buffer_1[j] = path_1[i];
			j++;

		}
		else
		{
			if(i<string_length_2)
			{
				if(path_1[i]!=home_Directory_Path[i])
				{
					Flag_1=1;
					break;
				}
			}
		}
	}
	printf("%d\n",j);
	if(string_length_1<string_length_2)
	{
		Flag_1=1;
	}
	buffer_1[j] = '\0';
	strcpy(buffer_2,"");
	if(Flag_1==0)
	{
		strcat(buffer_2,"~");
		strcat(buffer_2,buffer_1);
	}
	else
	{
		strcat(buffer_2,path_1);
	}
	strcpy(path_1,"");
	strcat(path_1,buffer_2);
	return path_1;
	
}

void pinfo(char *flags_of_command[],char *home_Directory_Path, int no_of_flags_of_command)
{
	char  stat_file[1000],exe_file[1000],status,path_of_exe_file[10000];
	memset(stat_file,0,1000);
	memset(exe_file,0,1000);
	memset(path_of_exe_file,0,1000);
	pid_t pid;
	ll memory;
	int tpgid;
	strcpy(path_of_exe_file,"");
	if(no_of_flags_of_command == 1)
	{
		pid=getpid();
	}
	else
	{
		pid=atoi(flags_of_command[1]);
	}
	sprintf(stat_file, "/proc/%d/stat", pid);
	int ct1 = open(stat_file, O_RDONLY);
    if (ct1 < 0)
        perror("Error: no such process exists\n");
    else
    {
        FILE *file1;
        file1 = fopen(stat_file, "r");
        fscanf(file1, "%*d %*s %c %*d %*d %*d %*d %d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lld", &status,&tpgid,&memory);
        fclose(file1);
        printf("PID -- %d\n", pid);
        if(pid==tpgid)
        	printf("Process Status -- %c+\n", status);
        else
        	printf("Process Status -- %c\n", status);
        printf("Memory -- %lld\n", memory);
        sprintf(exe_file, "/proc/%d/exe", pid);
        int x = readlink(exe_file, path_of_exe_file, sizeof(path_of_exe_file));
        char *output_path;
        printf("%s\n",path_of_exe_file);
        output_path=get_Relative_Path_1(path_of_exe_file,home_Directory_Path);
        printf("Executable Path-- %s\n", output_path);
    }
}
