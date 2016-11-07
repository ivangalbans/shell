#include "../src/parser.c"


//count how many times a chararacter c divide a string str
int counter(char *, char);

char* next_token(char *, int *);

int parse_simplecommand(char *, simple_command *);

int parse_command(char *, int, command *);
