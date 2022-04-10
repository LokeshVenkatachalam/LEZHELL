#include "headers.h"

struct utsname uname_Pointer;
struct passwd* user_Name_Pointer;
uid_t uid_username;
char user_Name[1024];//string of the user name
char system_Name[1024];//string of the system name
char home_Directory_Path[100000];

char relative_Directory_Path[100000];
char absolute_Directory_Path[100000];
char Previous_Working_Directory[100000];
char Current_Working_Directory[100000];
char new_Path[100000];
char basic_Display[2060];
char lezhell_Prompt[102060];
char *commands[1000000];
char *flags_of_command[1000000];
int no_of_flags_of_command;
int no_of_Commands;
struct jobs background_Process_List[1000];
int no_of_Process_Created[1]={0};
void exitting(ll pid)
{
	for(int i=1;i<=no_of_Process_Created[0];i++)
	{
		if(background_Process_List[i].pid==pid)
		{
			background_Process_List[i].exited=-1;
			break;
		}
	}
}

void basic_Display_Find()
{
	/*HOST/SYSTEM NAME*/

	gethostname(system_Name,sizeof(system_Name));
	
	/*USERNAME

		get uid 
			+ 
		getpwuid()
		getpweuid()
			OR
		getlogin_r()

		can be used for getting username
	*/

	uid_username = getuid();
	user_Name_Pointer = getpwuid(uid_username);
	if(user_Name_Pointer)
	{
		strcpy(user_Name,"");
		strcat(user_Name,user_Name_Pointer->pw_name);
	}
	//getlogin_r(user_Name,sizeof(user_Name));
	
	//Creating basic_Display

	strcpy(basic_Display,"");
	strcat(basic_Display,"<");
	strcat(basic_Display,user_Name);
	strcat(basic_Display,"@");
	strcat(basic_Display,system_Name);	
	strcat(basic_Display,":");
}

void get_Relative_Path()
{
	char buffer_1[102060];
	
	strcpy(buffer_1,"");

	ll j=0;
	ll Flag_1=0;

	ll string_length_1=strlen(absolute_Directory_Path);
	ll string_length_2=strlen(home_Directory_Path);
	for(ll i=0; i<string_length_1; i++)
	{
		if(i > string_length_2)
		{
			buffer_1[j] = absolute_Directory_Path[i];
			j++;
		}
		else
		{
			if(i<string_length_2)
			{
				if(absolute_Directory_Path[i]!=home_Directory_Path[i])
				{
					Flag_1=1;
					break;
				}
			}
		}
	}
	if(string_length_1<string_length_2)
	{
		Flag_1=1;
	}
	buffer_1[j] = '\0';
	strcpy(relative_Directory_Path,"");
	if(Flag_1==0)
	{
		strcat(relative_Directory_Path,"~");
		strcat(relative_Directory_Path,buffer_1);
	}
	else
	{
		strcat(relative_Directory_Path,absolute_Directory_Path);
	}
	
}

void print_Lezhell_prompt()
{
	if(getcwd(absolute_Directory_Path,sizeof(absolute_Directory_Path))==NULL)
	{
		perror("error Finding path to current directory");
	}
	else
	{
		strcpy(lezhell_Prompt,"");
		get_Relative_Path();
		strcat(lezhell_Prompt,basic_Display);
		strcat(lezhell_Prompt,relative_Directory_Path);
		strcat(lezhell_Prompt,">");
	}
	printf("\e[1;93m");
	printf("%s",lezhell_Prompt);
	printf("\e[0;97m");
	
}

