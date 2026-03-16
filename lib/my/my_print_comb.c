/*
** EPITECH PROJECT, 2025
** my_print_comb.c
** File description:
** task05
*/

#include "my.h"

static void print_num(char c, char d, char u)
{
    my_putchar(c + 48);
    my_putchar(d + 48);
    my_putchar(u + 48);
    if (c == 7 && d == 8 && u == 9) {
        return;
    }
    my_putchar(44);
    my_putchar(32);
}

static void my_print_comb_suite(int d, int c)
{
    for (int u = 2; u <= 9; u++) {
        if (c < d && d < u) {
            print_num(c, d, u);
        }
    }
}

int my_print_comb(void)
{
    for (int c = 0; c <= 7; c++) {
        for (int d = 1; d <= 8; d++) {
            my_print_comb_suite(d, c);
        }
    }
    return 0;
}
