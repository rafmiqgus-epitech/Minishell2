/*
** EPITECH PROJECT, 2025
** spec_parser.c
** File description:
** width parser function
*/

#include "../my_printf.h"
#include "../../my_macro_abs.h"
#include <stddef.h>
#include <stdbool.h>

static size_t star_handler(spec_t *spec, va_list args)
{
    int width_arg = va_arg(args, int);

    if (width_arg < 0) {
        if (spec->flags.minus) {
            return ABS(width_arg);
        } else {
            spec->flags.minus = true;
            return ABS(width_arg);
        }
    } else {
        return width_arg;
    }
}

const char *get_width(const char *format, spec_t *spec, va_list args)
{
    size_t size = 0;
    size_t i;

    for (i = 0; ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
        && format[i]; i++) {
        if (format[i] == '*') {
            size = star_handler(spec, args);
            i++;
            break;
        }
        size = size * 10 + (format[i] - 48);
    }
    spec->width = size;
    return &format[i];
}
