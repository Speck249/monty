#include "monty.h"
/**
*exec_opcode - function implements opcode
*@stack: first parameter
*@i: second parameter
*@file: third parameter
*@content: fourth parameter
*Return: no return value
*/
int exec_opcode(char *content, stack_t **stack, unsigned int i, FILE *file)
{
instruction_t opst[] = {
            {"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
            {"pop", monty_pop},
            {"swap", monty_swap},
            {"add", monty_add},
            {"nop", monty_nop},
            {"sub", monty_sub},
            {"div", monty_div},
            {"mul", monty_mul},
            {"mod", monty_mod},
            {"queue", monty_queue},
            {"stack", monty_stack},
            {NULL, NULL}
            };

unsigned int j = 0;
char *op;

op = strtok(content, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[j].opcode) == 0)
{
opst[j].f(stack, i);
return (0);
}
j++;
}

if (op && opst[j].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", i, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
