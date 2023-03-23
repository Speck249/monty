#include "monty.h"
/**
*pop_err - Prints pop error messages for empty stacks.
*@line_number: parameter.
*Return: (EXIT_FAILURE) always.
*/
int pop_err(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
*pint_err - Prints error messages.
*@line_number: parameter.
*Return: (EXIT_FAILURE) always.
*/
int pint_err(unsigned int line_number)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
*short_stack_err - Prints error messages.
*@line_number: first parameter.
*@op: second parameter.
*Return: (EXIT_FAILURE) always.
*/
int short_stack_err(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}

/**
*div_err - Prints error messages.
*@line_number: parameter.
*Return: (EXIT_FAILURE) always.
*/
int div_err(unsigned int line_number)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
return (EXIT_FAILURE);
}

/**
*pchar_err - Prints error messages.
*@line_number: first parameter.
*@message: second parameter.
*Return: (EXIT_FAILURE) always.
*/
int pchar_err(unsigned int line_number, char *message)
{
fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
return (EXIT_FAILURE);
}
