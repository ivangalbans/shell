#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../include/parser.h"

#define register_size 51
#define buffer_size 1024

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
		
		parse_command(buffer, size, cmd);
		
}

int execute_process(command *cmd)
{
	int i;
	pid_t pid;
	int fdpipe[2], infile, outfile;

	for(i=0;i<cmd->_no_simple_commands;i++)
	{
		outfile=get_outfile(&cmd->_simple_commands[i]);
		if(i!=cmd->_no_simple_commands-1)
		{
			pipe(fdpipe);
			if(outfile==STDOUT_FILENO)
				outfile=fdpipe[1];
			else
				close(fdpipe[1]);
		}

		int asd = builtin_command(&cmd->_simple_commands[i],outfile);
		if(asd==2)
			return 2;
		if(!asd)
		{
			pid=fork();
			int status;
			if(pid==0)
			{
				exec_command(&cmd->_simple_commands[i],infile,outfile);
			}
		}
		if(infile!=get_infile(&cmd->_simple_commands[i]))
			close(infile);
		if(outfile!=get_outfile(&cmd->_simple_commands[i]))
			close(outfile);
		infile=get_infile(&cmd->_simple_commands[i]);
		if(infile==STDIN_FILENO)
			infile=fdpipe[0];
		else 
			close(fdpipe[0]);
	}
	
	if(!cmd->_background)
	{
		int status;
		waitpid(pid,&status,0);
	}
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