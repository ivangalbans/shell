#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../include/parser.h"

# define register_size 51
# define buffer_size 1024

char register_buffer[register_size][buffer_size];

int register_buffer_size[register_size];

int start_register=0;

int end_register=0;

const char *endl="\n";

int write_prompt()
{
		char path[1024],*logname,user[64],*p1="@",*p2=":",*p3="$ ";
		getcwd(path,1024);
		logname = getenv("LOGNAME");
		gethostname(user,64);
		write(STDIN_FILENO,logname,strlen(logname));
		write(STDIN_FILENO,p1,strlen(p1));
		write(STDIN_FILENO,user,strlen(user));
		write(STDIN_FILENO,p2,strlen(p2));
		write(STDIN_FILENO,path,strlen(path));
		write(STDIN_FILENO,p3,strlen(p3));
}

void read_command(command *cmd)
{
	 	char buffer[buffer_size];
		int size=read(STDIN_FILENO,buffer, buffer_size);
		

		if(buffer[0]!=' ')
		{
			register_buffer_size[end_register]=size;
			strncpy(register_buffer[end_register],buffer,size);
			end_register=(end_register+1)%register_size;
		}

		if(end_register==start_register)
			start_register=(start_register+1)%register_size;	
		
		parse_command(buffer,size,cmd);
}

int main()
{
	char *logname = getenv("LOGNAME");
	char home[] = "/home/";
	chdir(strcat(home, logname));
	
	while(1)
	{
		write_prompt();
		command cmd;
		read_command(&cmd);

	}

	return 0;
}