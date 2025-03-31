#include <stddef.h>
#include <stringw.h>
#include <stdlib.h>
#include "lists.h"

/**
 * _strlen - A custom function to calculate the length of a string
 *
 * @str: The string to calculate length for
 *
 * Return: The length of the string
 */

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

/**
 * add_node_end - A function that adds a node at the end of a list
 *
 * @head: Pointer to the beginning of the list
 * @str: The string to append at the list
 *
 * Return: The memory address of the new node (or NULL if fail)
 */

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
