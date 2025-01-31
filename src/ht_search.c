/*
** EPITECH PROJECT, 2025
** secured
** File description:
** search hash
*/

#include "my_printf.h"
#include "my_strings.h"

#include "hashtable.h"

char *search_in_list(list_t *list, int key)
{
    list_t *node = list;

    if (!list)
        return NULL;
    while (node) {
        if (((data_t *)(node->data))->key == key)
            return ((data_t *)(node->data))->value;
        node = node->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    if (!ht || !key || !ht->table || !ht->hash)
        return NULL;
    return search_in_list(ht->table[ht->hash(key, ht->len) % ht->len],
        ht->hash(key, ht->len));
}
