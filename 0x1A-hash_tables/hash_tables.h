#ifndef __hash_tables__
#define __hash_tables__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Represents a node in a hash table.
 *
 *	@key: The unique string key for this node.
 *	@value: The corresponding value associated with the key.
 *	@next: A pointer to the next node in the linked list.
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Represents a hash table.
 *
 *	@size: The size of the hash table array.
 *	@array: An array of pointers to the first node of linked lists,
 *		facilitating chaining for collision handling.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);

unsigned long int hash_djb2(const unsigned char *str);

unsigned long int key_index(const unsigned char *key, unsigned long int size);

hash_node_t *set_pair(const char *key, const char *value);

int set_pair_only(hash_table_t *ht, const char *key, const char *value,
		  unsigned long int size);

int hash_table_set(hash_table_t *ht, const char *key, const char *value);

char *hash_table_get(const hash_table_t *ht, const char *key);

void hash_table_print(const hash_table_t *ht);

void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s
 - Represents a node in a sorted hash table.
 *
 *	@key: The unique string key for this node.
 *	@value: The corresponding value associated with the key.
 *	@next: A pointer to the next node in the linked list.
 *	@sprev: A pointer to the previous node in the sorted linked list.
 *	@snext: A pointer to the next node in the sorted linked list.
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Represents a sorted hash table.
 *
 *	@size: The size of the hash table array.
 *	@array: An array of pointers to the first node of linked lists,
 *		facilitating chaining for collision handling.
 *	@shead: A pointer to the head of the sorted linked list.
 *	@stail: A pointer to the tail of the sorted linked list.
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);

shash_node_t *set_spair(const char *key, const char *value);

shash_node_t *set_spair_only(shash_table_t *ht, const char *key,
			    const char *value, unsigned long int index);

int update_value(shash_node_t *node, const char *value);

shash_node_t *set_spair_front(shash_table_t *ht, const char *key,
			     const char *value, unsigned long int index);

int slist_set_first(shash_table_t *ht, shash_node_t *node);

int slist_set(shash_table_t *ht, shash_node_t *old_node, shash_node_t *node);

int slist_set_end(shash_table_t *ht, shash_node_t *node);

int shash_table_set(shash_table_t *ht, const char *key, const char *value);

char *shash_table_get(const shash_table_t *ht, const char *key);

void shash_table_print(const shash_table_t *ht);

void shash_table_print_rev(const shash_table_t *ht);

void shash_table_delete(shash_table_t *ht);

#endif /* __hash_tables__ */
