/*
** EPITECH PROJECT, 2025
** my_strncat.c
** File description:
** prout
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0' && i < nb; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
