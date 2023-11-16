#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void add_node(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node != NULL)
	{
		new_node->n = line_number;
		new_node->prev = NULL;

		temp = *stack;

		new_node->next = temp;
		*stack = new_node;

		if (temp != NULL)
			temp->prev = *stack;
	}
}