void home_Directory_Finder()
{
	if(getcwd(home_Directory_Path,sizeof(home_Directory_Path))==NULL)
	{
		perror("error Finding path to home directory");
	}
	else
	{
		strcpy(Previous_Working_Directory,home_Directory_Path);
		strcpy(Current_Working_Directory, home_Directory_Path);
	}
}
ll find_Decimal(char *string_1)
{
	int length=strlen(string_1);
	ll ans=0;
	for(int i=0;i<length;i++)
	{
		int digit=string_1[i]-'0';
		ans=ans*10+digit;
	}
	return ans;
}
void run1(char *commands_1)
{
			char string_2[1000000];
			char string_3[1000000];
			no_of_flags_of_command=0;
    		flags_of_command[0]= strtok(commands_1," \t\n");
    		while(flags_of_command[no_of_flags_of_command] != NULL)
    		{
    			no_of_flags_of_command++;
    			flags_of_command[no_of_flags_of_command]=strtok(NULL," \t\n");
    		}
    		if(pipe_Checking(commands_1)==true)
    		{
    			//piping(commands_1);
    			printf("pipe_Checking is true\n");
    		}
    		else if(check_Redirection(commands_1)==true)
    		{
    			//redirection(commands_1);
    			printf("check_Redirection is true\n");
    		}
    		else if(no_of_flags_of_command < 1)
    		{

    		}
    		else if(strcmp(flags_of_command[0],"cd")==0)
    		{
    			cd(flags_of_command,new_Path,home_Directory_Path,absolute_Directory_Path,Previous_Working_Directory,Current_Working_Directory,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"echo")==0)
    		{
    			
    			echo(flags_of_command,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"pwd")==0)
    		{
    			pwd(flags_of_command,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"ls")==0)
    		{
    			ls(flags_of_command,home_Directory_Path,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"pinfo")==0)
    		{
    			pinfo(flags_of_command,home_Directory_Path,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"fg")==0)
    		{
    			fg(flags_of_command,background_Process_List,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"bg")==0)
    		{
    			bg(flags_of_command,background_Process_List,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"repeat")==0)
    		{
    			strcpy(string_2,"");
    			for(int i=2;i<no_of_flags_of_command;i++)
    			{
    				strcat(string_2,flags_of_command[i]);
    				strcat(string_2," ");
    			}
    			ll repeat_value = find_Decimal(flags_of_command[1]);
    			//printf("%lld",repeat_value);
    			
    			for(int i=1;i<=repeat_value;i++)
    			{
    				strcpy(string_3,string_2);
    				run1(string_3);	
    			}
    			
    		}
    		else if(strcmp(flags_of_command[0],"jobs")==0)
    		{
    			jobs(flags_of_command,background_Process_List,no_of_flags_of_command);
    		}
    		else
    		{
    			functions(flags_of_command,no_of_flags_of_command,background_Process_List);
    		}
}
void run()
{
	
	print_Lezhell_prompt();
	size_t input_Line_Length;
	char *input_Line = NULL;
	ssize_t input_Line_Read_Flag;
	if((input_Line_Read_Flag=getline(&input_Line,&input_Line_Length,stdin)) == -1)
	{
		perror("Error reading the command line\n");
		return;
	}
	else
	{
		char commands_5[100000]; 
		strcpy(commands_5,input_Line);
		commands[0]= strtok(input_Line, ";\n"); //separating the commands
    	ll no_of_Commands=0;
    	while (commands[no_of_Commands] != NULL)
    	{
      		no_of_Commands++;
      		commands[no_of_Commands] = strtok(NULL, ";\n");
    	}
    	for(ll i=0;i<no_of_Commands;i++)
    	{
    		if(pipe_Checking(commands_5)==true)
    		{
    			//piping(commands_1);
    			printf("pipe_Checking is true\n");
    		}
    		else if(check_Redirection(commands_5)==true)
    		{
    			//redirection(commands_1);
    			printf("check_Redirection is true\n");
    		}
    		else
    		{
    			run1(commands[i]);
    		}
    		/*
    		no_of_flags_of_command=0;
    		flags_of_command[0]= strtok(commands[i]," \t\n");
    		while(flags_of_command[no_of_flags_of_command] != NULL)
    		{
    			no_of_flags_of_command++;
    			flags_of_command[no_of_flags_of_command]=strtok(NULL," \t\n");
    		}
    		if(no_of_flags_of_command < 1)
    		{
    			continue;
    		}
    		else if(strcmp(flags_of_command[0],"cd")==0)
    		{
    			cd(flags_of_command,new_Path,home_Directory_Path,absolute_Directory_Path,Previous_Working_Directory,Current_Working_Directory,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"echo")==0)
    		{
    			
    			echo(flags_of_command,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"pwd")==0)
    		{
    			pwd(flags_of_command,pwd_Path, no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"ls")==0)
    		{
    			ls(flags_of_command,home_Directory_Path,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"pinfo")==0)
    		{
    			pinfo(flags_of_command,home_Directory_Path,no_of_flags_of_command);
    		}
    		else if(strcmp(flags_of_command[0],"repeat")==0)
    		{

    		}
    		else
    		{
    			
    		}
    		*/
    	}

	}
}



int main(int argc, char const *argv[])
{
	basic_Display_Find();
	home_Directory_Finder();
	while(1)
		run();
	//printf("%s\n",home_Directory_path);
	return 0;
}