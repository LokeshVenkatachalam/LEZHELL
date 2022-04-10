#include "headers.h"

void echo(char *flags_of_command[],int no_of_flags_of_command)
{
	for(int i=1;i<no_of_flags_of_command;i++)
	{
		printf("%s",flags_of_command[i]);
	}
	printf("\n");
}