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
	(*stack)->n = sum;
}

/**
 * nop - do nothing
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - sub the top ele of the stack from the second top ele of the stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);

	remove_node(stack);
	(*stack)->n = result;
}

/**
 * division - div the second top ele of the stack by the top ele of the stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void division(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) / ((*stack)->n);

	remove_node(stack);
	(*stack)->n = result;
}

/**
 * mul - mul the second top ele of the stack with the top ele of the stack.
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) * ((*stack)->n);

	remove_node(stack);
	(*stack)->n = result;
}
