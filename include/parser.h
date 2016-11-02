#define t_input 1
#define t_output_write 2
#define t_output_append 3
#define t_command 4


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


//count how many times a chararacter c divide a string str
int counter(char *str,char c);

char *str_global;
char* next_token(char *str,int *type);

int parse_simplecommand(char *str, simple_command *scommand);

int parse_command(char *str,int size,command *ccommand);