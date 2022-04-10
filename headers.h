#ifndef HEADERS_H_
#define HEADERS_H_
#include "stdio.h"
#include "math.h"
#include "sys/utsname.h"
#include "string.h"
#include "unistd.h"
#include "pwd.h"
#include "dirent.h"
#include "grp.h"
#include "time.h"
#include "sys/stat.h"
#include "stdlib.h"
#include "fcntl.h"  
#include "stdbool.h"
#include "sys/wait.h"
#include "signal.h"
typedef long long ll;


typedef struct jobs{
    char name[500];
    pid_t pid;
    char status[50];
    int exited;
};

extern int  no_of_Process_Created[1];

void echo(char *flags_of_command[],int no_of_flags_of_command);
void pwd(char *flags_of_command[],int no_of_flags_of_command);
void cd(char *flags_of_command[],char *new_Path,char *home_Directory_Path,char *absolute_Directory_Path,char *Previous_Working_Directory,char *Current_Working_Directory,int no_of_flags_of_command);
char * get_Relative_Path_1(char *path_1,char *home_Directory_Path);
//void pinfo(char *flags_of_command[],char *home_Directory_Path,int no_of_flags_of_command);
void lsd(char *input_Directory,char *home_Directory_Path,int count);
void ls0f(char *input_Directory,char *home_Directory_Path,int count);
void ls0(char *input_Directory,char *home_Directory_Path,int count);
void lsa(char *input_Directory,char *home_Directory_Path,int count);
void lslf(char *input_Directory,char *home_Directory_Path,int count);
void lsl(char *input_Directory,char *home_Directory_Path,int count);
void lsla(char *input_Directory,char *home_Directory_Path,int count);
void ls(char *flags_of_command[],char *home_Directory_Path,int no_of_flags_of_command);
void repeat(char *flags_of_command[],int no_of_flags_of_command);
void basic_Display_Find();
void get_Relative_Path();
void print_Lezhell_prompt();
void home_Directory_Finder();
void run1(char *commands_1);
void run();
bool pipe_Checking(char *command_1);
bool check_Redirection(char *command_1);
void functions(char **flags_of_command,int no_of_flags_of_command,struct jobs *background_Process_List);
void handler();
void jobs(char *flags_of_command[],struct jobs *background_Process_List, int no_of_flags_of_command);
void bg(char *flags_of_command[],struct jobs *background_Process_List,int no_of_flags_of_command);
void fg(char *flags_of_command[],struct jobs *background_Process_List,int no_of_flags_of_command);


#endif