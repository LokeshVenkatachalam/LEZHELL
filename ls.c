#include "headers.h"

void lsd(char *input_Directory,char *home_Directory_Path,int count)
{
	char input_Directory_Path[100000];
	if(input_Directory[0]=='~')
	{
		strcpy(input_Directory_Path,home_Directory_Path);
	}
	else
	{
		strcpy(input_Directory_Path,input_Directory);;
	}
	struct dirent **read;
	ll ct=scandir(input_Directory_Path,&read,NULL,alphasort);
	if(ct<0)
	{
		FILE *file;
		if((file=fopen(input_Directory_Path,"r"))!= NULL )
		{
			fclose(file);
		}
		else
		{
			printf("ls: cannot access '%s': No such file or directory\n\n",input_Directory);
		}
	}
}
void ls0f(char *input_Directory,char *home_Directory_Path,int count)
{
	char input_Directory_Path[100000];
	if(input_Directory[0]=='~')
	{
		strcpy(input_Directory_Path,home_Directory_Path);
	}
	else
	{
		strcpy(input_Directory_Path,input_Directory);
	}
	struct dirent **read;
	ll ct=scandir(input_Directory_Path,&read,NULL,alphasort);
	if(ct<0)
	{
		FILE *file;
		if(file=fopen(input_Directory_Path,"r"))
		{
			printf("%s\n\n",input_Directory_Path);
			fclose(file);
		}
	}
}
void ls0(char *input_Directory,char *home_Directory_Path,int count)
{
	char input_Directory_Path[100000];
	if(input_Directory[0]=='~')
	{
		strcpy(input_Directory_Path,home_Directory_Path);
	}
	else
	{
		strcpy(input_Directory_Path,input_Directory);
	}

	struct dirent **read;
	ll ct=scandir(input_Directory_Path,&read,NULL,alphasort);
	ll x=0;
	if(ct<0)
	{

	}
	else
	{
		if(count>1)
		{
			printf("%s:\n",input_Directory_Path);
		}
		while(x<ct)
		{
			char string1[100000];
			strcpy(string1,read[x]->d_name);
			x++;
			if(string1[0]=='.')
			{
				continue;
			}
			else
			{
				printf("%s\n",string1);
			}
		}
		printf("\n");
	}
}

