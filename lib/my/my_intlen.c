/*
** EPITECH PROJECT, 2025
** my_intlen.c
** File description:
** calculates the size of an int.
*/

#include <stddef.h>

size_t my_intlen(int nb)
{
    size_t len = 0;

    if (nb <= 0) {
        len++;
        nb = -nb;
    }
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return len;
}
