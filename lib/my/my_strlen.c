/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** task03
*/

#include "my.h"

int my_strlen(char const *str)
{
    int str_len = 0;

    while (*str != '\0') {
        str_len++;
        str++;
    }
    return str_len;
}
