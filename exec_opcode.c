#include "monty.h"

void free_tok(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_opcode_func(char *opcode))(stack_t**, unsigned int);
int exec_monty(FILE *script_fd);

/**
*free_tok - Frees global op_toks array.
*Return: no return value
*/
void free_tok(void)
{
size_t i = 0;
if (op_toks == NULL)
return;

for (i = 0; op_toks[i]; i++)
free(op_toks[i]);
free(op_toks);
}

/**
*token_arr_len - gets length of current op_toks.
*Return: Len of current op_toks.
*/
unsigned int token_arr_len(void)
{
unsigned int toks_len = 0;
while (op_toks[toks_len])
toks_len++;
return (toks_len);
}

/**
*is_empty_line - Checks for delimiters.
*@line: first parameter
*@delims: second parameter
*Return: 1 for delimiters, 0 Otherwise.
*/
int is_empty_line(char *line, char *delims)
{
int i, j;

for (i = 0; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
break;
}
if (delims[j] == '\0')
return (0);
}
return (1);
}

/**
*get_opcode_func - Matches an opcode with corresponding function.
*@opcode: parameter
*Return: pointer to function.
*/
void (*get_opcode_func(char *opcode))(stack_t**, unsigned int)
{
instruction_t op_funcs[] = {
	{"push", monty_push},
	{"pall", monty_pall},
	{"pint", monty_pint},
	{"pop", monty_pop},
	{"swap", monty_swap},
	{"add", monty_add},
	{"nop", monty_nop},
	{"sub", monty_sub},
	{"div", monty_div},
	{"mul", monty_mul},
	{"mod", monty_mod},
	{"pchar", monty_pchar},
	{"pstr", monty_pstr},
	{"rotl", monty_rotl},
	{"rotr", monty_rotr},
	{"stack", monty_stack},
	{"queue", monty_queue},
	{NULL, NULL}
	};
int i;
for (i = 0; op_funcs[i].opcode; i++)
{
if (strcmp(opcode, op_funcs[i].opcode) == 0)
return (op_funcs[i].f);
}
return (NULL);
}

/**
*exec_monty - runs Monty bytecodes script.
*@script_fd: parameter.
*Return: EXIT_SUCCESS for success.
*/
int exec_monty(FILE *script_fd)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0, exit_status = EXIT_SUCCESS;
unsigned int line_number = 0, prev_tok_len = 0;
void (*op_func)(stack_t**, unsigned int);

if (init_stack(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);

while (getline(&line, &len, script_fd) != -1)
{
line_number++;
op_toks = strtow(line, DELIMS);
if (op_toks == NULL)
{
if (is_empty_line(line, DELIMS))
continue;
free_stack(&stack);
return (malloc_err());
}
else if (op_toks[0][0] == '#')
{
free_tok();
continue;
}
op_func = get_opcode_func(op_toks[0]);
if (op_func == NULL)
{
free_stack(&stack);
exit_status = unknown_op_err(op_toks[0], line_number);
free_tok();
break;
}
prev_tok_len = token_arr_len();
op_func(&stack, line_number);
if (token_arr_len() != prev_tok_len)
{
if (op_toks && op_toks[prev_tok_len])
exit_status = atoi(op_toks[prev_tok_len]);
else
exit_status = EXIT_FAILURE;
free_tok();
break;
}
free_tok();
}
free_stack(&stack);

if (line && *line == 0)
{
free(line);
return (malloc_err());
}

free(line);
return (exit_status);
}
