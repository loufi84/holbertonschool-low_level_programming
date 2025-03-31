#include "lists.h"

/**
 * free_dlistint - A function to free the list
 *
 * @head: The beginning of the list
 *
 * Return: Nothing
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
