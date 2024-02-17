#include "hash_tables.h"

/**
 * hash_table_print - Prints key/value pairs in the hash table array order.
 *
 * @ht: A pointer to the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0, count = 0;
	hash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	while (i < ht->size)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			for (; node != NULL; node = node->next)
			{
				if (count > 0)
					printf(", ");
				printf("'%s': '%s'", node->key, node->value);
				count++;
			}
		}
		i++;
	}
	printf("}\n");
}
