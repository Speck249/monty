#include "monty.h"
/**
*monty_rotl- function rotates stack to the top
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_rotl(stack_t **head,  __attribute__((unused)) unsigned int i)
{
stack_t *tmp = *head, *aux;

if (*head == NULL || (*head)->next == NULL)
{
return;
}
aux = (*head)->next;
aux->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = aux;
}
