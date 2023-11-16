#include <stdio.h>
#include "monty.h"

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
