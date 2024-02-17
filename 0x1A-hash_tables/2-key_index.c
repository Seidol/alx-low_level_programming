#include "hash_tables.h"

/**
 * key_index - index of a key.
 * @key: string key.
 * @size: hash table array size
 *
 * Return: Index number for the key/value pair in the hash table array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
