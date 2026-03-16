/*
** EPITECH PROJECT, 2025
** my_sort_word_array.c
** File description:
** using ascii order, sorts the words received via my_str_to_word_array
** with given function.
*/

#include "my.h"

static void swap(char **a, char **b)
{
    char *temp = *b;

    *b = *a;
    *a = temp;
}

static void detect_swap(char **array, int *nb_swaps,
    int (*cmp)(char const *, char const *))
{
    int cmp_res = cmp(*array, *(array + 1));

    if (cmp_res > 0) {
        swap(array, array + 1);
        (*nb_swaps)++;
    }
}

int my_advanced_sort_word_array(char **tab,
    int (*cmp)(char const *, char const *))
{
    int nb_swaps = 1;
    char **tab_addr = tab;

    while (nb_swaps != 0) {
        nb_swaps = 0;
        tab = tab_addr;
        for (char **p = tab; p[1]; ++p) {
            detect_swap(p, &nb_swaps, cmp);
        }
    }
    return 0;
}
