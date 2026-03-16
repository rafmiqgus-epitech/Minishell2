/*
** EPITECH PROJECT, 2025
** my_isneg.c
** File description:
** task04
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    };
    return 0;
}
