#include "monty.h"
#include <string.h>
/**
*free_stack - Frees a stack.
*@stack: parameter
*Return: no return value
*/
void free_stack(stack_t **stack)
{
stack_t *tmp = *stack;

while (*stack)
{
tmp = (*stack)->next;
free(*stack);
*stack = tmp;
}
}

/**
* init_stack - Initializes a stack.
* @stack: parameter
* Return: EXIT_FAILURE for error, otherwise EXIT_SUCCESS.
*/
int init_stack(stack_t **stack)
{
stack_t *s;

s = malloc(sizeof(stack_t));
if (s == NULL)
if (s == NULL)
return (malloc_err());

s->n = STACK;
s->prev = NULL;
s->next = NULL;
*stack = s;
return (EXIT_SUCCESS);
}

/**
*check_mode - Checks if linked list is in stack or queue mode.
*@stack: paramter
*Return: 0 for Stack, 1 for Queue or 2 otherwise
*/
int check_mode(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (2);
}
