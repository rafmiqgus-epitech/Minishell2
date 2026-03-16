/*
** EPITECH PROJECT, 2025
** my_putnbr_base.c
** File description:
** converts and displays a decimal number into a number in a given base
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = 0;
    long num = nbr;

    while (base[base_len] != '\0') {
        base_len++;
    }
    if (base_len < 2) {
        return 0;
    }
    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num >= base_len) {
        my_putnbr_base(num / base_len, base);
    }
    my_putchar(base[num % base_len]);
    return 0;
}
