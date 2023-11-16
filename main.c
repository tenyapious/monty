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
 * @opcode: instruction to be executed
 * @line_number: line number of opcode
 *
 * Return: instrunction_t
*/
instruction_t *exec_line(char *opcode, unsigned int *line_number)
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
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, opcode);
		exit(EXIT_FAILURE);
	}
	return (func);
}

/**
 * readLine - read line from file
 * @file: file to read line from
*/
void readLine(FILE *file)
{
	stack_t *stack = NULL;
	char *opcode;
	unsigned int line_number = 1, n;
	char line[100];
	const char *delim = " \t\n";
	char *token = NULL;
	instruction_t *func;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		token = strtok(line, delim);
		opcode = token;
		token = strtok(NULL, delim);
		if (token != NULL || strcmp(opcode, "push") == 0)
		{
			if (token[0] != '0' && atoi(token) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			else
				n = atoi(token);
		}
		func = exec_line(opcode, &line_number);
		func->f(&stack, n);

		free(func);
		line_number++;
	}
	free_all(&stack);
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
	FILE *file;

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

	readLine(file);

	fclose(file);
	return (0);
}
