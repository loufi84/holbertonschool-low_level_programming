#include "lists.h"

/**
 * sum_dlistint - A function that sums all n of a list
 *
 * @head: The start of the list
 *
 * Return: The sum of all n datas in the list
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
