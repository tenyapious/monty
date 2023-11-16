#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void add_node_end(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node != NULL)
	{
		new_node->n = line_number;
		new_node->next = NULL;

		if (*stack == NULL)
		{
			new_node->prev = NULL;
			*stack = new_node;
		}
		else
		{
			temp = *stack;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
	}
}
