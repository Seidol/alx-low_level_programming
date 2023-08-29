#include "lists.h"

/**
 * free_listint_safe - will free a linked list
 * @h: pointer to the first node.
 *
 * Return: all elements in the list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	for (; *h; len++)
	{
		temp = (*h)->next;
		(*h)->next = NULL;
		free(*h);
		*h = temp;

		if (*h <= temp)
		{
			break;
		}
	}

	*h = NULL;

	return (len);
}
