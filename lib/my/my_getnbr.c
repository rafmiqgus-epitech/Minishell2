/*
** EPITECH PROJECT, 2025
** my_getnbr.c
** File description:
** task05
*/

#include "my.h"
#include <limits.h>

static int is_min_int(char const *c)
{
    const char *min_int = "2147483648";

    for (int i = 0; i < 10; i++) {
        if (c[i] != min_int[i])
            return 0;
    }
    if (c[10] >= '0' && c[10] <= '9')
        return 0;
    return 1;
}

static int is_int(char const *str)
{
    int nb = 0;

    while (*str >= '0' && *str <= '9') {
        if (nb > 0) {
            nb *= 10;
        }
        nb += *str - 48;
        str += 1;
    }
    if (nb < 0) {
        return 0;
    } else {
        return nb;
    }
}

static int is_sign(char const *c)
{
    int nb_min = 0;

    while (*c == '+' || *c == '-') {
        if (*c == '-')
            nb_min += 1;
        c++;
    }
    if (c[0] < '0' || c[0] > '9')
        return my_getnbr(c);
    if ((nb_min % 2) == 0)
        return is_int(c);
    if (is_min_int(c))
        return INT_MIN;
    return -is_int(c);
}

int my_getnbr(char const *str)
{
    while (*str != '\0') {
        if (*str == '-' || *str == '+') {
            return is_sign(str);
        }
        if (*str >= '0' && *str <= '9') {
            return is_int(str);
        }
        str += 1;
    }
    return 0;
}
