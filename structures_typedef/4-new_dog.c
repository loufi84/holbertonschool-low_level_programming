#include "main.h"
#include "dog.h"
#include <stdlib.h>

/**
 * str_len - calculate the length of a string
 * @str: the string to calculate
 * Return: the length of the string
 */

unsigned int str_len(char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * new_dog - create a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: a dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	unsigned int i;

	dog = (dog_t *)malloc(sizeof(dog_t));
	if (dog == NULL)
	{
		return (NULL);
	}

	dog->name = (char *)malloc(str_len(name) + 1);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = (char *)malloc(str_len(owner) + 1);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	for (i = 0; i <= str_len(name); i++)
	{
		dog->name[i] = name[i];
	}
	for (i = 0; i <= str_len(owner); i++)
	{
		dog->owner[i] = owner[i];
	}

	dog->age = age;

	return (dog);
}
