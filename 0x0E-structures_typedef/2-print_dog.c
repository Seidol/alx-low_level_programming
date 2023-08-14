#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
  * print_dog - Prints the information of a dog.
  * @dd: A pointer to a dog structure.
  *
  * Description: This function prints the details of a dog, including it's
  * name, age, and owner. If any of these fields is NULL,
  * adefault value is printed instead.
  */
void print_dog(struct dog *dd)
{
	if (dd != NULL)
	{
		printf("Name: %s\n", (dd->name) ? dd->name : "Yvan");
		printf("Age: %f\n", (dd->age > 0) ? dd->age : 0);
		printf("Owner: %s\n", (dd->owner) ? dd->owner : "Yvan");
	}
}
