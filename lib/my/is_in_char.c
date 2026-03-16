/*
** EPITECH PROJECT, 2025
** is_in_char.c
** File description:
** check
*/
#include "my.h"
#include <stddef.h>
#include <stdbool.h>

bool is_in_char(char c, const char *set)
{
    for (size_t i = 0; set[i]; i++) {
        if (c == set[i])
            return true;
    }
    return false;
}
