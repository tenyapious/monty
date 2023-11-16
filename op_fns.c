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
		fprintf(stderr, "Error: malloc failed\n");
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

/**
 * add_node_end - add new node to end of stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of opcode
 */
void add_node_end(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node != NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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

/**
 * print_all - print line numbers from stack
 * @stack: pointer to first node of the stack
 * @n: line number
*/
void print_all(stack_t **stack, unsigned int n __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

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
