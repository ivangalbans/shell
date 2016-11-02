#include "../include/parser.h"


int parse_command(char *str,int size,command *ccommand)
{
	ccommand->_background=0;
	
	size-=2;
		
	while(str[size]==' ')
	{
		--size;

	}
	if(str[size]=='&')
		ccommand->_background=1;
	else
		++size;	
	str[size]=0;

	

	ccommand->_no_simple_commands=counter(str,'|');
	

	if(ccommand->_no_simple_commands>0)
	{
		ccommand->_simple_commands=(simple_command*)malloc( ccommand->_no_simple_commands * sizeof ( simple_command ) );

		char *saveptr;	

		char *token = strtok_r(str,"|",&saveptr);
		
		for (int i = 0; token!= NULL; ++i)
		{   
			parse_simplecommand(token,&ccommand->_simple_commands[i]);
			
			token=strtok_r(NULL,"|",&saveptr);
		}
	}

	return 0;
}
