#include "header.h"

//return hash result
int hash(char *input)
{
	return (strlen(input) % 42 / 10);
}

//initialize the dictionnary, given as parameter the capacity of the array
struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict;

	dict = malloc(sizeof(struct s_dict));
	dict->items = malloc(sizeof(struct s_item *) * capacity);
	for (int i = 0; i < capacity; i++)
	{
		dict->items[i] = malloc(sizeof(struct s_item));
		dict->items[i]->value = NULL;
		dict->items[i]->key = NULL;
		dict->items[i]->next = NULL;
	}
	dict->capacity = capacity;

	return (dict);
} 

//add one element in the dictionnary, if FAIL return 0, otherwise 1
int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item *item;

	if (!(item = malloc(sizeof(struct s_item))))
		return (0);

	item->value = value;
	item->key = strdup(key);
	item->next = NULL;

	int hash_idx = hash(key);
	if (hash_idx >= dict->capacity)
		hash_idx = dict->capacity;

	//printf("key: %s hash: %d\n", key, hash_idx);

	if (dict->items[hash_idx]->value != NULL)
	{
		struct s_item *tmp = dict->items[hash_idx];

		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = item;
	}
	else
		dict->items[hash_idx] = item;
	return (1);
} 

//find one element in the dictionnary, if not found, return NULL
struct s_art *dictSearch(struct s_dict *dict, char *name)
{
	int hash_idx = hash(name);
	if (hash_idx >= dict->capacity)
		hash_idx = dict->capacity;

	if (!dict->items[hash_idx])
		return (NULL);
	else
	{
		struct s_item *tmp = dict->items[hash_idx];
		
		while ((strcmp(tmp->value->name, name)) != 0)
		{
			tmp = tmp->next;
			if (!tmp)
				return (NULL);
		}
		return (tmp->value);
	}
}

int searchPrice(struct s_dict *dict, char *name)
{
	if (!dict || !name)
		return (-1);

	struct s_art *res = dictSearch(dict, name);
	if (!res)
		return (-1);
	else
		return (res->price);
}