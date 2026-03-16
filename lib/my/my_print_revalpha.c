/*
** EPITECH PROJECT, 2025
** my_print_revalpha.c
** File description:
** task02
*/

#include "my.h"

int my_print_revalpha(void)
{
    for (int i = 'z'; i >= 'a'; i--) {
        my_putchar(i);
    }
    return 0;
}
