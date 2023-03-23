#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
*main - entry point
*@argc: first parameter
*@argv: second parameter
*Return: (EXIT_SUCCESS) for success, (EXIT_FAILURE) for error
*/
int main(int argc, char **argv)
{
FILE *script_fd = NULL;
int exit_code = EXIT_SUCCESS;

if (argc != 2)
return (usage_err());
script_fd = fopen(argv[1], "r");
if (script_fd == NULL)
return (f_open_err(argv[1]));
exit_code = exec_monty(script_fd);
fclose(script_fd);
return (exit_code);
}
