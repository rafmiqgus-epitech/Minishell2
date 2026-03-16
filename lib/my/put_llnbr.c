/*
** EPITECH PROJECT, 2025
** print_number.c
** File description:
** small long long ints printing funcitons
*/

#include "my.h"

void put_llunbr(unsigned long long value)
{
    if (value >= 10)
        put_llunbr(value / 10);
    my_putchar((value % 10) + '0');
}

void put_llnbr(long long value)
{
    unsigned long long magnitude;

    if (value < 0) {
        my_putchar('-');
        magnitude = (unsigned long long)(-(value + 1)) + 1;
    } else {
        magnitude = (unsigned long long)value;
    }
    put_llunbr(magnitude);
}
