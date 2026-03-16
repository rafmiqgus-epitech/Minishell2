/*
** EPITECH PROJECT, 2025
** my_compute_factorial_it.c
** File description:
** task01
*/

int my_compute_factorial_it(int nb)
{
    int factorial = nb;

    if (nb < 0 || nb >= 13) {
        return 0;
    }
    if (nb == 0) {
        return 1;
    }
    for (int i = 1; i < nb; i++) {
        factorial *= nb - i;
    }
    return factorial;
}
