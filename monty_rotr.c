#include "monty.h"
/**
*monty_rotr - function rotates stack to the bottom
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_rotr(stack_t **head, __attribute__((unused)) unsigned int i)
{
stack_t *copy;

copy = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
while (copy->next)
{
copy = copy->next;
}
copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
}
