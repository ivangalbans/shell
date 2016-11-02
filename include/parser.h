//describe a simple commad and arguments
typedef struct
{
	char *_file;
	int _type;
} output_file;

typedef struct
{ 		
	//array of arguments
	char ** _tokens;
	 	
	//number of arguments
	int _no_tokens;

	output_file *_outfiles;
	
	int _no_infiles;
	
	char **_infiles;
	
	int _no_outfiles;

} simple_command;


typedef struct
{
	//list of simple commands
	simple_command *_simple_commands;
 
	//number of simple commands
	int _no_simple_commands;

	//the process would be in background
	int _background;

} command;


