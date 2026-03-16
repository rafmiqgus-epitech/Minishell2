/*
** EPITECH PROJECT, 2025
** my_compute_square_root.c
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    if (nb < 0) {
        return 0;
    }
    for (int i = 0; i <= 46340 && i * i <= nb; i++) {
        if (i * i == nb)
            return i;
    }
    return 0;
}
