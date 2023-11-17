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
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", mod},
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
 * readLine - read line from file
 * @file: file to read line from
 */
void readLine(FILE *file)
{
	stack_t *stack = NULL;
	char *opcode;
	unsigned int line_number = 1;
	char line[100];
	const char *delim = " \t\n";
	instruction_t *func;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (line[0] == '#')
			opcode = "nop";
		else
			opcode = strtok(line, delim);

		if (opcode == NULL)
		{
			line_number++;
			continue;
		}

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
		func->f(&stack, line_number);
		free(func);
		line_number++;
	}
	free_stack(&stack);
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
