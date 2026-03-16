/*
** EPITECH PROJECT, 2025
** spec_parser.c
** File description:
** spec parser function
*/

#include "../my_printf.h"

spec_t spec_parser(const char *format, va_list args)
{
    const char *start = format;
    spec_t spec = {{false, false, false, false, false}, 0, -1,
        {'\0'}, '\0', 0};

    format = get_flags(format, &spec);
    format = get_width(format, &spec, args);
    format = get_precision(format, &spec, args);
    format = get_length(format, &spec);
    get_specifier(format, &spec);
    if (spec.specifier)
        format++;
    spec.raw_size = format - start;
    return spec;
}
