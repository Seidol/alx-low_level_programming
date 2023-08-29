#include "lists.h"

/**
 * free_listint - frees a linked
 * @head: list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	for (; head != NULL; temp = head->next)
	{
		free(head);
		head = temp;
	}
}
