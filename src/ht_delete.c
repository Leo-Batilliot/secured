/*
** EPITECH PROJECT, 2025
** secured
** File description:
** delete hash
*/

#include "my_lists.h"

#include "hashtable.h"

void
free_data(void *data)
{
    free(((data_t *)data)->value);
    free(data);
}

int
cmp_data(void const *d1, void const *d2)
{
    data_t *data1 = (data_t *)d1;
    data_t *data2 = (data_t *)d2;

    return (data1->key - data2->key);
}

int
ht_delete(hashtable_t *ht, char *key)
{
    int hash = 0;
    int index = 0;
    data_t *data = NULL;

    if (!ht || !key)
        return 84;
    hash = ht->hash(key, ht->len);
    if (hash < 0)
        return 84;
    data = malloc(sizeof(data_t));
    if (!data)
        return 84;
    data->key = hash;
    index = hash % ht->len;
    if (ht->table[index] == NULL)
        return 84;
    remove_node(&ht->table[index], data, &free_data, &cmp_data);
    free(data);
    return 0;
}
