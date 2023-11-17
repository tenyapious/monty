#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_node - add new node to beginning of stack
 * @stack: pointer to first node of the stack
 * @n: integer value for node
 */
void add_node(stack_t **stack, int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;

	temp = *stack;

	new_node->next = temp;
	*stack = new_node;

	if (temp != NULL)
		temp->prev = *stack;
}

/**
 * add_node_end - add new node to end of stack
 * @stack: pointer to first node of the stack
 * @n: integer value for node
 */
void add_node_end(stack_t **stack, int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node != NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
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

/**
 * free_stack - free stack
 * @stack: pointer to first node of the stack
*/
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}

/**
 * remove_node - remove node from stack
 * @stack: pointer to first node of the stack
 */
void remove_node(stack_t **stack)
{
	stack_t *temp;

	temp = *stack;

	*stack = temp->next;

	free(temp);
}


