#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
*monty_rotl - Rotates top value of linked list to bottom.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value
*/
void monty_rotl(stack_t **stack, unsigned int line_number)
{
stack_t *top, *bottom;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (*stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;

top->next->prev = *stack;
(*stack)->next = top->next;
bottom->next = top;
top->next = NULL;
top->prev = bottom;

(void)line_number;
}

/**
*monty_rotr - Rotates bottom element of linked list to top.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value
*/
void monty_rotr(stack_t **stack, unsigned int line_number)
{
stack_t *top, *bottom;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (*stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;

bottom->prev->next = NULL;
(*stack)->next = bottom;
bottom->prev = *stack;
bottom->next = top;
top->prev = bottom;

(void)line_number;
}

/**
*monty_stack - Converts queue to stack.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value
*/
void monty_stack(stack_t **stack, unsigned int line_number)
{
(*stack)->n = STACK;
(void)line_number;
}

/**
*monty_queue - Converts stack to queue.
*@stack: first parameter.
*@line_number: second parameter.
*Return: no return value
*/
void monty_queue(stack_t **stack, unsigned int line_number)
{
(*stack)->n = QUEUE;
(void)line_number;
}
