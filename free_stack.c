#include "monty.h"
/**
*free_stack - function frees doubly linked list
*@head: parameter
*Return: no return value
*/

void free_stack(stack_t *head)
{
stack_t *temp;

temp = head;

while (head)
{
temp = head->next;
free(head);
head = temp;
}
}

/**
*monty_stack - function prints top of stack
*@head: first parameter
*@i: second parameter
*Return: no return value
*/

void monty_stack(stack_t **head, unsigned int i)
{
(void)head;
(void)i;
bus.lifi = 0;
}
