#include <stdio.h>
#include "monty.h"

/**
 * print_all - print line numbers from stack
 * @stack: pointer to first node of the stack
*/
void print_all(stack_t **stack)
{
	stack_t *temp;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
