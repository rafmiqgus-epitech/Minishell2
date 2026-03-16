/*
** EPITECH PROJECT, 2025
** my_ftoa.c
** File description:
** transforms a float into it's equivalent as a string
*/

#include <stdlib.h>
#include "my.h"

static void write_int_part(char *str, int *idx, long value)
{
    char *int_str;
    int i;

    int_str = my_int_to_base((unsigned long long)value, "0123456789");
    for (i = 0; int_str[i]; i++) {
        str[*idx] = int_str[i];
        (*idx)++;
    }
    free(int_str);
}

static void write_frac_part(char *str, int *idx, long frac, int prec)
{
    int i;

    str[*idx] = '.';
    (*idx)++;
    for (i = prec - 1; i >= 0; i--) {
        str[*idx + i] = '0' + (frac % 10);
        frac /= 10;
    }
    *idx += prec;
}

static long compute_scale(int prec)
{
    long scale;
    int i;

    scale = 1;
    for (i = 0; i < prec; i++)
        scale *= 10;
    return scale;
}

static long get_frac_part(float nb, long int_part, long scale)
{
    return (long)((nb - (float)int_part) * (float)scale);
}

static char *build_float_str(int neg, long int_part, long frac, int prec)
{
    char *result;
    int len;
    int idx;

    len = (neg ? 1 : 0) + my_intlen(int_part) + (prec > 0 ? 1 + prec : 0) + 1;
    result = malloc(len);
    if (!result)
        return NULL;
    idx = 0;
    if (neg) {
        result[idx] = '-';
        idx++;
    }
    write_int_part(result, &idx, int_part);
    if (prec > 0)
        write_frac_part(result, &idx, frac, prec);
    result[idx] = '\0';
    return result;
}

char *my_ftoa(float nb, int precision)
{
    int neg;
    int prec;
    long int_part;
    long frac_part;
    long scale;

    neg = (nb < 0.0f);
    if (neg)
        nb = -nb;
    prec = (precision < 0) ? 6 : precision;
    int_part = (long)nb;
    scale = compute_scale(prec);
    frac_part = get_frac_part(nb, int_part, scale);
    return build_float_str(neg, int_part, frac_part, prec);
}
