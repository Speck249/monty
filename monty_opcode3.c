#include "monty.h"
/**
*monty_pop - function removes top of stack
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_pop(stack_t **head, unsigned int i)
{
stack_t *h;
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
*head = h->next;
free(h);
}

/**
*monty_pint - function prints top of stack
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_pint(stack_t **head, unsigned int i)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

/**
*monty_nop - function doesn't do anything
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_nop(stack_t **head, unsigned int i)
{
(void) i;
(void) head;
}
