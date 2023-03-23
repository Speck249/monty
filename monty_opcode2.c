#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
*monty_add - Adds top two elements of linked list.
*@stack: first parameter
*@line_number: second parameter
*Return: no return value
*/
void monty_add(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tok_err(short_stack_err(line_number, "add"));
return;
}
(*stack)->next->next->n += (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
*monty_sub - Subtracts second elements from top of linked list.
*@stack: first parameter
*@line_number: second parameter
*Return: no return value
*/
void monty_sub(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tok_err(short_stack_err(line_number, "sub"));
return;
}
(*stack)->next->next->n -= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
*monty_div - Divides second elements from top of linked list.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value
*/
void monty_div(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tok_err(short_stack_err(line_number, "div"));
return;
}
if ((*stack)->next->n == 0)
{
set_opcode_tok_err(div_err(line_number));
return;
}
(*stack)->next->next->n /= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
*monty_mul - Multiplies second elements from top of linked list.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value
*/
void monty_mul(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tok_err(short_stack_err(line_number, "mul"));
return;
}
(*stack)->next->next->n *= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
*monty_mod - Finds modulus of second elements from top of linked list.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value.
*/
void monty_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tok_err(short_stack_err(line_number, "mod"));
return;
}
if ((*stack)->next->n == 0)
{
set_opcode_tok_err(div_err(line_number));
return;
}
(*stack)->next->next->n %= (*stack)->next->n;
monty_pop(stack, line_number);
}
