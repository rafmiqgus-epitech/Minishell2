/*
** EPITECH PROJECT, 2025
** my_print_combn.c
** File description:
** task09
*/

#include "my.h"

static int get_exp(int exp)
{
    int res = 1;

    for (int i = 0; i < exp; i++) {
        res *= 10;
    }
    return res;
}

static int check(int nb)
{
    int current = nb % 10;
    int next = (nb % 100) / 10;

    if (nb < 10) {
        return 0;
    }
    while (nb >= 10) {
        if (current <= next) {
            return 1;
        }
        nb /= 10;
        current = nb % 10;
        next = (nb % 100) / 10;
    }
    return 0;
}

static int get_max(int n)
{
    int res = 10 - n;

    for (int i = 1; i < n; i++) {
        res *= 10;
        res = res + 10 - n + i;
    }
    return res;
}

static void print_numn(int nb, int n, int zero_detect)
{
    int rev_nb = 0;
    int nb_copy = nb;

    if (nb < zero_detect) {
        my_putchar('0');
    }
    while (nb > 0) {
        rev_nb += nb % 10;
        nb /= 10;
        rev_nb *= 10;
    }
    rev_nb /= 10;
    while (rev_nb > 0) {
        my_putchar((rev_nb % 10) + 48);
        rev_nb /= 10;
    }
    if (get_max(n) == nb_copy)
        return;
    my_putchar(',');
    my_putchar(' ');
}

int my_print_combn(int n)
{
    int nb = n >= 2 ? get_exp(n - 2) : 0;
    int zero_detect = nb * 10;

    while (nb < get_exp(n)) {
        if (check(nb) == 0) {
            print_numn(nb, n, zero_detect);
        }
        nb += 1;
    }
    return 0;
}
