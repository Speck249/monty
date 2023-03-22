#include "monty.h"
/**
*monty_add - function adds top two elements of stack
*@head: first parameter
*@i: second parameter
*Return: returns no value
*/

void monty_add(stack_t **head, unsigned int i)
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
fprintf(stderr, "L%d: can't add, stack too short\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
temp = h->n + h->next->n;
h->next->n = temp;
*head = h->next;
free(h);
}

/**
*monty_sub - function substract node
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_sub(stack_t **head, unsigned int i)
{
stack_t *temp;
int sub, j;

temp = *head;
for (j = 0; temp != NULL; j++)
temp = temp->next;
if (j < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = *head;
sub = temp->next->n - temp->n;
temp->next->n = sub;
*head = temp->next;
free(temp);
}

/**
*monty_mul - function multiplies top two stack elements
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_mul(stack_t **head, unsigned int i)
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
fprintf(stderr, "L%d: can't mul, stack too short\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
temp = h->next->n * h->n;
h->next->n = temp;
*head = h->next;
free(h);
}

/**
*monty_div - function divides top two stack elements
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_div(stack_t **head, unsigned int i)
{
stack_t *h;
int l = 0, temp;

h = *head;
while (h)
{
h = h->next;
l++;
}
if (length < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = h->next->n / h->n;
h->next->n = temp;
*head = h->next;
free(h);
}

/**
*monty_mod - function finds remainder
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_mod(stack_t **head, unsigned int i)
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
fprintf(stderr, "L%d: can't mod, stack too short\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = h->next->n % h->n;
h->next->n = temp;
*head = h->next;
free(h);
}
