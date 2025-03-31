#include <stddef.h>
#include <string.h>
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
 * add_node - A function that add a new node at the beginning of a list
 *
 * @head: The beginning of hte list
 * @str: The string to add at the list
 *
 * Return: Pointer to the address of the new node (or NULL if failed)
 */

list_t *add_node(list_t **head, const char *str)
{
	char *new = strdup(str);
	list_t *new_node;

	if (new == NULL)
		return (NULL);

	new_node = (list_t *)malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = new;
	new_node->next = *head;
	new_node->len = _strlen(str);
	*head = new_node;

	return (new_node);
}
