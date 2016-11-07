#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/type.h"


#define t_input 1
#define t_output_write 2
#define t_output_append 3
#define t_command 4

char *str_global;



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


char* next_token(char *str,int *type)
{
	
	char *token;
	*type = t_command;
	
	if(str!=NULL)
	{
		str_global=str;
	} 
	
	while(*str_global==' ')
		++str_global;

	if(*str_global==0)
	{
		str_global=NULL;
		*type=0;
		return NULL;
	}
	
	

	switch (*str_global)
	{
		case '<':
		{
			*type=t_input;
			++str_global;
			break;
		}
		case '>':
		{ 
			*type=t_output_write;
			if(*(str_global+1)=='>')
			{
				*type=t_output_append;
				++str_global;
			}
			++str_global;
			break;
		}
	}	
	
	while(*str_global==' ')
		++str_global;

	char *current=str_global;
	
    while(*current!=' ' && *current!='<' && *current!='>' && *current!=0 )
	{
		++current;
	}

	
	int token_size=current-str_global;
	//printf("%d\n",token_size );
	token=(char*)malloc((token_size)*(sizeof(char)));
	strncpy(token,str_global,token_size);
	token[token_size]=0;
	str_global=current;
	return token;
}

int parse_simplecommand(char *str, simple_command *scommand)
{
	
	int i;
	int k;
	char *str_tmp=str;
	char *token;

	scommand->_no_tokens=0;
	scommand->_no_outfiles=0;
	scommand->_no_infiles=0;
	scommand->_outfiles=0;
	scommand->_infiles=0;
	scommand->_tokens=0;

	str_global=NULL;
	token=next_token(str_tmp,&k);
	while(token!=NULL)
	{
			
		switch (k)
		{
			case t_input:
			{
				++scommand->_no_infiles;
				break;
			}
			case t_output_append:
			case t_output_write:
			{
				++scommand->_no_outfiles;
				break;
			}
			case t_command:
			{
				++scommand->_no_tokens;
				break;
			}
		}		
		free(token);
		token=next_token(NULL,&k);
	}

	scommand->_outfiles=(output_file*)malloc(scommand->_no_outfiles*sizeof(output_file));
	scommand->_infiles=(char**)malloc(scommand->_no_infiles*sizeof(char*));
	scommand->_tokens=(char**)malloc(scommand->_no_tokens*sizeof(char*));
	for (i = 0; i < scommand->_no_tokens; ++i) scommand->_tokens[i]=0;
	for (i = 0; i < scommand->_no_infiles; ++i) scommand->_infiles[i]=0;
	for (i = 0; i < scommand->_no_outfiles; ++i)
	{
		scommand->_outfiles[i]._file=0;
		scommand->_outfiles[i]._type=0;
	}
	str_global=NULL;
	token=next_token(str,&k);
	int it_out=0, it_inf=0, it_tokens=0;
	while(token!=NULL)
	{
			
			switch (k)
			{
				case t_input:
				{
				
					scommand->_infiles[it_inf]=token;
					++it_inf;
					break;
					
				}
				case t_output_append:
				{
					
					scommand->_outfiles[it_out]._file=token;
					scommand->_outfiles[it_out]._type=t_output_append;
					++it_out;
					break;
				}
				case t_output_write:
				{
					
					scommand->_outfiles[it_out]._file=token;
					scommand->_outfiles[it_out]._type=t_output_write;
					break;
				}
				case t_command:
				{
					
					scommand->_tokens[it_tokens]=token;
					++it_tokens;
					break;
				}
			}
			
		token = next_token(NULL,&k);

	}
	scommand->_infiles[scommand->_no_infiles]=NULL;
	scommand->_outfiles[scommand->_no_outfiles]._file=NULL;
	scommand->_outfiles[scommand->_no_outfiles]._type=0;
	scommand->_tokens[scommand->_no_tokens]=NULL;

	return 0;

}


int parse_command(char *str,int size,command *ccommand)
{
	char *saveptr;
	char *token;
	int i;

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

		token = strtok_r(str,"|",&saveptr);
		
		for (i = 0; token!= NULL; ++i)
		{   
			parse_simplecommand(token,&ccommand->_simple_commands[i]);
			token=strtok_r(NULL,"|",&saveptr);
		}
	}

	return 0;
}
