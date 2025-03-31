#include "lists.h"

/**
 * get_dnodeint_at_index - A function that get the node in n position
 *
 * @head: The start of the list
 * @index: The desired node
 *
 * Return: A pointer to the asked node (or NULL if non existant)
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);

		head = head->next;
		i++;
	}

	return (NULL);
}
