/*
** EPITECH PROJECT, 2025
** secured
** File description:
** dump table
*/

#include "hashtable.h"
#include "my_printf.h"

void print_list_content(list_t *list)
{
    list_t *node = list;

    while (node != NULL) {
        my_printf("> %i - %s\n",
            ((data_t *)(node->data))->key,
            ((data_t *)(node->data))->value);
        node = node->next;
    }
    return;
}

void ht_dump(hashtable_t *ht)
{
    if (!ht || !ht->table)
        return;
    for (int i = 0; i < ht->len; i++) {
        my_printf("[%i]:\n", i);
        print_list_content(ht->table[i]);
    }
    return;
}
