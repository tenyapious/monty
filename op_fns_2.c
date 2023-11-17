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

/**
 * pchar - The opcode pchar prints the char at the top of the stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	_putchar(n);
	_putchar('\n');
}
