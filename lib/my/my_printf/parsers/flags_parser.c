/*
** EPITECH PROJECT, 2025
** spec_parser.c
** File description:
** flags parser function
*/

#include "../my_printf.h"
#include <stddef.h>

static bool is_flag(char c)
{
    return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

const char *get_flags(const char *format, spec_t *spec)
{
    flags_t flags = {false, false, false, false, false};
    size_t i;

    for (i = 0; is_flag(format[i]) && format[i]; i++) {
        if (format[i] == '-')
            flags.minus = true;
        if (format[i] == '+')
            flags.plus = true;
        if (format[i] == ' ')
            flags.space = true;
        if (format[i] == '#')
            flags.hash = true;
        if (format[i] == '0')
            flags.zero = true;
    }
    spec->flags = flags;
    return &format[i];
}
