#include "lists.h"

/**
 * add_nodeint_end - Inserts a new node at the end of a linked list.
 * @head: Pointer.
 * @n: Data to be inserted.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *tem = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	*head = (*head) ? *head : new_node;

	while (tem->next)
	{
		tem = tem->next;
	}

	tem->next = new_node;

	return (new_node);
}
