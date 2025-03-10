#include "main.h"
#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - print a struct dog
 * @d: The pointer to the dog
 * Return: void
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", (d->name) ? d->name : "(nil)");
		printf("Age: %d\n", (d->age) ? d->age : 0);
		printf("Owner; %s\n", (d->owner) ? d->owner : "(nil)");
	}
}
