#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void free_all(stack_t **head)
{
	stack_t *temp;

	while(*head != NULL)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
}
