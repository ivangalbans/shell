#include "../include/parser.h"


//count how many times a chararacter c divide a string str
int counter(char *str,char c)
{
	
	int counter=1;
	
	char *tmp=str;
	

	//not count firsts characters equals to c
	while(*tmp==c)
		++tmp;

	//verify if the line if a line is formed only by c characters
	if(*tmp==0)
		return 0;

	//cout the the number of characters equals to c
	for (; *tmp ; ++tmp)
	{
		if (*tmp==c)
		{
			++counter;
		}

		//not count consecutive character equals to c
		while(*tmp==c)
			++tmp;

		//not count lasts character equals to c
		if(*tmp==0)
		{
			--counter;
			--tmp;
		}
	}
	return counter;
}


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
