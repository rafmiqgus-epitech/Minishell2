/*
** EPITECH PROJECT, 2025
** float_scientific.c
** File description:
** scientific float formatter
*/

#include "../my_printf.h"
#include "../../my.h"
#include <stdlib.h>

static void normalize_dec(long double *norm, int *exp)
{
    while (*norm >= 10.0L) {
        *norm = *norm / 10.0L;
        *exp = *exp + 1;
    }
    while (*norm > 0.0L && *norm < 1.0L) {
        *norm = *norm * 10.0L;
        *exp = *exp - 1;
    }
}

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

static char *alloc_mantissa(char *lead, char *frac, bool dot)
{
    int len_l = my_strlen(lead);
    int len_f = my_strlen(frac);
    char *result = malloc(len_l + (dot ? 1 : 0) + len_f + 1);

    if (!result)
        return NULL;
    my_strcpy(result, lead);
    if (dot) {
        result[len_l] = '.';
        my_strcpy(result + len_l + 1, frac);
        return result;
    }
    my_strcpy(result + len_l, frac);
    return result;
}

static char *build_mantissa(int lead, long double frac, int precision, bool dot)
{
    char *lead_str = my_int_to_base(lead, "0123456789");
    char *frac_str = NULL;
    char *result = NULL;

    if (!lead_str)
        return NULL;
    frac_str = build_frac_dec(frac, precision);
    if (!frac_str) {
        free(lead_str);
        return NULL;
    }
    result = alloc_mantissa(lead_str, frac_str, dot);
    free(lead_str);
    free(frac_str);
    return result;
}

static char *build_exp_part(int exp)
{
    char *digits = my_int_to_base((exp < 0) ? -exp : exp, "0123456789");
    int len = 0;
    char *result = NULL;

    if (!digits)
        return NULL;
    len = my_strlen(digits);
    result = malloc((len < 2 ? 4 : len + 2));
    if (!result) {
        free(digits);
        return NULL;
    }
    result[0] = (exp < 0) ? '-' : '+';
    if (len < 2)
        result[1] = '0';
    my_strcpy(result + ((len < 2) ? 2 : 1), digits);
    free(digits);
    return result;
}

static char *build_sci_string(bool neg, char *mantissa, bool upper, char *exp)
{
    int len_m = my_strlen(mantissa);
    int len_e = my_strlen(exp);
    char *result = malloc((neg ? 2 : 1) + len_m + 1 + len_e);
    int idx = 0;

    if (!result)
        return NULL;
    if (neg) {
        result[idx] = '-';
        idx = idx + 1;
    }
    my_strcpy(result + idx, mantissa);
    idx = idx + len_m;
    result[idx] = upper ? 'E' : 'e';
    my_strcpy(result + idx + 1, exp);
    return result;
}

static char *sci_with_exp(long double value, bool upper,
    int exp, char *mantissa)
{
    char *exp_part = build_exp_part(exp);
    char *result = NULL;

    if (!exp_part) {
        free(mantissa);
        return NULL;
    }
    result = build_sci_string(float_is_negative(value), mantissa, upper,
        exp_part);
    free(mantissa);
    free(exp_part);
    return result;
}

static char *sci_from_value(long double value, int precision, bool upper,
    bool hash)
{
    long double norm = float_abs(value);
    int exp = 0;
    int lead = 0;
    char *mantissa = NULL;

    normalize_dec(&norm, &exp);
    norm = norm + (0.5L / float_pow10(precision));
    if (norm >= 10.0L) {
        norm = norm / 10.0L;
        exp = exp + 1;
    }
    lead = (int)norm;
    mantissa = build_mantissa(lead, norm - (long double)lead, precision,
        (precision > 0 || hash));
    if (!mantissa)
        return NULL;
    return sci_with_exp(value, upper, exp, mantissa);
}

char *float_to_sci(long double value, int precision, bool upper, bool hash)
{
    if (precision < 0)
        precision = 6;
    if (float_class(value) != 0)
        return float_special_string(value, upper);
    return sci_from_value(value, precision, upper, hash);
}
