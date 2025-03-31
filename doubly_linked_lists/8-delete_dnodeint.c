#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - A function to delete a node at n position
 *
 * @head: The beginning of the list
 * @index: The position of the node to delete in the list
 *
 * Return: 1 if success, -1 if failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *tmp = *head, *del_node;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	for (; tmp && i < index - 1; i++)
		tmp = tmp->next;

	if (!tmp || !(tmp->next))
		return (-1);

	del_node = tmp->next;
	tmp->next = del_node->next;
	if (del_node->next)
		del_node->next->prev = tmp;

	free(del_node);
	return (1);
}
