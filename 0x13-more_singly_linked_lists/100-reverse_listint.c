#include "lists.h"

/**
 * reverse_listint - Reverses the order of nodes in a linked list.
 * @head: Pointer to the first node of the list.
 *
 * This function reverses the order of nodes in the linked list pointed to by
 * @head. It modifies the next pointers to reverse the list order.
 *
 * Return: Pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current;
	listint_t *n;

	if (!head || !(*head) || !((*head)->next))
		return *head;

	current = *head;
	n = current->next;

	while (n)
	{
		current->next = prev;
		prev = current;
		current = n;
		n = n->next;
	}

	current->next = prev;
	*head = current;

	return (*head);
}
