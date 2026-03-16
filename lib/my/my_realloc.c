/*
** EPITECH PROJECT, 2025
** my_realloc.c
** File description:
** enlarges a buffer allocated with malloc
*/

#include <stdlib.h>

void *my_realloc(void *ptr, size_t new_size)
{
    char *new_ptr;
    char *prev_ptr = (char *)ptr;

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(new_size);
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
    for (size_t i = 0; i < new_size; i++) {
        new_ptr[i] = prev_ptr[i];
    }
    free(ptr);
    return new_ptr;
}
