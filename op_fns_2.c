#include "monty.h"

/**
 * mod - computes the mod of the second top ele by the top ele of the stack.
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) % ((*stack)->n);

	remove_node(stack);
	(*stack)->n = result;
}
