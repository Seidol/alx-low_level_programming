#include <stdio.h>
#include "lists.h"

/**
 * print_list- Displays the contents of a linked list
 * @h: Pointer to the list_t linked list for printing
 * Return: The count of nodes that were printed
 *
 * Description: This function prints the data of each node in the linked list
 * pointed to by 'h'. It returns the total count of nodes that were printed.
 */

size_t print_list(const list_t *h)
{
	size_t a = 0;

	for (; h != NULL; h = h->next)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		a++;
	}
	return (a);
}
