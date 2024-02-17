#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 *
 * @size: Number of array slots to make the table.
 *
 * Return: Pointer to the hash table created, or NULL if malloc failed.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned int i;
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	return (ht);
}

/**
 * set_spair - Mallocs a key/value pair to the sorted hash table.
 *
 * @key: The key, a non-empty string.
 * @value: The value associated with the key, can be an empty string.
 *
 * Return: Pointer to the new node.
 */
shash_node_t *set_spair(const char *key, const char *value)
{
	shash_node_t *node = malloc(sizeof(shash_node_t));

	if (node == NULL)
		return (NULL);
	node->key = malloc(strlen(key) + 1);
	if (node->key == NULL)
		return (NULL);
	node->value = malloc(strlen(value) + 1);
	if (node->value == NULL)
		return (NULL);
	strcpy(node->key, key);
	strcpy(node->value, value);
	return (node);
}

/**
 * set_spair_only - (No collision) Set key:value pair to first array element.
 *
 * @ht: Pointer to the sorted hash table.
 * @key: The key, a non-empty string.
 * @value: The value associated with the key, can be an empty string.
 * @index: The key's index.
 *
 * Return: The node, or NULL if failed.
 */
shash_node_t *set_spair_only(shash_table_t *ht, const char *key,
			     const char *value, unsigned long int index)
{
	shash_node_t *node = set_spair(key, value);

	if (node == NULL)
		return (NULL);
	node->next = NULL;
	ht->array[index] = node;
	return (node);
}

/**
 * update_value - Updates the value of a given node.
 *
 * @node: Pointer to the node.
 * @value: String to put at the node.
 *
 * Return: 1 on success, 0 on fail.
 */
int update_value(shash_node_t *node, const char *value)
{
	if (strcmp(node->value, value) == 0)
		return (1);
	free(node->value);
	node->value = malloc(strlen(value) + 1);
	if (node->value == NULL)
		return (0);
	strcpy(node->value, value);
	return (1);
}

/**
 * set_spair_front - Sets key:value pair node to front of given index's list.
 *
 * @ht: Pointer to the sorted hash table.
 * @key: The key, a non-empty string.
 * @value: The value associated with the key, can be an empty string.
 * @index: The key's index.
 *
 * Return: The new node, or NULL if failed.
 */
shash_node_t *set_spair_front(shash_table_t *ht, const char *key,
			     const char *value, unsigned long int index)
{
	shash_node_t *node = set_spair(key, value);

	if (node == NULL)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	return (node);
}

/**
 * slist_set_first - Sets the first addition to the sorted list.
 *
 * @ht: Pointer to the sorted hash table.
 * @node: Pointer to the first node on the table.
 *
 * Return: Always 1.
 */
int slist_set_first(shash_table_t *ht, shash_node_t *node)
{
	node->sprev = NULL;
	node->snext = NULL;
	ht->shead = node;
	ht->stail = node;
	return (1);
}

/**
 * slist_set - Sets a new node before the given old node.
 *
 * @ht: Pointer to the sorted hash table.
 * @old_node: The node to place the new node in front of.
 * @node: The new node to place in front of the old one.
 *
 * Return: Always 1 (success).
 */
int slist_set(shash_table_t *ht, shash_node_t *old_node, shash_node_t *node)
{
	if (old_node->sprev == NULL)
		ht->shead = node;
	node->snext = old_node;
	node->sprev = old_node->sprev;
	old_node->sprev = node;
	if (node->sprev != NULL)
		node->sprev->snext = node;
	return (1);
}

/**
 * slist_set_end - Sets a node at the end of the sorted list.
 *
 * @ht: Pointer to the sorted hash table.
 * @node: The node to place at the end.
 *
 * Return: Always 1 (success).
 */
int slist_set_end(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *old_node = ht->stail;

	ht->stail = node;
	node->snext = NULL;
	node->sprev = old_node;
	old_node->snext = node;
	return (1);
}

/**
 * shash_table_set - Adds or updates an element to the sorted hash table.
 *
 * @ht: Pointer to the sorted hash table.
 * @key: The key, a non-empty string.
 * @value: The value associated with the key, can be an empty string.
 *
 * Return: 1 on success, 0 on error.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *curr_old_node;

	if (key == NULL || ht == NULL)
		return (0);
	/* Set the item in the table */
	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];
	if (node == NULL)
		node = set_spair_only(ht, key, value, index);
	else
	{
		for (; node != NULL; node = node->next)
		{
			if (strcmp(node->key, key) == 0)
				return (update_value(node, value));
		}
		node = set_spair_front(ht, key, value, index);
	}
	if (node == NULL)
		return (0);
	/* Arrange the item in the sorted linked list */
	if (ht->shead == NULL)
		return (slist_set_first(ht, node));
	for (curr_old_node = ht->shead; curr_old_node != NULL;
	     curr_old_node = curr_old_node->snext)
	{
		if (strcmp(curr_old_node->key, node->key) >= 0)
			return (slist_set(ht, curr_old_node, node));
	}
	return (slist_set_end(ht, node));
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 *
 * @ht: A pointer to the sorted hash table array.
 * @key: The key, a non-empty string.
 *
 * Return: The value associated with the key, or NULL if key can't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL)
		return (NULL);
	if (key == NULL)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index] == NULL)
		return (NULL);
	if (strcmp(ht->array[index]->key, key) == 0)
		return (ht->array[index]->value);
	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
	}
	return (NULL);
}

/**
 * shash_table_print - Prints key/value pairs in sorted hash table order.
 *
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int count = 0;
	shash_node_t *node;

	if (ht == NULL)
		return;
	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		if (count > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		count++;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints sorted key/value pairs in reverse.
 *
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int count = 0;
	shash_node_t *node;

	if (ht == NULL)
		return;
	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		if (count > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		count++;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 *
 * @ht: The sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		for (node = ht->array[i]; node != NULL;)
		{
			temp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}
	}
	free(ht->array);
	free(ht);
}
