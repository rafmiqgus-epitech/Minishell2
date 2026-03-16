/*
** EPITECH PROJECT, 2025
** my_print_digits.c
** File description:
** task03
*/

#include "my.h"

int my_print_digits(void)
{
    for (int i = 48; i < 58; i++) {
        my_putchar(i);
    }
    return 0;
}
