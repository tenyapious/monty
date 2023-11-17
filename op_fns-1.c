#include "monty.h"

/**
 * add - ad top two elements of the stuck
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	remove_node(stack);
	remove_node(stack);
	add_node(stack, sum);
}
