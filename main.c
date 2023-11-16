#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - interprete monty bytecode
 * @ac: arguments coount
 * @av: arguments vector
 *
 * Return: 0 if successfull or exit(EXIT_FAILURE)
*/
int main(int ac, char **av)
{
	stack_t *stack __attribute__((unused));
	char *opcode;
	unsigned int line_number;
	FILE *file;
	char line[100];
	const char *delim = " \t\n";
	char *token = NULL;

	if (ac < 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
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

		if (strcmp(opcode, "push") == 0)
		{
			add_node(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			print_all(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free_all(&stack);

	fclose(file);

	return (0);
}
