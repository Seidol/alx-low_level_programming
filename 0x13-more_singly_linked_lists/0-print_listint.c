#include "lists.h"

/**
 * print_listint - Display nums of the elements of a linked list
 * @h: pointer to display number and link to next list
 *
 * Return: This will return all node's n
 */
size_t print_listint(const listint_t *h)
{
	size_t number = 0;

	for (; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
		number++;
	}

	return (number);
}
