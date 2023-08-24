#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list
 * @head: Pointer to the list_t list to be freed
 *
 * Description: This function frees
 * each node in the linked list 'head'. It
 * releases the memory allocated for
 * the 'str' field of each node and then
 * frees the node itself.
 * The function starts from the beginning of the list
 * and iterates through until the entire list is freed.
 */
void free_list(list_t *head)
{
	list_t *t;

	while (head)
	{
		t = head->next;
		free(head->str);
		free(head);
		head = t;
	}
}
