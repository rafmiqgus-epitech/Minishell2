/*
** EPITECH PROJECT, 2025
** my_itoa.c
** File description:
** transforms an int as it's equivalent in a string.
*/

#include <stdlib.h>

static int get_int_length(int nb)
{
    int len = 0;

    while (nb != 0) {
        nb /= 10;
        len++;
    }
    return len;
}

char *my_itoa(int nb)
{
    int neg = (nb < 0);
    int nb_tmp = (neg) ? -nb : nb;
    char *str;
    int len;

    if (nb == 0)
        return "0";
    len = get_int_length(nb_tmp);
    str = malloc(sizeof(char) * (len + neg + 1));
    if (!str)
        return NULL;
    str[len + neg] = '\0';
    while (nb_tmp != 0) {
        len--;
        str[len + neg] = (nb_tmp % 10) + '0';
        nb_tmp /= 10;
    }
    if (neg)
        str[0] = '-';
    return str;
}
