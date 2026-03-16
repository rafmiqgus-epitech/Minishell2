/*
** EPITECH PROJECT, 2025
** spec_parser.c
** File description:
** flags parser function
*/

#include "../my_printf.h"
#include <stddef.h>

static bool is_length(char c)
{
    return (c == 'h' || c == 'l' || c == 'L' ||
        c == 'j' || c == 'z' || c == 't');
}

static const char *set_length_two(const char *format,
    spec_t *spec, char x, char y)
{
    spec->length[0] = x;
    spec->length[1] = y;
    spec->length[2] = '\0';
    return &format[2];
}

static const char *set_length_one(const char *format, spec_t *spec, char x)
{
    spec->length[0] = x;
    spec->length[1] = '\0';
    spec->length[2] = '\0';
    return &format[1];
}

const char *get_length(const char *format, spec_t *spec)
{
    if (!is_length(format[0])) {
        spec->length[0] = '\0';
        spec->length[1] = '\0';
        spec->length[2] = '\0';
        return format;
    }
    if (format[0] == 'h' && format[1] == 'h')
        return set_length_two(format, spec, 'h', 'h');
    if (format[0] == 'l' && format[1] == 'l')
        return set_length_two(format, spec, 'l', 'l');
    return set_length_one(format, spec, format[0]);
}
