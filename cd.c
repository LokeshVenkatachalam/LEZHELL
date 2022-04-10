#include "headers.h"
#include "headers.h"

void cd(char *flags_of_command[],char *new_Path,char *home_Directory_Path,char *absolute_Directory_Path,char *Previous_Working_Directory,char *Current_Working_Directory, int no_of_flags_of_command)
{
	if(no_of_flags_of_command > 2)
	{
		perror("LEZHELL: cd: too many arguments\n");
	}
	else
	{
		if(no_of_flags_of_command<2)
		{
			strcpy(new_Path,home_Directory_Path);
		}
		else if(strcmp(flags_of_command[1],"/")==0)
		{
			strcpy(new_Path,flags_of_command[1]);
		}
		else if(strcmp(flags_of_command[1],".")==0)
		{
			strcpy(new_Path,absolute_Directory_Path);
		}
		else if(strcmp(flags_of_command[1],"~")==0)
		{
			strcpy(new_Path,home_Directory_Path);
		}
		else if(strcmp(flags_of_command[1],"-")==0)
		{
			strcpy(new_Path,Previous_Working_Directory);
			printf("%s\n",new_Path);
		}
		else
		{
			strcpy(new_Path,flags_of_command[1]);
			/*
			ll length_of_cd=strlen(flags_of_command[1]);
			strcpy(new_Path,absolute_Directory_Path);
			ll length_after_cd=strlen(new_Path);
			ll index_1=0;
			char temp[1000000];
			strcpy(temp,"");
			int temp_length=0;
			while(index_1<=length_of_cd)
			{
				if((flags_of_command[1][index_1]=='/')||(flags_of_command[1][index_1]=='\0'))
				{
					temp[temp_length]='\0';
					if((strcmp(temp,"."))==0)
					{

					}
					else if((strcmp(temp,".."))==0)
					{
						while(new_Path[length_after_cd]!= '/')
						{
							length_after_cd--;
							if(length_after_cd==0)
								break;
						}
						new_Path[length_after_cd]='\0';
					}
					else
					{
						new_Path[length_after_cd]='/';
						length_after_cd++;
						for(int i=0;i<strlen(temp);i++)
						{
							new_Path[length_after_cd]=temp[i];
							length_after_cd++;
						}
					}
					if(length_after_cd==0)
					{
						new_Path[0]='/';
						length_after_cd++;
					}
					strcpy(temp,"");
					temp_length=0;
				}
				else
				{
					temp[temp_length]=flags_of_command[1][index_1];
					temp_length++;
				}
				index_1++;
			}
			new_Path[length_after_cd]='\0';
			*/
		}
		int check;
		if((check=chdir(new_Path))<0)
		{
			printf("LEZHELL: cd: %s: No such file or directory\n",flags_of_command[1]);
		}
		else
		{
			
			strcpy(Previous_Working_Directory,Current_Working_Directory);
			getcwd(Current_Working_Directory,sizeof(Current_Working_Directory));
		}
	}

}
