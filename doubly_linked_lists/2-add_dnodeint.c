#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - A function that adds a node at the beginning of the list
 *
 * @head: The beginning of the list
 * @n: The data of the new node
 *
 * Return: A pointer to the new node (or NULL if failed)
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}
