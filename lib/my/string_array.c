/*
** EPITECH PROJECT, 2026
** string_array.c
** File description:
** utilities for null-terminated string arrays
*/

#include "my.h"

#include <stdlib.h>

size_t string_array_len(char **array)
{
    size_t len = 0;

    if (array == NULL)
        return 0;
    while (array[len] != NULL)
        ++len;
    return len;
}

void free_string_array(char **array)
{
    size_t len = string_array_len(array);

    if (array == NULL)
        return;
    for (size_t i = 0; i < len; ++i)
        free(array[i]);
    free(array);
}

char **dup_string_array(char **array)
{
    size_t len = string_array_len(array);
    char **dup = malloc(sizeof(char *) * (len + 1));

    if (dup == NULL)
        return NULL;
    for (size_t i = 0; i < len; ++i) {
        dup[i] = my_strdup(array[i]);
        if (dup[i] == NULL) {
            dup[i] = NULL;
            free_string_array(dup);
            return NULL;
        }
    }
    dup[len] = NULL;
    return dup;
}
