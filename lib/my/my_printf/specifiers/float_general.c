/*
** EPITECH PROJECT, 2025
** float_general.c
** File description:
** general float formatter
*/

#include "../my_printf.h"
#include "../../my.h"

static int get_dec_exp(long double value)
{
    int exp = 0;

    while (value >= 10.0L) {
        value = value / 10.0L;
        exp = exp + 1;
    }
    while (value > 0.0L && value < 1.0L) {
        value = value * 10.0L;
        exp = exp - 1;
    }
    return exp;
}

static void trim_fixed(char *str)
{
    int i = my_strlen(str) - 1;

    while (i >= 0 && str[i] != '.' && str[i] == '0') {
        str[i] = '\0';
        i = i - 1;
    }
    if (i >= 0 && str[i] == '.')
        str[i] = '\0';
}

static void trim_sci(char *str)
{
    int exp_i = 0;
    int dot_i = 0;
    int end = 0;

    while (str[exp_i] && str[exp_i] != 'e' && str[exp_i] != 'E')
        exp_i = exp_i + 1;
    while (str[dot_i] && str[dot_i] != '.')
        dot_i = dot_i + 1;
    for (end = exp_i - 1; end > dot_i && str[end] == '0'; end = end - 1)
        str[end] = '\0';
    if (end == dot_i)
        str[end] = '\0';
    while (str[exp_i]) {
        str[end + 1] = str[exp_i];
        end = end + 1;
        exp_i = exp_i + 1;
    }
    str[end + 1] = '\0';
}

static char *format_sci(long double value, int precision, bool upper, bool hash)
{
    char *result = float_to_sci(value, precision - 1, upper, hash);

    if (result && !hash)
        trim_sci(result);
    return result;
}

static char *format_fixed(long double value, int precision,
    bool upper, bool hash)
{
    char *result = float_to_fixed(value, precision, upper, hash);

    if (result && !hash)
        trim_fixed(result);
    return result;
}

char *float_to_general(long double value, int precision, bool upper, bool hash)
{
    int exp = 0;
    int fixed_prec = 0;

    if (float_class(value) != 0)
        return float_special_string(value, upper);
    if (precision < 0)
        precision = 6;
    if (precision == 0)
        precision = 1;
    exp = get_dec_exp(float_abs(value));
    if (exp < -4 || exp >= precision)
        return format_sci(value, precision, upper, hash);
    fixed_prec = precision - (exp + 1);
    if (fixed_prec < 0)
        fixed_prec = 0;
    return format_fixed(value, fixed_prec, upper, hash);
}
