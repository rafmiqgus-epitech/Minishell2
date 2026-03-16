/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *str_dup = malloc((my_strlen(str) + 1) * 1);

    my_strcpy(str_dup, str);
    return str_dup;
}
