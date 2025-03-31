#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/**
 * struct list_t - A singly linked list
 *
 * @str: A string in the list
 * @len: The length of said string
 * @next: A pointer to the next node
 */

typedef struct list_t
{
	char *str;
	unsigned int len;
	struct list_t *next;
} list_t;

int _putchar(char c);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif /* MAIN_H */
