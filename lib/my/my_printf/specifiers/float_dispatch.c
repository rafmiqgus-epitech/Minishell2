/*
** EPITECH PROJECT, 2025
** float_dispatch.c
** File description:
** dispatcher for float specifiers
*/

#include "../my_printf.h"
#include "../../my.h"

static bool is_upper_spec(char specifier)
{
    return is_in_char(specifier, "FEGA");
}

static int get_float_precision(spec_t *spec)
{
    if (is_in_char(spec->specifier, "aA"))
        return spec->precision;
    if (is_in_char(spec->specifier, "gG")) {
        if (spec->precision < 0)
            return 6;
        if (spec->precision == 0)
            return 1;
        return spec->precision;
    }
    if (spec->precision < 0)
        return 6;
    return spec->precision;
}

char *format_float_spec(spec_t *spec, long double value)
{
    int precision = get_float_precision(spec);
    bool upper = is_upper_spec(spec->specifier);
    bool hash = spec->flags.hash;

    if (is_in_char(spec->specifier, "fF"))
        return float_to_fixed(value, precision, upper, hash);
    if (is_in_char(spec->specifier, "eE"))
        return float_to_sci(value, precision, upper, hash);
    if (is_in_char(spec->specifier, "gG"))
        return float_to_general(value, precision, upper, hash);
    if (is_in_char(spec->specifier, "aA"))
        return float_to_hex(value, precision, upper, hash);
    return NULL;
}