void lsa(char *input_Directory,char *home_Directory_Path,int count)
{
	char input_Directory_Path[100000];
	if(input_Directory[0]=='~')
	{
		strcpy(input_Directory_Path,home_Directory_Path);
	}
	else
	{
		strcpy(input_Directory_Path,input_Directory);
	}
	struct dirent **read;
	ll ct=scandir(input_Directory_Path,&read,NULL,alphasort);
	ll x=0;
	if(ct<0)
	{
		
	}
	else
	{
		if(count>1)
		{
			printf("%s:\n",input_Directory_Path);
		}
		while(x<ct)
		{
			char string1[100000];
			strcpy(string1,read[x]->d_name);
			x++;
			printf("%s\n",string1);
		}
		printf("\n");
	}
}
void lslf(char *input_Directory,char *home_Directory_Path,int count)
{
	char input_Directory_Path[100000];
	if(input_Directory[0]=='~')
	{
		strcpy(input_Directory_Path,home_Directory_Path);
	}
	else
	{
		strcpy(input_Directory_Path,input_Directory);
	}
	struct dirent **read;
	ll ct=scandir(input_Directory_Path,&read,NULL,alphasort);
	if(ct<0)
	{
		FILE *file;
		struct stat stat1;
		ll hardlinks, size;
		char date[30];
		if(file=fopen(input_Directory_Path,"r"))
		{
			char file_path[100000];
			strcpy(file_path,input_Directory_Path);
			stat(file_path,&stat1);
			hardlinks = stat1.st_nlink;
            struct passwd *pd;
            pd = getpwuid(stat1.st_uid);
            struct group *gr;
            gr = getgrgid(stat1.st_gid);

            size = stat1.st_size;
            char per[12];
            strcpy(per ,"----------");
            if (S_ISDIR(stat1.st_mode))
            {
            	per[0]='d';
            }
            if (stat1.st_mode & S_IRUSR)
            {
            	per[1]='r';
            }
            if(stat1.st_mode & S_IWUSR)
            {
            	per[2]='w';
            }
            if(stat1.st_mode & S_IXUSR)
            {
            	per[3]='x';
            }
            if(stat1.st_mode & S_IRGRP)
            {
            	per[4]='r';
            }
            if(stat1.st_mode & S_IWGRP)
            {
            	per[5]='w';
            }
            if(stat1.st_mode & S_IXGRP)
            {
            	per[6]='x';
            }
            if(stat1.st_mode & S_IROTH)
            {
            	per[7]='r';
            }
            if(stat1.st_mode & S_IWOTH)
            {
            	per[8]='w';
            }
            if(stat1.st_mode & S_IXOTH)
            {
            	per[9]='x';
            }
            strftime(date, 24, "%Y-%m-%d    %H:%M", localtime(&(stat1.st_ctime)));
            printf("%-12s%-6lld%-8s%-8s%-8lld%-24s%-20s\n", per, hardlinks, pd->pw_name, gr->gr_name, size, date, file_path);
		}
	}		

}
void lsl(char *input_Directory,char *home_Directory_Path,int count)
{
	char input_Directory_Path[100000];
	if(input_Directory[0]=='~')
	{
		strcpy(input_Directory_Path,home_Directory_Path);
	}
	else
	{
		strcpy(input_Directory_Path,input_Directory);
	}
	struct dirent **read;
	ll ct=scandir(input_Directory_Path,&read,NULL,alphasort);
	if(ct<0)
	{

	}
	else
	{
		ll x=0;
		ll x1=0;
		ll Total=0;
		if(count>1)
		{
			printf("%s:\n",input_Directory_Path);
		}
		while(x1<ct)
		{
			char file_path[100000];
			strcpy(file_path,input_Directory_Path);
			strcat(file_path,"/");
			strcat(file_path,read[x1]->d_name);
			struct stat stat2;
			char string1[100000];
			strcpy(string1,read[x1]->d_name);
			x1++;
			if(string1[0]=='.')
			{
				continue;
			}
			stat(file_path,&stat2);
			Total+=stat2.st_blocks;
		}
		printf("total %lld\n",Total/2);
		while(x<ct)
		{
			
			struct stat stat1,stat3;
			ll hardlinks, size;
			char date[30];
			char file_path[100000];
			strcpy(file_path,input_Directory_Path);
			strcat(file_path,"/");
			strcat(file_path,read[x]->d_name);
			char string1[100000];
			strcpy(string1,read[x]->d_name);
			x++;
			if(string1[0]=='.')
			{
				continue;
			}
			
			stat(file_path,&stat1);
			hardlinks = stat1.st_nlink;
            struct passwd *pd;
            pd = getpwuid(stat1.st_uid);
            struct group *gr;
            gr = getgrgid(stat1.st_gid);

            size = stat1.st_size;
            char per[12];
            strcpy(per ,"----------");
            if (S_ISDIR(stat1.st_mode))
            {
            	per[0]='d';
            }
            if (stat1.st_mode & S_IRUSR)
            {
            	per[1]='r';
            }
            if(stat1.st_mode & S_IWUSR)
            {
            	per[2]='w';
            }
            if(stat1.st_mode & S_IXUSR)
            {
            	per[3]='x';
            }
            if(stat1.st_mode & S_IRGRP)
            {
            	per[4]='r';
            }
            if(stat1.st_mode & S_IWGRP)
            {
            	per[5]='w';
            }
            if(stat1.st_mode & S_IXGRP)
            {
            	per[6]='x';
            }
            if(stat1.st_mode & S_IROTH)
            {
            	per[7]='r';
            }
            if(stat1.st_mode & S_IWOTH)
            {
            	per[8]='w';
            }
            if(stat1.st_mode & S_IXOTH)
            {
            	per[9]='x';
            }
            stat3=stat1;
            time_t current_sec = time(NULL);
            time_t file_sec = time(&stat3.st_ctime);
            if((current_sec-file_sec)<15552000)
            {
            	strftime(date, 24, "%b %d    %H:%M ", localtime(&(stat1.st_ctime)));
            }
            else
            {
            	strftime(date, 24, "%b %d    %Y  ", localtime(&(stat1.st_ctime)));
            }
            
            printf("%-12s%-6lld%-8s%-8s%-8lld%-24s%-20s\n", per, hardlinks, pd->pw_name, gr->gr_name, size, date, string1);
		}
		printf("\n");
		
	}
}
void lsla(char *input_Directory,char *home_Directory_Path,int count)
{
	char input_Directory_Path[100000];
	if(input_Directory[0]=='~')
	{
		strcpy(input_Directory_Path,home_Directory_Path);
	}
	else
	{
		strcpy(input_Directory_Path,input_Directory);
	}
	struct dirent **read;
	ll ct=scandir(input_Directory_Path,&read,NULL,alphasort);
	if(ct<0)
	{
		
	}
	else
	{
		ll x=0;
		ll x1=0;
		ll Total=0;
		if(count>1)
		{
			printf("%s:\n",input_Directory_Path);
		}
		while(x1<ct)
		{
			char file_path[100000];
			strcpy(file_path,input_Directory_Path);
			strcat(file_path,"/");
			strcat(file_path,read[x1]->d_name);
			x1++;
			struct stat stat2;
			stat(file_path,&stat2);
			Total+=stat2.st_blocks;
		}
		printf("total %lld\n",Total/2);
		while(x<ct)
		{
			
			struct stat stat1,stat3;
			ll hardlinks, size;
			char date[30];
			char file_path[100000];
			strcpy(file_path,input_Directory_Path);
			strcat(file_path,"/");
			strcat(file_path,read[x]->d_name);
			char string1[100000];
			strcpy(string1,read[x]->d_name);
			x++;
			stat(file_path,&stat1);
			hardlinks = stat1.st_nlink;
            struct passwd *pd;
            pd = getpwuid(stat1.st_uid);
            struct group *gr;
            gr = getgrgid(stat1.st_gid);

            size = stat1.st_size;
            char per[12];
            strcpy(per ,"----------");
            if (S_ISDIR(stat1.st_mode))
            {
            	per[0]='d';
            }
            if (stat1.st_mode & S_IRUSR)
            {
            	per[1]='r';
            }
            if(stat1.st_mode & S_IWUSR)
            {
            	per[2]='w';
            }
            if(stat1.st_mode & S_IXUSR)
            {
            	per[3]='x';
            }
            if(stat1.st_mode & S_IRGRP)
            {
            	per[4]='r';
            }
            if(stat1.st_mode & S_IWGRP)
            {
            	per[5]='w';
            }
            if(stat1.st_mode & S_IXGRP)
            {
            	per[6]='x';
            }
            if(stat1.st_mode & S_IROTH)
            {
            	per[7]='r';
            }
            if(stat1.st_mode & S_IWOTH)
            {
            	per[8]='w';
            }
            if(stat1.st_mode & S_IXOTH)
            {
            	per[9]='x';
            }
            stat3=stat1;
            
            time_t current_sec = time(NULL);
            time_t file_sec = time(&stat3.st_ctime);
            if((current_sec-file_sec)<15552000)
            {
            	strftime(date, 24, "%b %d    %H:%M ", localtime(&(stat1.st_ctime)));
            }
            else
            {
            	strftime(date, 24, "%b %d    %Y    ", localtime(&(stat1.st_ctime)));
            }
            printf("%-12s%-6lld%-8s%-8s%-16lld%-24s%-20s\n", per, hardlinks, pd->pw_name, gr->gr_name, size, date, string1);
		}
		printf("\n");	
	}

}

