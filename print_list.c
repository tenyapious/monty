#include <stdio.h>
#include "monty.h"

void print_list(stack_t **stack, unsigned int n __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
