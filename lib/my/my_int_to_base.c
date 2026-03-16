/*
** EPITECH PROJECT, 2025
** my_nbr_to_base.c
** File description:
** converts an int number into a given base
*/

#include "my.h"
#include <stdlib.h>

static int get_nb_digits(unsigned long long nbr, int base_len)
{
    int count = 0;

    if (nbr == 0)
        return 1;
    while (nbr != 0) {
        nbr /= base_len;
        count++;
    }
    return count;
}

static void fill_result(char *result, unsigned long long nbr, char const *base,
    int base_len)
{
    int i = get_nb_digits(nbr, base_len) - 1;

    result[i + 1] = '\0';
    while (nbr >= (unsigned long long)base_len) {
        result[i] = base[nbr % base_len];
        i--;
        nbr /= base_len;
    }
    result[i] = base[nbr % base_len];
}

char *my_int_to_base(unsigned long long nbr, char const *base)
{
    int base_len = my_strlen(base);
    int size = get_nb_digits(nbr, base_len);
    char *result = malloc(sizeof(char) * (size + 1));

    if (base_len < 2 || result == NULL)
        return NULL;
    fill_result(result, nbr, base, base_len);
    return result;
}
