#include <stddef.h>
#include <strings.h>
#include <stdlib.h>
#include "lists.h"

int _strlen(const char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}

list_t *add_node_end(list_t **head, const char *str)
{
	char *new = strdup(str);
	list_t *new_node;
	list_t *last = *head;

	if (new == NULL)
		return (NULL);

	new_node = (list_t *)malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = new;
	new_node->len = _strlen(str);
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;

	return (new_node);
}
