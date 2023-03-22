#include "monty.h"
/**
*monty_pstr - function prints string
*@head: first parameter
*@i: second parameter
*Return: returns no value
*/

void monty_pstr(stack_t **head, unsigned int i)
{
stack_t *h;
(void)i;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
putchar('\n');
}
