/*
** EPITECH PROJECT, 2025
** secured
** File description:
** insert hash
*/

#include "my_lists.h"
#include "my_strings.h"

#include "hashtable.h"

int
check_and_replace(hashtable_t *ht, char *key, char *value)
{
    int hash = ht->hash(key, ht->len);
    int index = hash % ht->len;
    list_t *tmp = ht->table[index];

    while (tmp) {
        if (((data_t *)tmp->data)->key == hash) {
            free(((data_t *)tmp->data)->value);
            ((data_t *)tmp->data)->value = my_strdup(value);
            return 0;
        }
        tmp = tmp->next;
    }
    return 1;
}

int
ht_insert(hashtable_t *ht, char *key, char *value)
{
    data_t *data = NULL;
    int index = 0;

    if (!ht || !key || !value)
        return 84;
    if (check_and_replace(ht, key, value) == 0)
        return 0;
    data = malloc(sizeof(data_t));
    if (!data)
        return 84;
    data->key = ht->hash(key, ht->len);
    index = data->key % ht->len;
    if (index < 0){
        free(data);
        return 84;
    }
    data->value = my_strdup(value);
    add_to_top(&(ht->table[index]), data);
    return 0;
}
