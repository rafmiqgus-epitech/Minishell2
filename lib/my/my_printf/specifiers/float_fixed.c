/*
** EPITECH PROJECT, 2025
** float_fixed.c
** File description:
** fixed-point float formatter
*/

#include "../my_printf.h"
#include "../../my.h"
#include <stdlib.h>

static char *build_frac_dec(long double frac, int precision)
{
    char *frac_str = malloc(precision + 1);
    int i = 0;
    int digit = 0;

    if (!frac_str)
        return NULL;
    for (i = 0; i < precision; i++) {
        frac = frac * 10.0L;
        digit = (int)frac;
        frac = frac - (long double)digit;
        frac_str[i] = '0' + digit;
    }
    frac_str[precision] = '\0';
    return frac_str;
}

static char *join_fixed(bool neg, char *int_part, char *frac_part, bool dot)
{
    int len_i = my_strlen(int_part);
    int len_f = my_strlen(frac_part);
    int total = (neg ? 1 : 0) + len_i + (dot ? 1 : 0) + len_f + 1;
    char *result = malloc(total);
    int idx = 0;

    if (!result)
        return NULL;
    if (neg) {
        result[idx] = '-';
        idx = idx + 1;
    }
    my_strcpy(result + idx, int_part);
    idx = idx + len_i;
    if (dot) {
        result[idx] = '.';
        idx = idx + 1;
    }
    my_strcpy(result + idx, frac_part);
    return result;
}

static char *free_parts(char *result, char *int_str, char *frac_str)
{
    free(int_str);
    free(frac_str);
    return result;
}

static char *fixed_from_abs(long double abs_value, int precision,
    bool neg, bool hash)
{
    unsigned long long int_part = 0;
    long double frac = 0.0L;
    bool dot = (precision > 0 || hash);
    char *int_str = NULL;
    char *frac_str = NULL;
    char *result = NULL;

    abs_value = abs_value + (0.5L / float_pow10(precision));
    int_part = (unsigned long long)abs_value;
    frac = abs_value - (long double)int_part;
    int_str = my_int_to_base(int_part, "0123456789");
    if (!int_str)
        return NULL;
    frac_str = build_frac_dec(frac, precision);
    if (!frac_str) {
        free(int_str);
        return NULL;
    }
    result = join_fixed(neg, int_str, frac_str, dot);
    return free_parts(result, int_str, frac_str);
}

char *float_to_fixed(long double value, int precision, bool upper, bool hash)
{
    if (precision < 0)
        precision = 6;
    if (float_class(value) != 0)
        return float_special_string(value, upper);
    return fixed_from_abs(float_abs(value), precision, float_is_negative(value),
        hash);
}
