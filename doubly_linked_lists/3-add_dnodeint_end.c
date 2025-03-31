#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - A function that adds a node at the end of a list
 *
 * @head: The beginning of the list
 * @n: The data to add in the list
 *
 * Return: A pointer to the new node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *last = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	return (new_node);
}
