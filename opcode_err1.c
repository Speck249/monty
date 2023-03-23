#include "monty.h"
/**
* usage_err - Prints error messages.
* Return: (EXIT_FAILURE) always.
*/
int usage_err(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
*malloc_err - Prints error messages.
*Return: (EXIT_FAILURE) always.
*/
int malloc_err(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}

/**
*f_open_err - Prints error messages.
*@filename: parameter
*Return: (EXIT_FAILURE) always.
*/
int f_open_err(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

/**
*unknown_op_err - Prints error messages.
*@opcode: first parameter.
*@line_number: second parameter.
*Return: (EXIT_FAILURE) always.
*/
int unknown_op_err(char *opcode, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n",
line_number, opcode);
return (EXIT_FAILURE);
}

/**
*no_int_err - Prints error messages.
*@line_number: parameter.
*Return: (EXIT_FAILURE) always.
*/
int no_int_err(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
