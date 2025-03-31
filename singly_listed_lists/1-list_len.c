#include <stddef.h>
#include "lists.h"

size_t list_len(const list_t *h)
{
	int count = 0;
	const list_t *curr = h;

	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
