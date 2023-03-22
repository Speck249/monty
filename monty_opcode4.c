#include "monty.h"
/**
*monty_pall - function prints stack
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_pall(stack_t **head, unsigned int i)
{
stack_t *h;
(void)i;

h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}

/**
*monty_swap - function swaps top two stack elements
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_swap(stack_t **head, unsigned int i)
{
stack_t *h;
int l = 0, temp;

h = *head;
while (h)
{
h = h->next;
l++;
}
if (l < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
temp = h->n;
h->n = h->next->n;
h->next->n = temp;
}
