#include "monty.h"
/**
*monty_queue - function prints top of queue
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_queue(stack_t **head, unsigned int i)
{
(void)head;
(void)i;
bus.lifi = 1;
}

/**
*add_to_queue - function adds node to tail of queue
*@head: first parameter
*@n: second parameter
*Return: no return value
*/
void add_to_queue(stack_t **head, int n)
{
stack_t *new_node, *temp;

temp = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (temp)
{
while (temp->next)
temp = temp->next;
}
if (!temp)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
temp->next = new_node;
new_node->prev = temp;
}
}
