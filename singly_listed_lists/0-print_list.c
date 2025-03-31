#include "lists.h"
#include <stdio.h>
#include <stddef.h>

size_t print_list(const list_t *h)
{
	int count = 0;

	const list_t *curr = h;

	while (curr)
	{
		if (curr->str)
			printf("[%u] %s\n", curr->len, curr->str);

		else
			printf("[0] (nil)");

		count++;
		curr = curr->next;
	}
	return (count);
}
