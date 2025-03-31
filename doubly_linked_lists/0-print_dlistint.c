#include "lists.h"
#include <stdio.h>



size_t print_dlistint(const dlistint_t *h)
{
	int count = 0;
	const dlistint_t *curr = h;

	while (curr)
	{
		if (curr->n)
			printf("%d\n", curr->n);

		count++;
		curr = curr->next;
	}

	return (count);
}
