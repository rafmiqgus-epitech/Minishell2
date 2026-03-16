/*
** EPITECH PROJECT, 2025
** my_compute_square_root.c
** File description:
** task05
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i <= my_compute_square_root(nb); i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
