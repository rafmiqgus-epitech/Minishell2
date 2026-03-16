/*
** EPITECH PROJECT, 2025
** my_find_prime_sup.c
** File description:
** task07
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 0) {
        return 0;
    }
    for (int i = nb + 1; i < 2147483647; i++) {
        if (my_is_prime(i)) {
            return i;
        }
    }
    return 0;
}
