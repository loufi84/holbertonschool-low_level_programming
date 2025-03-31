#include "lists.h"
#include <stdlib.h>

/**
 * free_list - A simple function that frees the allocated memory
 *
 * @head: The beginning of the list
 *
 * Return: Nothing
 */

void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}