void ls(char *flags_of_command[],char *home_Directory_Path,int no_of_flags_of_command)
{
	
	
	ll FLAG_A=0;
	ll FLAG_L=0;
	ll count_1=0;
	
	for(int i=1;i<no_of_flags_of_command;i++)
	{
		if(strcmp(flags_of_command[i],"-a")==0)
		{
			FLAG_A=1;
		}
		else if(strcmp(flags_of_command[i],"-l")==0)
		{
			FLAG_L=1;
		}
		else if(strcmp(flags_of_command[i],"-al")==0)
		{
			FLAG_A=1;
			FLAG_L=1;
		}
		else if(strcmp(flags_of_command[i],"-la")==0)
		{
			FLAG_A=1;
			FLAG_L=1;
		}
		else
		{
			count_1++;
		}
	}
	if(count_1 == 0)
	{
		//strcpy(flags_of_command[no_of_flags_of_command],"");
		//strcpy(flags_of_command[no_of_flags_of_command+1],NULL);
		//no_of_flags_of_command++;
		
	}
	for(int i=1;i<no_of_flags_of_command;i++)
	{
		if((strcmp(flags_of_command[i],"-a")!=0)&&(strcmp(flags_of_command[i],"-l")!=0)&&(strcmp(flags_of_command[i],"-al")!=0)&&(strcmp(flags_of_command[i],"-la")!=0))
		{	
			lsd(flags_of_command[i],home_Directory_Path,count_1);	
		}
	}
	for(int i=1;i<no_of_flags_of_command;i++)
	{
		if((strcmp(flags_of_command[i],"-a")!=0)&&(strcmp(flags_of_command[i],"-l")!=0)&&(strcmp(flags_of_command[i],"-al")!=0)&&(strcmp(flags_of_command[i],"-la")!=0))
		{
			if(FLAG_L==1)
			{
				lslf(flags_of_command[i],home_Directory_Path,count_1);
			}
			else 
			{
				ls0f(flags_of_command[i],home_Directory_Path,count_1);
			}
		}
	}
	for(int i=1;i<no_of_flags_of_command;i++)
	{
		if((strcmp(flags_of_command[i],"-a")!=0)&&(strcmp(flags_of_command[i],"-l")!=0)&&(strcmp(flags_of_command[i],"-al")!=0)&&(strcmp(flags_of_command[i],"-la")!=0))
		{
			if((FLAG_L==1)&&(FLAG_A==1))
			{
				lsla(flags_of_command[i],home_Directory_Path,count_1);
			}
			else if(FLAG_A==1)
			{
				lsa(flags_of_command[i],home_Directory_Path,count_1);
			}
			else if(FLAG_L==1)
			{
				lsl(flags_of_command[i],home_Directory_Path,count_1);
			}
			else
			{
				ls0(flags_of_command[i],home_Directory_Path,count_1);
			}
		}
	}
	if(count_1==0)
	{
			count_1++;
			if((FLAG_L==1)&&(FLAG_A==1))
			{
				lsla(".",home_Directory_Path,count_1);
			}
			else if(FLAG_A==1)
			{
				lsa(".",home_Directory_Path,count_1);
			}
			else if(FLAG_L==1)
			{
				lsl(".",home_Directory_Path,count_1);
			}
			else
			{
				ls0(".",home_Directory_Path,count_1);
			}
	}
}
