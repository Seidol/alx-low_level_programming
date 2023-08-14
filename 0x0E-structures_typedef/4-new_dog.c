#include <stdlib.h>
#include "dog.h"

int custom_strlen(char *s);
char *custom_strcpy(char *dest, char *src);

/**
  * new_dog - Creates a new dog structure.
  * @name: The name of the dog.
  * @age: The age of the dog.
  * @owner: The owner of the dog.
  *
  * Return: A pointer to the new dog structure.
  */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *puppy_dog;
	int name_length = 0, owner_length = 0;

	if (name != NULL && owner != NULL)
	{
		name_length = custom_strlen(name) + 1;
		owner_length = custom_strlen(owner) + 1;
		puppy_dog = malloc(sizeof(dog_t));

		if (puppy_dog == NULL)
			return (NULL);

		puppy_dog->name = malloc(sizeof(char) * name_length);

		if (puppy_dog->name == NULL)
		{
			free(puppy_dog);
			return (NULL);
		}

		puppy_dog->owner = malloc(sizeof(char) * owner_length);

		if (puppy_dog->owner == NULL)
		{
			free(puppy_dog->name);
			free(puppy_dog);
			return (NULL);
		}

		char *name_copy = puppy_dog->name;
		char *owner_copy = puppy_dog->owner;
		char *name_src = name;
		char *owner_src = owner;

		while (*name_src)
		{
			*name_copy++ = *name_src++;
		}
		*name_copy = '\0';

		while (*owner_src)
		{
			*owner_copy++ = *owner_src++;
		}
		*owner_copy = '\0';

		puppy_dog->age = age;
	}

	return (puppy_dog);
}

/**
  * custom_strlen - Returns the length of a string.
  * @s: The string to count.
  *
  * Return: The length of the string.
  */
int custom_strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
  * custom_strcpy - Copies a string.
  * @dest: The destination buffer.
  * @src: The source string.
  *
  * Return: A pointer to the destination buffer.
  */
char *custom_strcpy(char *dest, char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (original_dest);
}
