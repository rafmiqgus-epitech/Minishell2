/*
** EPITECH PROJECT, 2025
** my_swap.c
** File description:
** task02
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str += 1;
    }
    return 0;
}
