/*
** EPITECH PROJECT, 2025
** curry
** File description:
** hash function
*/

#include <limits.h>

#include "hashtable.h"

int
hash(char *key, __attribute__((unused)) int size)
{
    unsigned long hash = 5381;
    int c = 0;
    int result = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        c = key[i];
        hash = ((hash << 5) + hash) + (c * (i + 1));
    }
    hash ^= (hash >> 21);
    hash *= 2654435761;
    result = (int)(hash % INT_MAX);
    return result > 0 ? result : result + 1;
}
