/*
** EPITECH PROJECT, 2025
** secured
** File description:
** delete table
*/

#include "my_lists.h"

#include "hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; i < ht->len; i++)
        free_list(&(ht->table[i]), &free_data);
    free(ht->table);
    free(ht);
    return;
}
