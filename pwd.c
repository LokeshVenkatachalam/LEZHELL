#include "headers.h"

char pwd_Path[100000];
void pwd(char *flags_of_command[],int no_of_flags_of_command)
{
	if(getcwd(pwd_Path,sizeof(pwd_Path))==NULL)
	{
		perror("error Finding path to home directory");
		return;
	}
	else
	{
		printf("%s\n",pwd_Path);
	}
	
}