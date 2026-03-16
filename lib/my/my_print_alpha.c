/*
** EPITECH PROJECT, 2025
** my_print_alpha.c
** File description:
** task01
*/

#include "my.h"

int my_print_alpha(void)
{
    for (char i = 'a'; i <= 'z'; i++) {
        my_putchar(i);
    }
    return 1;
}
