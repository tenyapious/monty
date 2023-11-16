#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * getOpFn - get operation function
 * @opcode: opcode
 *
 * Return: the function for the opcode or NULL
*/
void (*getOpFn(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opFnArr[] = {
		{"push", add_node},
		{"pall", print_all},
		{NULL, NULL}
	};
	int i = 0;

	while (opFnArr[i].opcode != NULL)
	{
		if (strcmp(opFnArr[i].opcode, opcode) == 0)
			return (opFnArr[i].f);
		i++;
	}
	return (NULL);
}


/**
 * exec_line - execute line from monty bytecode
 * @stack: pointer to first node of the stack
 * @opcode: instruction to be executed
 * @line_number: line number of opcode
 */
void exec_line(stack_t **stack, char *opcode, int line_number)
{
	instruction_t *func;

	func = malloc(sizeof(instruction_t));
	if (func == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	func->f = getOpFn(opcode);

	if (func->f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	else
	{
		func->f(stack, line_number);
	}

	free(func);
}

/**
 * main - interprete monty bytecode
 * @ac: arguments coount
 * @av: arguments vector
 *
 * Return: 0 if successfull or exit(EXIT_FAILURE)
 */
int main(int ac, char **av)
{
	stack_t *stack;
	char *opcode;
	unsigned int line_number;
	FILE *file;
	char line[100];
	const char *delim = " \t\n";
	char *token = NULL;

	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		token = strtok(line, delim);
		opcode = token;
		token = strtok(NULL, delim);
		if (token != NULL)
		{
			line_number = atoi(token);
		}
		exec_line(&stack, opcode, line_number);
	}

	free_all(&stack);

	fclose(file);

	return (0);
}
