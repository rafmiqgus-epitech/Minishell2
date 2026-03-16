/*
** EPITECH PROJECT, 2025
** my_print_comb2.c
** File description:
** task06
*/

#include "my.h"

static void print_num2(int a, int b, int c, int d)
{
    if ((c * 10 + d) <= (a * 10 + b)) {
        return;
    }
    my_putchar(a + 48);
    my_putchar(b + 48);
    my_putchar(' ');
    my_putchar(c + 48);
    my_putchar(d + 48);
    if (a == 9 && b == 8 && c == 9 && d == 9) {
        return;
    }
    my_putchar(',');
    my_putchar(' ');
}

static void my_print_comb2_suite(int a, int b)
{
    for (int c = 0; c <= 9; c++) {
        for (int d = 0; d <= 9; d++) {
            print_num2(a, b, c, d);
        }
    }
}

int my_print_comb2(void)
{
    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            my_print_comb2_suite(a, b);
        }
    }
    return 0;
}
