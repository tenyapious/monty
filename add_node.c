#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_node - add new node to beginning of stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of opcode
 */
void add_node(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->prev = NULL;

	temp = *stack;

	new_node->next = temp;
	*stack = new_node;

	if (temp != NULL)
		temp->prev = *stack;
}
