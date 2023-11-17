#include "monty.h"

/**
 * isInt - check if string is an int
 * @s: the string
 *
 * Return: 1 if true or 0
 */
int isInt(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			i++;
			continue;
		}

		if (isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * stack_len - count the length of the stack
 * @stack: pointer to first node of stack
 *
 * Return: length of stack
 */
int stack_len(stack_t **stack)
{
	stack_t *temp;
	int i = 0;

	temp = *stack;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
