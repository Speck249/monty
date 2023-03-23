#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
*monty_nop - Doesn't do anything.
*@stack: first parameter
*@line_number: second parameter
*Return: no return value
*/
void monty_nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
*monty_pchar - Prints character in the top value node of linked list.
*@stack: first parameter
*@line_number: second parameter
*Return: no return value
*/
void monty_pchar(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
set_opcode_tok_err(pchar_err(line_number, "stack empty"));
return;
}
if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
{
set_opcode_tok_err(pchar_err(line_number,
"value out of range"));
return;
}
printf("%c\n", (*stack)->next->n);
}

/**
*monty_pstr - Prints string inside linked list.
*@stack: first parameter.
*@line_number: second parameter
*Return: no return value
*/
void monty_pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;
while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
{
printf("%c", tmp->n);
tmp = tmp->next;
}
putchar('\n');

(void)line_number;
}
