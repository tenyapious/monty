#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

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
		printf("USAGE: monty file\n");
		EXIT_FAILURE;
	}

	file = fopen(av[1], "r");

	if (file == NULL)
	{
		perror("Error opening the file");
		return 1;
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

		if (strcmp(opcode,"push") == 0)
		{
			add_node(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			print_all(&stack);
		}
	}
	
	free_all(&stack);

	fclose(file);

	return (0);
}
