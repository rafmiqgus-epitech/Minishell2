/*
** EPITECH PROJECT, 2025
** my_compute_power_it.c
** File description:
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int res = nb;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    for (int i = 0; i < p - 1; i++) {
        res *= nb;
    }
    return res;
}
