#include "main.h"
#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * init_dog - Initialize a dog struct
 * @d: The structure
 * @name: The dog's name
 * @age: The dog's age
 * @owner: The dog's owner
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
