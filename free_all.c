#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_all - free stack
 * @stack: pointer to first node of the stack
*/
void free_all(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}
