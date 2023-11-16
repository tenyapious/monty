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
		if (isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
