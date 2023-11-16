#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(void)
{
	stack_t *stack __attribute__((unused));
	char *opcode;
	unsigned int line_number;
	FILE *file;
	char line[100];
	const char *delim = " \t\n";
	char *token = NULL;

	file = fopen("bytecodes/000.m", "r");

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
		printf("%s--%d\n", opcode, line_number);
	}

	fclose(file);

	return (0);
}
