#include "monty.h"
/**
*monty_push - function adds node to stack
*@head: first parameter
*@i: second parameter
*Return: no return value
*/
void monty_push(stack_t **head, unsigned int i)
{
int j, k = 0, flag = 0;

if (bus.arg)
{
if (bus.arg[0] == '-')
k++;
for (; bus.arg[k] != '\0'; k++)
{
if (bus.arg[k] > 57 || bus.arg[k] < 48)
flag = 1; }

if (flag == 1)
{fprintf(stderr, "L%d: usage: push integer\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE); }}
else
{ fprintf(stderr, "L%d: usage: push integer\n", i);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE); }
j = atoi(bus.arg);

if (bus.lifi == 0)
add_node(head, j);
else
add_queue(head, j);
}
