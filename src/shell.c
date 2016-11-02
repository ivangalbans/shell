#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../include/parser.h"

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

int main()
{
	char *logname = getenv("LOGNAME");
	char home[] = "/home/";
	chdir(strcat(home, logname));
	
	while(1)
	{
		write_prompt();
	}

	return 0;
}