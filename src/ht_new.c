/*
** EPITECH PROJECT, 2025
** secured
** File description:
** new table
*/

#include <stddef.h>

#include "hashtable.h"

hashtable_t *
new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = NULL;

    if (!hash || len < 1)
        return NULL;
    ht = malloc(sizeof(hashtable_t));
    if (!ht)
        return NULL;
    ht->table = malloc(sizeof(list_t *) * len);
    if (!ht->table)
        return NULL;
    for (int i = 0; i < len; i++)
        ht->table[i] = NULL;
    ht->len = len;
    ht->hash = hash;
    return ht;
}
