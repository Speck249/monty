#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
*monty_push - Pushes value to linked list.
*@stack: first parameter
*@line_number: second parameter.
*Return: no return value
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *new;
int i;
new = malloc(sizeof(stack_t));
if (new == NULL)
{
set_opcode_tok_err(malloc_err());
return;
}
if (op_toks[1] == NULL)
{
set_opcode_tok_err(no_int_err(line_number));
return;
}
for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
continue;
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{
set_opcode_tok_err(no_int_err(line_number));
return;
}
}
new->n = atoi(op_toks[1]);
if (check_mode(*stack) == STACK)
{
tmp = (*stack)->next;
new->prev = *stack;
new->next = tmp;
if (tmp)
tmp->prev = new;
(*stack)->next = new;
}
else
{
tmp = *stack;
while (tmp->next)
tmp = tmp->next;
new->prev = tmp;
new->next = NULL;
tmp->next = new;
}
}

/**
*monty_pall - Prints values of linked list.
*@stack: first parameter
*@line_number: second parameter
*Return: no return value
*/
void monty_pall(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;
while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
(void)line_number;
}

/**
*monty_pint - Prints top value of linked list.
*@stack: first parameter.
*@line_number: second parameter
*Return: no return value
*/
void monty_pint(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
set_opcode_tok_err(pint_err(line_number));
return;
}
printf("%d\n", (*stack)->next->n);
}

/**
*monty_pop - Removes top element of linked list.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value
*/
void monty_pop(stack_t **stack, unsigned int line_number)
{
stack_t *next = NULL;
if ((*stack)->next == NULL)
{
set_opcode_tok_err(pop_err(line_number));
return;
}
next = (*stack)->next->next;
free((*stack)->next);
if (next)
next->prev = *stack;
(*stack)->next = next;
}

/**
*monty_swap - Swaps top two elements of linked list.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value.
*/
void monty_swap(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tok_err(short_stack_err(line_number, "swap"));
return;
}
tmp = (*stack)->next->next;
(*stack)->next->next = tmp->next;
(*stack)->next->prev = tmp;
if (tmp->next)
tmp->next->prev = (*stack)->next;
tmp->next = (*stack)->next;
tmp->prev = *stack;
(*stack)->next = tmp;
}
