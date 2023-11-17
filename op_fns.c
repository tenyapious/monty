#include "monty.h"

/**
 * push - perform push operation
 * @stack: pointer to first node of the stack
 * @line_number: line number of push operation
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *opcode_arg;
	const char *delim = " \t\n";

	opcode_arg = strtok(NULL, delim);

	if (opcode_arg == NULL || isInt(opcode_arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	add_node(stack, atoi(opcode_arg));
}

/**
 * pall - print integers from stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - print integer on top of stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop node from stack
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	remove_node(stack);
}

/**
 * swap - swap top two elements of the stuck
 * @stack: pointer to first node of the stack
 * @line_number: line number of pall operation
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}
